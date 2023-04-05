#include <assert.h>
#include <stdio.h>

extern int fib(int n);
extern int fun(int x);

int main(void) {
  printf("10: %d 11: %d 20: %d\n", fun(10), fun(11), fun(20));

  assert(fib(0) == 0);
  assert(fib(1) == 1);
  assert(fib(2) == 1);
  assert(fib(3) == 2);
  printf("10: %d 11: %d 20: %d\n", fib(10), fib(11), fib(20));
  assert(fib(10) == 55);
  assert(fib(12) == 144);
  printf("OK\n");
}
