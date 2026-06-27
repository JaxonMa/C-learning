#include <stdio.h>

int main() {
  int page_42 = 300;
  int *index = &page_42; // 目录写着"第42页"

  int value = *index; // 翻到第42页，阅读内容
  printf("The value at page 42 is: %d\n", value);
}