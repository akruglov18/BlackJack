project(Players_test)

add_executable(Players_test test_main.cpp test_dealer.cpp test_player.cpp)

target_link_libraries(Players_test PlayersLib gtest)



