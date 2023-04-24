cmake_minimum_required(VERSION 3.13)

set(PROJECT_ID program_organiation)

set(SOURCE_FILES
        src/mylib.c
        )

set(SOURCES_FILES_TESTS
        test/test_mylib.cpp
        )

include(../SetCommonConfig.cmake)