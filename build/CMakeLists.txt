cmake_minimum_required (VERSION 2.6)

###############################################
#options
###############################################
option(IncludeTests "Include Unit Tests" ON)

project (math)
include_directories("${PROJECT_SOURCE_DIR}/../inc")

###############################################
#library
###############################################
add_library(math OBJECT "${PROJECT_SOURCE_DIR}/../inc/Types.h"
						"${PROJECT_SOURCE_DIR}/../inc/Ray.h"
						"${PROJECT_SOURCE_DIR}/../inc/Rect.h"
						"${PROJECT_SOURCE_DIR}/../inc/Color.h"
						"${PROJECT_SOURCE_DIR}/../inc/Vector.h"
						"${PROJECT_SOURCE_DIR}/../src/Color.cpp")
						
				
if(IncludeTests)
	###############################################
	#unit tests
	###############################################
	add_executable(tests "${PROJECT_SOURCE_DIR}/../tests/Vector.cpp"
						"${PROJECT_SOURCE_DIR}/../tests/main.cpp")
endif()