#include <stdio.h>

void each_plus_one(int arr[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    arr[i]++;
  }
}

void print_array(int arr[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d, ", arr[i]);
  }
}

// Actually, this function does not return an array, but it changes the value of an array declared
// in main(). It could be regarded as an alternative to returning an array.

int main() {
  int arr[3] = {1, 2, 3};
  size_t len = sizeof(arr) / sizeof(arr[0]);
  each_plus_one(arr, len);
  print_array(arr, len);

  return 0;
}