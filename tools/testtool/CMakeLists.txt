set(SRC main.cc)
add_executable(testtool main.cc)
format_target(testtool ${CMAKE_CURRENT_SOURCE_DIR} ${SRC})
