#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void clear_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

char* dec_to_bin(int* dec) {
  // The first column of the binary form must be 1
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
      continue;

    } else if (value_of_columns[i] < difference) {
      bin[i] = '1';
      difference -= value_of_columns[i] * 1;

    } else {
      bin[i] = '1';
      memset(&bin[i+1], '0', num_columns - (i+1));
      break;
    }
  }

  return bin;
}

int main() {
  char option;
  printf("Select mode:\n[1] Binary -> Decimal\n[2] Decimal -> Binary\n>>> ");
  scanf("%c", &option);
  // clear_buffer();

  int num;
  switch (option) {
    case '1':
      printf("Enter the number in decimal: ");
      scanf("%d", &num);
      char* bin = dec_to_bin(&num);
      printf("The binary of %d is %s\n", num, bin);
      free(bin);
      break;

    case '2':
      break;

    default:
      printf("Please select an option provided");
      break;
  }

  return 0;
}