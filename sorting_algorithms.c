#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.c"


/*This method will take an array of unsorted floating point numbers,
 *and return the sorted version of the array, by using bubble_sort
 */
float* bubble_sort(float* unsorted, int length)
{

  float* sorted = (float*)malloc(length*sizeof(float));
  memcpy(sorted, unsorted, sizeof(float)*length);

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

  return sorted;

}



/*This method will take an array of unsorted floating point numbers,
 *and return the sorted version of the array, by using insertion sort
 */
float* insertion_sort(float* unsorted, int length)
{

  float* sorted = (float*)malloc(length*sizeof(float));
  memcpy(sorted, unsorted, sizeof(float)*length);

  
  for(int i = 1; i < length; i++)
  {
    int j = i;
    while(j > 0 && sorted[j] < sorted[j-1])
    {
      swap(sorted,j, j-1);
      j--;
    }
  }
 
  return sorted;
}


//this is a helper function used to help with merge sort
//it will take 2 sorted arrays and return a sorted array by merging them
float* merge(float* arr1, float* arr2, int arr1Len, int arr2Len)
{
  int indexArr1 = 0;//holds the index of the array element that is being merged from the first array
  int indexArr2 = 0;//holds the index of the array element that is being merged from the second array

  float* toReturn = (float*)malloc((arr1Len + arr2Len)*sizeof(float));
  int toReturnIndex = 0;


  while(indexArr1 < arr1Len && indexArr2 < arr2Len)
  {
    if(arr1[indexArr1] <= arr2[indexArr2])
    {
      toReturn[toReturnIndex] = arr1[indexArr1];
      indexArr1++;
    }
    else
    {
      toReturn[toReturnIndex] = arr2[indexArr2];
      indexArr2++;
    }
    toReturnIndex++;
  }


  while(indexArr1 < arr1Len)
  {
    toReturn[toReturnIndex] = arr1[indexArr1];

    indexArr1++;
    toReturnIndex++;
  }


  while(indexArr2 < arr2Len)
  {
    toReturn[toReturnIndex] = arr2[indexArr2];

    indexArr2++;
    toReturnIndex++;
  }


  return toReturn;
}
