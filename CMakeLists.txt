cmake_minimum_required(VERSION 3.10)

#set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}" )

# set the project name and version
project(Task2 VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



configure_file(cmake/config.h.in src/config.h)

add_compile_options(-Werror -Wall -Wextra)
# -Werror -Wall -Wextra -pedantic -std=c++17

## Append compiler flag to silence compiler warning for GNU extension
if (CMAKE_COMPILER_IS_GNUCXX OR (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang"))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")
endif()

# add the executable
add_executable(${PROJECT_NAME} src/main.cpp)



include(CTest) #adds option BUILD_TESTING (default ON)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()