# dart_ffi_classes
Handle Dart Classes from C++

## Build `simple_cpp`

In `simple_cpp` folder:

1. Set `DART_SDK_PATH` env variable
2. Run `cmake .`
3. Run `make -j4`
4. Ensure `libsimple-cpp-lib.[so|dylib]` is built


## Build

In the root folder:

1. `dart run ffigen`
2. Run `main.dart`
