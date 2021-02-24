#include "Table.h"
#define WIN32_LEAN_AND_MEAN
#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <Utils.h>
#include <iostream>
#include "Players/TcpPlayerServer.h"

Table::Table(int minBet, int maxBet)
{
    _minimumBet = minBet;
    _dealer = std::make_shared<Dealer>(_shoe, minBet, maxBet);
//    _logging = false;
}

void Table::AddPlayer(std::shared_ptr<IPlayer> player, bool assignId)
{
    if (assignId)
    {
        player->SetId(GenerateId());
    }
    _dealer->AddPlayer(player);
    _players.push_back(player);
}

void Table::RemovePlayer(std::shared_ptr<IPlayer> player)
{

    _dealer->RemovePlayer(player);
    _players.erase(std::find(_players.begin(), _players.end(), player));
}

void Table::PlayGame(int roundLimit)
{
    int currentRound = 0;
    while (_players.size() > 0 && currentRound++ < roundLimit)
    {
        std::cout << "Round " << currentRound << std::endl;
        KickBeggars();
        _dealer->PlayRound();
        KickBeggars();
    }
}

void Table::KickBeggars()
{
    for (int i = _players.size()-1; i >= 0; i--)
    {
        if (_players.at(i)->GetBank() < _minimumBet)
        {
            RemovePlayer(_players.at(i));
        }
    }
}

std::string Table::GenerateId()
{
    return std::to_string(_nextId++);
}

void Table::AcceptTcpPlayers(int playerCount, u_short port)
{
    SOCKET listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener == INVALID_SOCKET)
    {
        std::cerr << "socket error" << std::endl;
        exit(153);
    }
    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(listener, (sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cerr << "can't bind listener socket" << std::endl;
        exit(154);
    }

    listen(listener, SOMAXCONN);

    for (int i = 0; i < playerCount; i++)
    {
        sockaddr_in client_addr;
        int addrSize = sizeof(client_addr);
        _socket = accept(listener, (sockaddr*) &client_addr, &addrSize);
        std::cout << "client connected" << std::endl;

        std::string authMessage = ReceiveMsg();
        nlohmann::json j = nlohmann::json::parse(authMessage);
        if (j["command"] == "Authorize" && !j["data"]["name"].empty())
        {
            std::shared_ptr<TcpPlayerServer> player = std::make_shared<TcpPlayerServer>(_socket);//new TcpPlayerServer(_socket);
            player->_logging = _logging;
            player->SetName(j["data"]["name"]);
            player->SetId(GenerateId());

            nlohmann::json response;
            response["command"] = "OK";
            response["data"]["name"] = player->GetName();
            response["data"]["id"] = player->GetId();
            response["data"]["Bank"] = player->GetBank();
            SendMsg(response.dump());
            AddPlayer(player, false);
        }
        else
        {
            nlohmann::json response;
            response["command"] = "Error";
            if (j["command"] != "Authorize")
            {
                response["data"]["description"] = "Unknown command, Authorize expected";
            }
            else if (j["data"]["name"].empty())
            {
                response["data"]["description"] = "Name cannot be empty";
            }
            else
            {
                response["data"]["description"] = "Unknown error";
            }
            std::string message = response.dump();
            SendMsg(message);
        }
    }
    closesocket(listener);
}
