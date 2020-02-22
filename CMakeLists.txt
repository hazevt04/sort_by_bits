cmake_minimum_required( VERSION 2.8.0 )

project( sort_by_bits )

include_directories( "include" )

add_definitions( -std=c++11 )

set(EXEC_NAME "sort_by_bits")

set(SRCS
   "src/sort_by_bits.cpp"
   "src/utils.cpp"
   "src/main.cpp"
   )

option(DO_UNIT_TEST "Unit test option" OFF)

if(DO_UNIT_TEST)
   add_definitions(-DDO_UNIT_TEST)
endif()

add_executable( "${EXEC_NAME}" "${SRCS}" )
#target_link_libraries( "${EXEC_NAME}" m gsl gslcblas)


