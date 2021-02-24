project(HandLib)

add_library(HandLib Hand.cpp Hand.h)

target_include_directories(HandLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(HandLib CardLib)

#target_include_directories(GameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../gtest)

#add_subdirectory(test)