CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

PROJECT (SIMPLE-CPP)

INCLUDE_DIRECTORIES(.)

SET (simple-cpp-sources
  simple.h
  simple.cpp
)

ADD_LIBRARY (simple-cpp-lib SHARED ${simple-cpp-sources})
