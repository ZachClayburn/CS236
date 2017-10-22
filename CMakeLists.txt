cmake_minimum_required(VERSION 3.8)
project(CS236_Lab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lexer.cpp Lexer.h Token.cpp Token.h InputChars.cpp InputChars.h Parser.cpp Parser.h Schemes.cpp
        Schemes.h Facts.cpp Facts.h Rules.cpp Rules.h Queries.cpp Queries.h Scheme.cpp Scheme.h ID.cpp ID.h Fact.cpp Fact.h String.cpp String.h Rule.cpp Rule.h HeadPredicate.cpp HeadPredicate.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Opperator.cpp Opperator.h Expression.cpp Expression.h Table.cpp Table.h Header.cpp Header.h Row.cpp Row.h)
add_executable(Lab main.cpp ${SOURCE_FILES})
add_executable(testing ${SOURCE_FILES} testMain.cpp)