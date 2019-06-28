cmake_minimum_required(VERSION 3.8)
project(sparse_matrix_juliobonifaz)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .vscode/launch.json
        .vscode/settings.json
        .vscode/tasks.json
        mocker/mocker.cpp
        mocker/mocker.h
        tester/tester.cpp
        tester/tester.h
        .gitignore
        LICENSE
        main.cpp
        matrix.h
        node.h)

add_executable(sparse_matrix_juliobonifaz ${SOURCE_FILES})