set(SRC node.cc inode.cc)

add_library(node ${SRC})

format_target(node ${CMAKE_CURRENT_SOURCE_DIR} ${SRC})
