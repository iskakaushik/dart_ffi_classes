#include "simple.h"

#include <malloc.h>

/// initialization.

int simple_class_dart_dl_initialize(void* initialize_api_dl_data) {
  if (Dart_InitializeApiDL(initialize_api_dl_data) != 0) {
    printf("Failed to initialise Dart VM API\n");
    return -1;
  }
  // Check symbols used are present
  if (Dart_NewFinalizableHandle_DL == NULL) {
    printf("Unable to find Dart API finalizer symbols.\n");
    return -1;
  }
  return 1;
}

/// Simple list methods
simple_list_t* simple_list_create(int size, int value) {
  simple_list_t* ret = (simple_list_t*)malloc(sizeof(simple_list_t));
  ret->size = size;
  ret->values = (int*)malloc(size * sizeof(int));
  printf("Created simple list: %p of size: %d\n", ret, size);
  for (int i = 0; i < size; i++) {
    ret->values[i] = value;
  }
  return ret;
}

int simple_list_sum(simple_list_t* list) {
  if (!list) {
    return 0;
  }
  int res = 0;
  for (int i = 0; i < list->size; i++) {
    res += list->values[i];
  }

  return res;
}

static void simple_list_free(void* isolate_callback_data, void* peer) {
  assert(peer != nullptr);

  printf("Finalising: peer %p\n", peer);
  simple_list_t* l = reinterpret_cast<simple_list_t*>(peer);
  free(l->values);
  free(l);
}

int simple_list_attach_finalizer(Dart_Handle handle, void* pointer,
                                 intptr_t external_allocation_size) {
  printf("Registering finaliser: %p call(%p)\n", pointer, simple_list_free);
  Dart_FinalizableHandle weak_handle = Dart_NewFinalizableHandle_DL(
      handle, pointer, external_allocation_size, simple_list_free);

  if (weak_handle == nullptr) {
    printf("Failed to register finaliser: %p\n", pointer);
    return -1;
  }

  printf("Successfully registered finaliser: %p\n", pointer);
  return 1;
}
