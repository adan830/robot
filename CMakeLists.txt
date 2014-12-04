CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(robot CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CXX_FLAGS
  -g
  -D__SGROBOT__
  # -DMUDUO_STD_STRING
  -DCHECK_PTHREAD_RETURN_VALUE
  -D_FILE_OFFSET_BITS=64
  -Wall
  -Wextra
  -Werror
  -Wconversion
  -Wno-unused-parameter
  -Wold-style-cast
  -Woverloaded-virtual
  -Wpointer-arith
  -Wshadow
  -Wwrite-strings
  -march=native
  -pthread
  -lreadline
  -lncurses
  -MMD
  -std=c++11
  -rdynamic
  )

if(CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
endif()
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(PROJECT_BINARY_DIR ${BINARY_DIR})
set(CMAKE_CURRENT_SOURCE_DIR ${SOURCE_DIR})
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -D__NOTRANS__")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG -D__NOTRANS__")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

INCLUDE_DIRECTORIES(${SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${SOURCE_DIR}/src/common)
LINK_DIRECTORIES(${SOURCE_DIR}/lib)

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

ADD_SUBDIRECTORY(src)

