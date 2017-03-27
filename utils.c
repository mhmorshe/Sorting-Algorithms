#include <stdio.h>

//this functon will be used to swap 2 elements of a float array
void swap(float* array, int index1, int index2)
{
  float temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

//this function will be used to print the elents of a flaot array
void print_arr(float* array, int length)
{
  for(int i = 0; i < length; i++)
  {
    printf("%f\n", array[i]);
  }
}
