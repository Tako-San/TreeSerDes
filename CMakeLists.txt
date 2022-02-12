cmake_minimum_required(VERSION 3.16)
project(SerDes)

# Include formatter
include(cmake/clang_format.cmake)

# Build documentation with -DBUILD_DOC
option(BUILD_DOC "Build documentation" OFF)
add_subdirectory(docs)

# Include compiler flags
include(cmake/comp_flags.cmake)

# Prepare project libraries
add_subdirectory(lib)
message(STATUS "Collected libs: ${LIBLIST}")

foreach(LIB ${LIBLIST})
  target_include_directories(${LIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  target_include_directories(${LIB} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIB})

  apply_compiler_flags(${LIB})
  target_compile_features(${LIB} PRIVATE cxx_std_17)
endforeach()


# Prepare project tools
add_subdirectory(tools)
message(STATUS "Collected tools: ${TOOLLIST}")

foreach(TOOL ${TOOLLIST})
  target_include_directories(${TOOL} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

  apply_compiler_flags(${TOOL})
  target_link_libraries(${TOOL} ${LIBLIST})
  target_compile_features(${TOOL} PRIVATE cxx_std_17)

  set_target_properties(${TOOL}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
endforeach()


# Lookup for gtest
find_package(GTest REQUIRED)

add_subdirectory(test)
message(STATUS "Collected tests: ${TESTLIST}")

foreach(TEST ${TESTLIST})
  target_include_directories(${TEST} PRIVATE ${GTEST_INCLUDE_DIRS})
  target_link_libraries(${TEST} PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)

  target_compile_features(${TEST} PRIVATE cxx_std_20)
  target_include_directories(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  set_target_properties(${TEST}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
endforeach()
