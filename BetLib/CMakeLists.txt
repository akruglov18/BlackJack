project(BetLib)

add_library(BetLib Bet.cpp Bet.h)

target_include_directories(BetLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#target_link_libraries(BetLib)

#target_include_directories(GameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest)

#add_subdirectory(test)