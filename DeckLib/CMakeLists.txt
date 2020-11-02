project(DeckLib)

add_library(DeckLib Deck.cpp Deck.h)

target_include_directories(DeckLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DeckLib CardLib)

#add_subdirectory(test)