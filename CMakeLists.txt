cmake_minimum_required(VERSION 3.7)
project(compiler_construction)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp Lexer.cpp Lexer.h Token.cpp Token.h Parser.cpp Parser.h lib/AST_Node.cpp lib/AST_Node.h lib/Tree.cpp lib/Tree.h)

add_executable(compiler_construction ${SOURCE_FILES})