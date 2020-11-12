project(PlayersLib)

add_library(PlayersLib Player.cpp Dealer.cpp IPlayer.cpp HumanPlayer.cpp EventHandler.cpp
 Player.h Dealer.h IPlayer.h HumanPlayer.h EventHandler.h)

target_include_directories(PlayersLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PlayersLib HandLib CardShoeLib BetLib)

add_subdirectory(test)
