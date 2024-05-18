cmake_minimum_required(VERSION 3.29)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)

# set the project name
project(prett LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_program(CLANG_TIDY NAMES clang-tidy)
if(CLANG_TIDY)
	set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})
endif()

add_executable(prett src/main.cpp src/color.cpp)
target_include_directories(
	prett
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
target_compile_options(
	prett
	PRIVATE
	-Werror
	-Wall
	-Wextra
	-Wconversion
	-Wsign-conversion
)
