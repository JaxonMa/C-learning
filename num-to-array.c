#include <stdio.h>
#include <math.h>

int main() {
  int n = 12345;
  int array[5];

  for (int i = 0; i < 5; i++) {
    array[i] = n % 10;
    n /= 10;
  }

  printf("The digits in reverse order are: ");
  for (int i = 4; i >= 0; i--) {
    printf("%d ", array[i]);
  }
  printf("\n");
  int num = pow(2, 3);
  printf("%d\n", num);

  return 0;
}