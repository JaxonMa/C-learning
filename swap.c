#include <stdio.h>

void swap(int* x, int* y) {
  int middle = *x;
  printf("The address of x, middle, y: %p, %p, %p\n", x, &middle, y);
  *x = *y;
  *y = middle;
}

void swap_without_ptr(int x, int y) {
  int middle = y;
  printf("The address of x, middle, y: %p, %p, %p\n", &x, &middle, &y);
  y = x;
  x = middle;
}

int main() {
  int x = 1;
  int y = 2;
  // swap(&x, &y);
  swap_without_ptr(x, y);

  printf("x: %d, y: %d", x, y);

  /* The exapmle above tells us that, though swap_without_ptr() can work in the code block, it cannot
   * change the value of variables defined in other functions.
   */

  return 0;
}