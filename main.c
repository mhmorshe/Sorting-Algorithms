#include <stdio.h>
#include "bubble_sort.c"
void main()
{
  float unsorted[3] = {1.1, 1.2, 4.5};
  bubble_sort(unsorted);
  printf("This is a test\n");
}
