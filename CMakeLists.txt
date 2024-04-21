cmake_minimum_required(VERSION 3.5.0)
project(MyDatabase VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

set(HEADERS headers/inputbuffer.h
            headers/util.h
            headers/error.h)
set(SOURCES sources/inputbuffer.c
            sources/util.c
            sources/error.c)

include_directories(headers)
add_executable(MyDatabase main.c ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
