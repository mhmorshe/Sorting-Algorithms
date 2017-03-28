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



//this function will be used to perform a merge sort
float* merge_sort(float* arr, int length)
{
  //create an array of float pointers
  //each float pointer will point to a sub array needed in merge sort
  float* toMerge[length];

  //create an array to hold the lengths of each of the sub arrays
  int lengthOfSub[length];

  //fill both the array, every element of the original array is a sub array at first, with length 1
  for(int i = 0; i < length; i++)
  {
    toMerge[i] = &arr[i];
    lengthOfSub[i] = 1;
  }


  //int to hold the number of sub arrays, starts at the length because every element is a sub array at first
  int numberOfSub = length;

  //while ther is more than one sub array
  while(numberOfSub != 1)
  {



  }



}




