cmake_minimum_required(VERSION 3.12)
project(BlackJack)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


add_executable(BlackJack main.cpp)

add_subdirectory(gtest)
add_subdirectory(CardLib)
add_subdirectory(CardShoeLib)
add_subdirectory(HandLib)
add_subdirectory(PlayersLib)
add_subdirectory(GameLib)



target_link_libraries(BlackJack PlayersLib GameLib)



