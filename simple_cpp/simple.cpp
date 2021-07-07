#include "simple.h"

#include <malloc.h>

int simple_add(int x, int y) { return x + y; }

/// initialization.

int simple_class_dart_dl_initialize(void* initialize_api_dl_data) {
  if (Dart_InitializeApiDL(initialize_api_dl_data) != 0) {
    return -1;
  }
  // Check symbols used are present
  if (Dart_NewFinalizableHandle_DL == NULL) {
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

struct _finalizable_simple_list {
  void* ptr;
};

static void simple_list_free(void* isolate_callback_data, void* peer) {
  _finalizable_simple_list* fsl =
      reinterpret_cast<_finalizable_simple_list*>(peer);
  printf("Finalising: peer %p, internal %p\n", fsl, fsl->ptr);

  assert(fsl->ptr != nullptr);
  free(fsl->ptr);

  free(fsl);
}

int simple_list_attach_finalizer(Dart_Handle handle, void* pointer,
                                 intptr_t external_allocation_size) {
  printf("Registering finaliser: %p\n", pointer);
  _finalizable_simple_list* fsl =
      (_finalizable_simple_list*)malloc(sizeof(_finalizable_simple_list));
  fsl->ptr = pointer;

  Dart_FinalizableHandle weak_handle = Dart_NewFinalizableHandle_DL(
      handle, (void*)fsl, external_allocation_size, simple_list_free);

  if (weak_handle == nullptr) {
    free(fsl);
    printf("Failed to register finaliser: %p\n", pointer);
    return -1;
  }

  printf("Successfully registered finaliser: %p\n", pointer);
  return 1;
}
