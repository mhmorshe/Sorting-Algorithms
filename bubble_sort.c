#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This method will be used to swap 2 elements of a float array
void swap(float* array, int index1, int index2)
{
  float temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}


/*This method will take an array of unsorted floating point numbers,
 *and return the sorted version of the array
 */
float* bubble_sort(float* unsorted, int length)
{

  float* sorted = (float*)malloc(length*sizeof(float));
  memcpy(sorted, unsorted, sizeof(float)*length);

  printf("The unsorted array is \n");
  for(int i = 0; i < length; i++)
  {
    printf("%f\n",sorted[i]);
  }


  for(int i = length; i > 0; i--)
  {
    for(int j = 0; j < i - 1; j++)
    {
      if(sorted[j] > sorted[j+1])
      {
        swap(sorted, j, j+1);
      }     
    }
  }



  printf("\nThe sorted array is \n");
  for(int i = 0; i < length; i++)
  {
    printf("%f\n",sorted[i]);
  }


}
