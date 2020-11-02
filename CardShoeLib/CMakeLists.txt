project(CardShoeLib)

add_library(CardShoeLib CardShoe.cpp CardShoe.h)

target_include_directories(CardShoeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(CardShoeLib CardLib)

#add_subdirectory(test)