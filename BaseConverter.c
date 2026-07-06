#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void clear_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

char* dec_to_bin(int* dec) {
  // The first column of the binary form is always 1
  int num_columns = (int)log2(*dec) + 1;
  char* bin = (char*)malloc(num_columns * sizeof(char));
  bin[0] = '1';

  int value_of_columns[num_columns];
  for (int i = 0; i < num_columns; i++) {
    value_of_columns[i] = pow(2.0, num_columns - i - 1);
  }

  int difference = *dec - value_of_columns[0] * 1;
  for (int i = 1; i < num_columns; i++) {
    if (value_of_columns[i] > difference) {
      bin[i] = '0';
    } else {
      bin[i] = '1';
      difference -= value_of_columns[i] * 1;
    }
  }

  return bin;
}

int bin_to_dec(char* bin) {
  int length = 0;
  char* temp_bin = bin;

  // Get how many columns there are in binary form
  while (*temp_bin) {
    length++;
    temp_bin++;
  }
  if (length == 0) return 0;

  int columns[length];
  for (int i = 0; i < length; i++) {
    columns[i] = pow(2.0, length - i - 1);
  }

  int dec = 0;
  int index = 0;
  while (*bin) {
    if (*bin == '1')
      dec += columns[index] * 1;
    index++;
    bin++;
  }

  return dec;
}

int main() {
  char option;
  printf("Select mode:\n[1] Binary -> Decimal\n[2] Decimal -> Binary\n>>> ");
  scanf("%c", &option);
  // clear_buffer();

  int dec_num;
  char bin_num[128];
  switch (option) {
    case '1':
      // dec to bin
      printf("Enter the number in decimal: ");
      scanf("%d", &dec_num);
      char* bin = dec_to_bin(&dec_num);
      printf("The binary of %d is %s\n", dec_num, bin);
      free(bin);
      break;

    case '2':
      // bin to dec
      printf("Enter the number in binary: ");
      scanf("%s", bin_num);
      int dec = bin_to_dec(bin_num);
      printf("The decimal of %s is %d\n", bin_num, dec);
      break;

    default:
      printf("Please select an option provided");
      break;
  }

  return 0;
}