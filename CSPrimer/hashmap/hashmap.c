#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KEY_SIZE 1700
#define STARTING_BUCKETS 17
typedef struct Node Node;
struct Node{
  char* key;
  void* value;
  Node* next;
};

typedef struct Hashmap {
  int capacity;
  Node** arr;
} Hashmap;

Hashmap* Hashmap_new(){
  Hashmap* h = malloc(sizeof(Hashmap));
  h->capacity = STARTING_BUCKETS;
  h->arr = malloc(h->capacity * sizeof(Node*));
  for (int i=0; i< h->capacity; i++){
    h->arr[i] = NULL;
  }
  return h;
}

int hash(Hashmap* h,char* s){
  int ans = 0, i = 0;
  while (s[i] != '\0') {
    ans += (int) s[i] * (++i);
  }
  return ans % h->capacity;
}  

Node* h_get(Hashmap* h,char* key){
  int index = hash(h,key);
  Node* node = h->arr[index];
  while (node != NULL) {
    if (!strcmp(node->key, key)){
      return node;
    }
    node = node->next;
  }
  return NULL;
}
void* Hashmap_get(Hashmap* h, char* key){
  Node* node = h_get(h,key);
  if (node == NULL) return NULL;
  return node->value;
}

void Hashmap_set(Hashmap* h,char* key, void* value){
  int index = hash(h,key);
  Node* node = h_get(h,key);
  if (node == NULL){
      Node* n = malloc(sizeof(Node));
      n->key = key;
      n->value = value;
      n->next = NULL;
      h->arr[index] = n;
  } else {
    node->value = value;
  }
}
void Hashmap_delete(Hashmap* h, char* key){
  Hashmap_set(h,key,NULL);
}
void Hashmap_free(Hashmap* h){}

int main() {
  Hashmap *h = Hashmap_new();

  // basic get/set functionality
   int a = 5;
   float b = 7.2;
   Hashmap_set(h, "item a", &a);
   Hashmap_set(h, "item b", &b);
   assert(Hashmap_get(h, "item a") == &a);
   assert(Hashmap_get(h, "item b") == &b);

  // // using the same key should override the previous value
   int c = 20;
   Hashmap_set(h, "item a", &c);
   assert(Hashmap_get(h, "item a") == &c);

   // basic delete functionality
   Hashmap_delete(h, "item a");
   assert(Hashmap_get(h, "item a") == NULL);

   // handle collisions correctly
   // note: this doesn't necessarily test expansion
   int i, n = STARTING_BUCKETS * 10, ns[n];
   char key[MAX_KEY_SIZE];
   for (i = 0; i < n; i++) {
     ns[i] = i;
     printf("item %d", i);
     Hashmap_set(h, key, &ns[i]);
   }
   for (i = 0; i < n; i++) {
     sprintf(key, "item %d", i);
     assert(Hashmap_get(h, key) == &ns[i]);
   }

   Hashmap_free(h);
   /*
      stretch goals:
      - expand the underlying array if we start to get a lot of collisions
      - support non-string keys
      - try different hash functions
      - switch from chaining to open addressing
      - use a sophisticated rehashing scheme to avoid clustered collisions
      - implement some features from Python dicts, such as reducing space use,
      maintaing key ordering etc. see https://www.youtube.com/watch?v=npw4s1QTmPg
      for ideas
      */

   printf("ok\n");
}
