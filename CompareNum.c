#include <stdio.h>

char compare(float num1, float num2) {
  if (num1 > num2) {
    return '>';
  } else if (num1 < num2) {
    return '<';
  } else {
    return '=';
  }
}

int main() {
  float num1, num2;
  printf("Enter num1: ");
  scanf("%f", &num1);
  printf("Enter num2: ");
  scanf("%f", &num2);

  char res = compare(num1, num2);
  printf("num1 %c num2", res);
  
  return 0;