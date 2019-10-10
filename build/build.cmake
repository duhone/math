
include_directories("${CMAKE_CURRENT_LIST_DIR}/../inc")

###############################################
#library
###############################################
set(MATH_PUBLIC_HDRS
    ${CMAKE_CURRENT_LIST_DIR}/../inc/math/Color.h
    ${CMAKE_CURRENT_LIST_DIR}/../inc/math/Ray.h
    ${CMAKE_CURRENT_LIST_DIR}/../inc/math/Rect.h
    ${CMAKE_CURRENT_LIST_DIR}/../inc/math/Vector.h
    ${CMAKE_CURRENT_LIST_DIR}/../inc/math/Types.h
)

set(MATH_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/../src/Color.cpp
)

set(MATH_BUILD
    ${CMAKE_CURRENT_LIST_DIR}/../build/build.cmake
)

add_library(math OBJECT  ${MATH_PUBLIC_HDRS} ${MATH_SRCS} ${MATH_BUILD})
						
source_group("Public Headers" FILES ${MATH_PUBLIC_HDRS})
source_group("Source" FILES ${MATH_SRCS})
source_group("Build" FILES ${MATH_BUILD})
				
if(IncludeTests)
	###############################################
	#unit tests
	###############################################
set(MATH_TEST_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/../tests/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../tests/Vector.cpp
)
	
	add_executable(math_tests $<TARGET_OBJECTS:core>
						$<TARGET_OBJECTS:math>
						$<TARGET_OBJECTS:fmt>
						${MATH_TEST_SRCS})
						
	source_group("Source" FILES ${MATH_TEST_SRCS})
						
	set_property(TARGET math_tests APPEND PROPERTY FOLDER tests)
endif()
