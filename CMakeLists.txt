cmake_minimum_required(VERSION 3.8)
project(CS236_Lab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lexer.cpp Lexer.h Token.cpp Token.h InputChars.cpp InputChars.h Parser.cpp Parser.h SchemeClass.cpp SchemeClass.h FactClass.cpp FactClass.h RuleClass.cpp RuleClass.h QueryClass.cpp QueryClass.h)
add_executable(Lab main.cpp ${SOURCE_FILES})
add_executable(testing ${SOURCE_FILES} testMain.cpp)