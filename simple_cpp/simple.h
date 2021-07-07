#ifndef SIMPLE_H_
#define SIMPLE_H_

#include <stddef.h>

#include "include/dart_api_dl.h"

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

typedef struct simple_list_t {
  int* values;
  int size;
} simple_list_t;

// Creates a list of `size`, every element have `value`
simple_list_t* simple_list_create(int size, int value);

// Adds all the numbers in a simple list and returns the sum.
int simple_list_sum(simple_list_t* list);

// Attach a finalizer for pointer to object, such that `finalizer(pointer)` will
// be called when `object` is collected by the Dart garbage collector.
//
// The external_allocation_size is used by the Dart garbage collector as a hint
// about the size of the external allocation.
//
// Returns 1 on success.
int simple_list_attach_finalizer(Dart_Handle object, void* pointer,
                                 intptr_t external_allocation_size);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // SIMPLE_H_
