#include <stdio.h>
#define UNEXPECTED_INPUT_PLACEHOLDER 'u'

void clear_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

char get_mode() {
  // Ask user for operation
  char mode;
  printf(
      "Press A to add a new reminder\nPress Q to quit\n>>> ");
  scanf("%c", &mode);
  clear_buffer();

  if (mode == 'Q' || mode == 'q') {
    return 'Q';
  } else if (mode == 'A' || mode == 'a') {
    return 'A';
  } else {
    printf("Unexpected Input: %c\n\n", mode);
    return UNEXPECTED_INPUT_PLACEHOLDER;
  }

  return UNEXPECTED_INPUT_PLACEHOLDER;
}

void add_reminder() {
  // Add a new memo
  char memo[501];
  printf("New Memo (Limited to 500 characters, press ENTER to save.): \n");
  scanf("%[^\n]1000s", memo);
  clear_buffer();

  FILE* fp = fopen("reminder.txt", "a");
  fprintf(fp, "%s", memo);
  fclose(fp);
}

int main() {
  printf("Simple Memo\n");

  char mode = get_mode();
  while (mode == UNEXPECTED_INPUT_PLACEHOLDER) {
    mode = get_mode();
  }

  switch (mode) {
    case 'Q':
      return 0;
      break;
    case 'A':
      add_reminder();
      break;
    default:
      printf("Reminder is exiting due to an unexpected input: %c\n", mode);
      return 1;
      break;
  }
  return 0;
}