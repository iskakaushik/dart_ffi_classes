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

final dylib = DynamicLibrary.open(_getDylibPath());
final simpleCPP = SimpleCPP(dylib);

void _attachFinalizer(Pointer<simple_list_t> ptr, int size) {
  final ret = simpleCPP.simple_list_attach_finalizer(ptr, ptr.cast(), size);
  if (ret != 1) {
    throw Exception("Unable to attach finalizer to simple list ($size).");
  }
}

class SimpleListWrapper {
  factory SimpleListWrapper.create(int size, int value) {
    final ptr = simpleCPP.simple_list_create(size, value);
    if (ptr.address == 0) {
      throw Exception('Unable to intialize simple list');
    }
    print('[dart] Initialized simple list: ${ptr.address.toRadixString(16)}');
    _attachFinalizer(ptr, size);
    return SimpleListWrapper._(ptr);
  }

  int sum() {
    return simpleCPP.simple_list_sum(ptr);
  }

  SimpleListWrapper._(this.ptr);

  final Pointer<simple_list_t> ptr;
}

void main() {
  final initializer = simpleCPP.simple_class_dart_dl_initialize;
  if (initializer(NativeApi.initializeApiDLData) != 1) {
    throw UnsupportedError('Unable to initialize simple_cpp');
  } else {
    print('Successfully initialize Dart dl');
  }

  SimpleListWrapper simpleList = SimpleListWrapper.create(100, 5);
  print('Sum = ${simpleList.sum()}');
}
