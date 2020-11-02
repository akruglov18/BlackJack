project(CardLib)

add_library(CardLib Card.cpp Card.h)

target_include_directories(CardLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#add_subdirectory(test)