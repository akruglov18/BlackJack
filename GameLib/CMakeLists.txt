project(GameLib)

add_library(GameLib Game.cpp Game.h)

target_include_directories(GameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(GameLib CardLib PlayersLib)

#target_include_directories(GameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest)

#add_subdirectory(test)
