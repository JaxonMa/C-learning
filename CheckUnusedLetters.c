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
  char test_text[] =
      "He sat by the tree. The sun was hot, but the cold sea was near. He felt "
      "glad to be there, away from all the loud city noise. He had a book in his "
      "hand, but he just kept looking at the blue waves that one skips a bunch "
      "of letters, so it's a good test for your alphabet-tracking logic. how's "
      "that work for your code?";
  size_t length = sizeof(test_text) / sizeof(test_text[0]);
  char used_letters[27] = {0};
  char unused_letters[27] = {0};

  to_lower_string(test_text);
  get_used_letters(test_text, used_letters);
  printf("%s\n", used_letters);
  get_unused_letters(test_text, unused_letters);
  printf("%s\n", unused_letters);

  return 0;
}