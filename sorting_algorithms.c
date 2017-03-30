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


//This method will be used to fid the partition in quicksort
int partition(float* unsorted, int l, int r) 
{
  int pivot, i, j, t;
  pivot =unsorted[l];
  i = l; j = r+1;
		
  while(1)
  {
    do ++i; while( unsorted[i] <= pivot && i <= r );
   	do --j; while( unsorted[j] > pivot );
   	if( i >= j ) break;
    swap(unsorted, i, j);
  }
    swap(unsorted, l, j);
    return j;
}

//This method will be used to recursively call itself to do the quick sort
void quickSort(float* unsorted, int l, int r)
{
  int j;

  if( l < r ) 
  {
     j = partition( unsorted, l, r);
     quickSort( unsorted, l, j-1);
     quickSort( unsorted, j+1, r);
  }	
}


//this method calls quicksort to return a sorted array
float* quick_sort(float* unsorted, int length)
{
	float* toReturn = (float*)malloc(length*sizeof(float));
	memcpy(toReturn, unsorted, sizeof(float)*length);
	quickSort(toReturn, 0, length-1);
	return toReturn;
}





float* selection_sort(float* unsorted, int length)
{

  float* sorted = (float*)malloc(length*sizeof(float));
  memcpy(sorted, unsorted, sizeof(float)*length);


	int numSorted = 0;//this int will hold the number of sorted elements
	while(numSorted < length)
	{
		//assume the first element in the unsorted array is the min, until proven otherwise
    int currMin = sorted[numSorted];
    int currMinIndex = numSorted;

    //loop through the unsorted array and find a min
    for(int i = numSorted; i < length; i++)
    {
    	if(sorted[i] < currMin)//if a new min value is found, update currMin and curMinIndex
    	{
        currMin = sorted[i];
        currMinIndex = i;
    	}
    }

    //swap the min into its correct place
    swap(sorted, currMinIndex, numSorted);
    numSorted++;
	}

  //return the sorted array 
  return sorted;

}
