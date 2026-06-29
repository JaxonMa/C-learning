#include <ctype.h>
#include <stdio.h>

// Size of the alphabet including '\0'
const int kAlphabetSize = 27;

void to_lower_string(char* text) {
  while (*text) {
    *text = tolower(*text);
    text++;
  }
}

void to_upper_string(char* text) {
  while (*text) {
    *text = toupper(*text);
    text++;
  }
}

int isin(char chr, char* text) {
  while (*text) {
    if (chr == *text) return 1;
    text++;
  }
  return 0;
}

void get_used_letters(char* text, char* used_letters) {
  int i = 0;
  while (*text) {
    if (i >= 26) return;
    if (isalpha(*text) && !isin(*text, used_letters)) {
      used_letters[i] = *text;
      i++;
    }
    text++;
  }
}

void get_unused_letters(char* used_letters, char* unused_letters) {
  char alphabet[26];
  int i = 0;
  for (int letter = 'a'; letter < 'z'; letter++) {
    alphabet[i] = letter;
    i++;
  }

  int index = 0;
  for (int i = 0; i < kAlphabetSize; i++) {
    char letter = alphabet[i];
    if (!isin(letter, used_letters)) {
      unused_letters[index] = letter;
      index++;
    }
  }
}

int main() {
  char user_input[1000];
  printf("Enter text to get unused letters: ");
  fgets(user_input, sizeof(user_input), stdin);

  size_t length = sizeof(user_input) / sizeof(user_input[0]);
  char used_letters[27] = {0};
  char unused_letters[27] = {0};

  to_lower_string(user_input);
  get_used_letters(user_input, used_letters);
  get_unused_letters(used_letters, unused_letters);
  to_upper_string(unused_letters);
  printf("These letters are not used in the text given:\n%s\n", unused_letters);

  return 0;
}