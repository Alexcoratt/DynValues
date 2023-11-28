cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DynValues)

file(GLOB SOURCES "src/*/sources/*.cpp")

set(LIB_NAME ${PROJECT_NAME}_lib)
add_library(${LIB_NAME} STATIC ${SOURCES})
target_include_directories(
	${LIB_NAME}

	PUBLIC src/values/headers
	PUBLIC src/exceptions
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_NAME})
