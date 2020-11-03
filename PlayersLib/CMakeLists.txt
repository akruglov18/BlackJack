project(PlayersLib)

add_library(PlayersLib Player.cpp Dealer.cpp Players.cpp HumanPlayer.cpp Player.h Dealer.h Players.h HumanPlayer.h)

target_include_directories(PlayersLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(PlayersLib HandLib CardShoeLib)

add_subdirectory(test)
