import 'dart:ffi';
import 'dart:io';

import 'package:path/path.dart' as p;

import 'generated_bindings.dart';

String _getDylibPath() {
  final rootDir = Directory.current.absolute.path;
  var path = p.join(rootDir, 'simple_cpp');
  if (Platform.isMacOS) {
    path = p.join(path, 'libsimple-cpp-lib.dylib');
  } else {
    path = p.join(path, 'libsimple-cpp-lib.so');
  }
  return path;
}

void main() {
  print('Hello, World!');
  final int a = 50;
  final int b = 43;

  final dylib = DynamicLibrary.open(_getDylibPath());
  final int sum = NativeLibrary(dylib).simple_add(a, b);
  print('Sum of $a and $b is $sum.');
}
