set(TESTLIST)

foreach(TEST ${TESTLIST})
  add_subdirectory(${TEST})
endforeach()

set(TESTLIST "${TESTLIST}" PARENT_SCOPE)
