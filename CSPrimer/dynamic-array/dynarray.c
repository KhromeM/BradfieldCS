#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

typedef struct DA {
  void** arr;
  int cap;
  int size;
} DA;

DA* DA_new (void) {
  DA* da = (DA*) malloc(sizeof(DA));
  void** arr = calloc((size_t) STARTING_CAPACITY ,sizeof(void*));
  da->arr = arr;
  da->cap = STARTING_CAPACITY;
  da->size = 0;
  return da;
}

int DA_size(DA *da) {
  return da->size;
}

void DA_push (DA* da, void* x) {
  if (da->cap == da->size) {
    da->cap *= 2;
    da->arr = realloc(da->arr,sizeof(void*)*da->cap);
    printf("New Capacity: %d\n", da->cap);
  } 
  da->arr[da->size++] = x;
}

void* DA_pop(DA *da) {
  if (da->size){
    int index = --(da->size);
    void* ans = da->arr[index];
    da->arr[index] = 0;
    return ans;
  }
  return NULL;
}

void DA_set(DA *da, void *x, int i) {
  if (i < da->cap && i > -1)
    da->arr[i] = x;
}

void* DA_get(DA *da, int i) {
    if (i < da->cap && i > -1)
      return da->arr[i];
    return NULL;
}

void DA_free(DA *da) {
  free(da->arr);
  free(da);
}

int main() {
    DA* da = DA_new();

    assert(DA_size(da) == 0);

    // basic push and pop test
    int x = 5;
    float y = 12.4;
    DA_push(da, &x);
    DA_push(da, &y);
    assert(DA_size(da) == 2);

    assert(DA_pop(da) == &y);
    assert(DA_size(da) == 1);

    assert(DA_pop(da) == &x);
    assert(DA_size(da) == 0);
    assert(DA_pop(da) == NULL);

    // basic set/get test
    DA_push(da, &x);
    DA_set(da, &y, 0);
    assert(DA_get(da, 0) == &y);
    DA_pop(da);
    assert(DA_size(da) == 0);

    // expansion test
    DA *da2 = DA_new(); // use another DA to show it doesn't get overriden
    DA_push(da2, &x);
    int i, n = 100000 * STARTING_CAPACITY, arr[n];
    for (i = 0; i < n; i++) {
      arr[i] = i;
      DA_push(da, &arr[i]);
    }
    assert(DA_size(da) == n);
    for (i = 0; i < n; i++) {
      assert(DA_get(da, i) == &arr[i]);
    }
    for (; n; n--)
      DA_pop(da);
    assert(DA_size(da) == 0);
    assert(DA_pop(da2) == &x); // this will fail if da doesn't expand

    DA_free(da);
    DA_free(da2);
    printf("OK\n");
}
