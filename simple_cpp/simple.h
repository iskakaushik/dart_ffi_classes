#ifndef SIMPLE_H_
#define SIMPLE_H_

#include <stddef.h>

#include "dart_api_dl.h"

#ifdef __cplusplus
extern "C" {
#endif

// Super simple add function.
int simple_add(int x, int y);

///// CLASSES

// Initialize Dart API with dynamic linking.
//
// Must be called with `NativeApi.initializeApiDLData` from `dart:ffi`, before
// using other functions.
//
// Returns 1 on success.
int simple_class_dart_dl_initialize(void* initialize_api_dl_data);

// Creates a list of `size`, every element have `value`
void simple_list_create(int size, int value);

// Function pointer for de-allocation of a pointer, when attaching a finalizer
// using simple_list_attach_finalizer.
typedef void (*simple_list_finalizer_t)(void*);

// Attach a finalizer for pointer to object, such that `finalizer(pointer)` will
// be called when `object` is collected by the Dart garbage collector.
//
// The external_allocation_size is used by the Dart garbage collector as a hint
// about the size of the external allocation.
//
// Returns 1 on success.
void simple_list_attach_finalizer(Dart_Handle object, void* pointer,
                                  simple_list_finalizer_t finalizer,
                                  intptr_t external_allocation_size);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // SIMPLE_H_
