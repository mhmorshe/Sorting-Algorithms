#include <stdio.h>
#include "sorting_algorithms.c"

//This is the main function used to run the program
void main()
{
  float unsorted[9] = {1.1, 1.2, 4.5, 5.1, 3.2, 1.0, 0 , 54, 12.7};

  printf("The unsorted list is\n");
  print_arr(unsorted, 9);

  //running bubble sort
  float* bubble_sorted;
  bubble_sorted = bubble_sort(unsorted, 9);
  //print bubble sorted list
  printf("The sorted list from bubble sort is is\n");
  print_arr(bubble_sorted, 9);



  //running bubble sort
  float* insertion_sorted;
  insertion_sorted = insertion_sort(unsorted, 9);
  //print bubble sorted list
  printf("The sorted list from insertion sort is\n");
  print_arr(insertion_sorted, 9);



  //test the merge step of merge sprt
  float unsorted1[5] = {1,3,5,7,9};
  float unsorted2[4] = {2,4,8,10};

  float* merge_sorted = merge(unsorted1,unsorted2, 5, 4);
  print_arr(merge_sorted, 9);




}
