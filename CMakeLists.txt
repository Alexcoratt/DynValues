cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DynValues CXX)

file(GLOB SOURCES "src/*/sources/*.cpp")

if (NOT DEFINED DYN_VALUES_BUILD_TESTS)
	set(DYN_VALUES_BUILD_TESTS OFF)
endif()

set(LIB_NAME ${PROJECT_NAME}_lib)
add_library(${LIB_NAME} STATIC ${SOURCES})
target_include_directories(
	${LIB_NAME}

	PUBLIC src/values/headers
	PUBLIC src/exceptions
)

if (DYN_VALUES_BUILD_TESTS)
	link_libraries(${LIB_NAME})
	add_executable(test1 src/tests/test1.cpp)
endif()
