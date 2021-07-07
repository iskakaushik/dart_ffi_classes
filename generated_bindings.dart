// AUTO GENERATED FILE, DO NOT EDIT.
//
// Generated by `package:ffigen`.
import 'dart:ffi' as ffi;

/// Bindings to `simple_cpp`.
class SimpleCPP {
  /// Holds the symbol lookup function.
  final ffi.Pointer<T> Function<T extends ffi.NativeType>(String symbolName)
      _lookup;

  /// The symbols are looked up in [dynamicLibrary].
  SimpleCPP(ffi.DynamicLibrary dynamicLibrary)
      : _lookup = dynamicLibrary.lookup;

  /// The symbols are looked up with [lookup].
  SimpleCPP.fromLookup(
      ffi.Pointer<T> Function<T extends ffi.NativeType>(String symbolName)
          lookup)
      : _lookup = lookup;

  /// // CLASSES
  int simple_class_dart_dl_initialize(
    ffi.Pointer<ffi.Void> initialize_api_dl_data,
  ) {
    return _simple_class_dart_dl_initialize(
      initialize_api_dl_data,
    );
  }

  late final _simple_class_dart_dl_initialize_ptr =
      _lookup<ffi.NativeFunction<_c_simple_class_dart_dl_initialize>>(
          'simple_class_dart_dl_initialize');
  late final _dart_simple_class_dart_dl_initialize
      _simple_class_dart_dl_initialize = _simple_class_dart_dl_initialize_ptr
          .asFunction<_dart_simple_class_dart_dl_initialize>();

  ffi.Pointer<simple_list_t> simple_list_create(
    int size,
    int value,
  ) {
    return _simple_list_create(
      size,
      value,
    );
  }

  late final _simple_list_create_ptr =
      _lookup<ffi.NativeFunction<_c_simple_list_create>>('simple_list_create');
  late final _dart_simple_list_create _simple_list_create =
      _simple_list_create_ptr.asFunction<_dart_simple_list_create>();

  int simple_list_sum(
    ffi.Pointer<simple_list_t> list,
  ) {
    return _simple_list_sum(
      list,
    );
  }

  late final _simple_list_sum_ptr =
      _lookup<ffi.NativeFunction<_c_simple_list_sum>>('simple_list_sum');
  late final _dart_simple_list_sum _simple_list_sum =
      _simple_list_sum_ptr.asFunction<_dart_simple_list_sum>();

  int simple_list_attach_finalizer(
    Object object,
    ffi.Pointer<ffi.Void> pointer,
    int external_allocation_size,
  ) {
    return _simple_list_attach_finalizer(
      object,
      pointer,
      external_allocation_size,
    );
  }

  late final _simple_list_attach_finalizer_ptr =
      _lookup<ffi.NativeFunction<_c_simple_list_attach_finalizer>>(
          'simple_list_attach_finalizer');
  late final _dart_simple_list_attach_finalizer _simple_list_attach_finalizer =
      _simple_list_attach_finalizer_ptr
          .asFunction<_dart_simple_list_attach_finalizer>();
}

class simple_list_t extends ffi.Struct {
  external ffi.Pointer<ffi.Int32> values;

  @ffi.Int32()
  external int size;
}

typedef _c_simple_class_dart_dl_initialize = ffi.Int32 Function(
  ffi.Pointer<ffi.Void> initialize_api_dl_data,
);

typedef _dart_simple_class_dart_dl_initialize = int Function(
  ffi.Pointer<ffi.Void> initialize_api_dl_data,
);

typedef _c_simple_list_create = ffi.Pointer<simple_list_t> Function(
  ffi.Int32 size,
  ffi.Int32 value,
);

typedef _dart_simple_list_create = ffi.Pointer<simple_list_t> Function(
  int size,
  int value,
);

typedef _c_simple_list_sum = ffi.Int32 Function(
  ffi.Pointer<simple_list_t> list,
);

typedef _dart_simple_list_sum = int Function(
  ffi.Pointer<simple_list_t> list,
);

typedef _c_simple_list_attach_finalizer = ffi.Int32 Function(
  ffi.Handle object,
  ffi.Pointer<ffi.Void> pointer,
  ffi.IntPtr external_allocation_size,
);

typedef _dart_simple_list_attach_finalizer = int Function(
  Object object,
  ffi.Pointer<ffi.Void> pointer,
  int external_allocation_size,
);
