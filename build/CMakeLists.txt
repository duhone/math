cmake_minimum_required (VERSION 2.6)

###############################################
#options
###############################################
option(IncludeTests "Include Unit Tests" ON)

project (math)

add_subdirectory("${PROJECT_SOURCE_DIR}/../../Core/build" "${PROJECT_SOURCE_DIR}/../../Core_build")

include_directories("${PROJECT_SOURCE_DIR}/../inc")

###############################################
#library
###############################################
file(GLOB_RECURSE math_inc "${PROJECT_SOURCE_DIR}/../inc/*.h")
file(GLOB_RECURSE math_src1 "${PROJECT_SOURCE_DIR}/../src/*.h")
file(GLOB_RECURSE math_src2 "${PROJECT_SOURCE_DIR}/../src/*.cpp")
list(APPEND math_src ${math_inc})
list(APPEND math_src ${math_src1})
list(APPEND math_src ${math_src2})

add_library(math OBJECT ${math_src})
						
set_property(TARGET math APPEND PROPERTY COMPILE_FLAGS "-WX -W4")
				
if(IncludeTests)
	###############################################
	#unit tests
	###############################################
	file(GLOB_RECURSE math_test_inc "${PROJECT_SOURCE_DIR}/../tests/*.h")
	file(GLOB_RECURSE math_test_src1 "${PROJECT_SOURCE_DIR}/../tests/*.cpp")
	list(APPEND math_test_src ${math_test_inc})
	list(APPEND math_test_src ${math_test_src1})
	
	add_executable(math_tests $<TARGET_OBJECTS:core>
						$<TARGET_OBJECTS:math>
						${math_test_src})
						
	set_property(TARGET math_tests APPEND PROPERTY COMPILE_FLAGS "-WX -W4")
endif()