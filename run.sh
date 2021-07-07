#!/bin/bash
pushd simple_cpp
cmake .
make -j4
popd
dart run ffigen --compiler-opts -Ithird_party/dart-sdk/src/runtime/
dart run main.dart
