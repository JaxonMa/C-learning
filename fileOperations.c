#include <stdio.h>

int main() {
  // Write file
  FILE* fp = fopen("test.txt", "w");
  fprintf(fp, "This is my first file written with C");
  fclose(fp);

  return 0;
}
