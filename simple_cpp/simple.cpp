#include "simple.h"

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

int simple_add(int x, int y) { return x + y; }
