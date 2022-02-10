set(SRC tree.cc)

add_library(tree ${SRC})

format_target(tree ${CMAKE_CURRENT_SOURCE_DIR} ${SRC})
