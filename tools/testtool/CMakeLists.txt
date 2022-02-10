set(SRC main.cc)

add_executable(testtool main.cc)
target_link_libraries(testtool tree node)

format_target(testtool ${CMAKE_CURRENT_SOURCE_DIR} ${SRC})
