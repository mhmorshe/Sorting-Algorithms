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

  if (length < 2)//if the length of the array is 1 or 0, it is already sorted
  {
    return arr;
  }


  //split the array into 2 sub arrays
  float *sub1, *sub2;
  int lenSub1, lenSub2;

 
  //allocate space for each sub array, should be half the size of
  //current arr, or half + 1 for odd number size
  lenSub1 = length / 2;
  lenSub2 = length - lenSub1;
  sub1 = (float*)malloc(sizeof(float) * lenSub1);
  sub2 = (float*)malloc(sizeof(float) * lenSub2);
  
  //fill each of the sub arrays with data from the current array
  for (int i =0; i < lenSub1 + lenSub2; i++) 
  {
  	if(i < lenSub1)
  	{
      sub1[i] = arr[i];
  	}
  	else
  	{
      sub2[i-lenSub1] = arr[i];
  	}

  }


  //recursively call merge_sort and conquer
  float* toReturn = merge(merge_sort(sub1, lenSub1), merge_sort(sub2, lenSub2), lenSub1 ,lenSub2);
  free(sub1);
  free(sub2);

  return toReturn;

}
