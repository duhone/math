cmake_minimum_required (VERSION 2.6)

###############################################
#options
###############################################
option(IncludeTests "Include Unit Tests" ON)
set(GtestInclude "" CACHE STRING "GTest include folder")
set(GtestDebug "" CACHE STRING "GTest debug library folder")
set(GtestRelease "" CACHE STRING "GTest release folder")

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
	#gtest dependency
	#needs to be built as static library, with shared crt
	###############################################		
	add_library( gtest STATIC IMPORTED )
	set_target_properties( gtest PROPERTIES IMPORTED_LOCATION_DEBUG ${GtestDebug}/gtest.lib )
	set_target_properties( gtest PROPERTIES IMPORTED_LOCATION_RELEASE ${GtestRelease}/gtest.lib )
	set_target_properties( gtest PROPERTIES IMPORTED_LOCATION_RELWITHDEBINFO ${GtestRelease}/gtest.lib )

	###############################################
	#unit tests
	###############################################
	add_executable(tests "${PROJECT_SOURCE_DIR}/../tests/Vector.cpp"
						"${PROJECT_SOURCE_DIR}/../tests/main.cpp")
	target_include_directories(tests PRIVATE "${GtestInclude}")
	target_link_libraries(tests gtest)
endif()