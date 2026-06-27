#include <stdio.h>
#include <string.h>

typedef struct book {
  char name[50];
  char author[50];
  int pages;
} book;

struct librarySystem {
  book books[50];
  int bookNum;
  char librarian[50];
} system;

void addBook(char name[50], char author[50], int pages) {
  int newBookIndex = system.bookNum;
  book newBook = system.books[newBookIndex];
  snprintf(newBook.name, sizeof(newBook.name), "%s", name);
  snprintf(newBook.author, sizeof(newBook.author), "%s", author);
  newBook.pages = pages;
  system.bookNum++;
}

void removeBook(int index) {
  book targetBook = system.books[index];
  snprintf(targetBook.name, sizeof(targetBook.name), "");
  snprintf(targetBook.author, sizeof(targetBook.author), "");
  targetBook.pages = 0;
}

void setLibrarian(char librarian[50]) {
  snprintf(system.librarian, sizeof(system.librarian), "%s", librarian);
}

int main() {
  system.bookNum = 0;
  setLibrarian("Lora");
  char *librarian = getLibrarian();
  printf("%s", librarian);
  return 0;
}