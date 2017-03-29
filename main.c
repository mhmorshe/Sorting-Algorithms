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

  printf("The original list is");
  print_arr(unsorted,9);

  printf("The sorted list from merge sort is\n");
  float* merge_sorted = merge_sort(unsorted,9);
  print_arr(merge_sorted, 9);

  printf("The original list is\n");
  print_arr(unsorted,9);

  printf("The sorted list from quick sort is\n");
  float* quick_sorted = quick_sort(unsorted,9);
  print_arr(quick_sorted, 9);

  printf("The original list is\n");
  print_arr(unsorted,9);


  printf("The sorted list from selection sort is\n");
  float* selection_sorted = selection_sort(unsorted,9);
  print_arr(selection_sorted, 9);

  printf("The original list is\n");
  print_arr(unsorted,9);


}
