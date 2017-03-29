#include <stdio.h>
#include <time.h>
#include "sorting_algorithms.c"


//this method will be used to handle the user's input
void handle_option(int option, float* unsorted, float* sorted, int numberOfFloats)
{


  if(option == 1)
  {
    printf("The unsorted list is\n");
    print_arr(unsorted, numberOfFloats);
  }
  else if(option == 2)
  {
    printf("Running selection sort\n");
    free(sorted);
    time_t before = time(NULL);
    sorted = selection_sort(unsorted,numberOfFloats);
    time_t after = time(NULL);
    double diff_sec = difftime(after,before);
    printf("Sorting was done in %d seconds\n", diff_sec);
  }
  else if(option == 3)
  {
    printf("Running bubble sort\n");
    free(sorted);
    time_t before = time(NULL);
    sorted = bubble_sort(unsorted,numberOfFloats);
    time_t after = time(NULL);
    double diff_sec = difftime(after,before);
    printf("Sorting was done in %d seconds\n", diff_sec);
  }
  else if(option == 4)
  {
    printf("Running insertion sort\n");
    free(sorted);
    time_t before = time(NULL);
    sorted = insertion_sort(unsorted,numberOfFloats);
    time_t after = time(NULL);
    double diff_sec = difftime(after,before);
    printf("Sorting was done in %d seconds\n", diff_sec);
  }
  else if(option == 5)
  {
    printf("Running merge sort\n");
    free(sorted);
    time_t before = time(NULL);
    sorted = merge_sort(unsorted,numberOfFloats);
    time_t after = time(NULL);
    double diff_sec = difftime(after,before);
    printf("Sorting was done in %d seconds\n", diff_sec);
  }
  else if(option == 6)
  {
    printf("Running quick sort\n");
    free(sorted);
    time_t before = time(NULL);
    sorted = quick_sort(unsorted,numberOfFloats);
    time_t after = time(NULL);
    double diff_sec = difftime(after,before);
    printf("Sorting was done in %d seconds\n", diff_sec);
  }
  else if(option == 7)
  {
    if(sorted == NULL)
    {
      printf("A sorting algorithm has not been run yet, can not print the sorted list");
    }
    else
    {
      printf("The sorted list is:\n");
      print_arr(sorted, numberOfFloats);
    }

  }
  else if(option == 8)
  {
    return;
  }


}

//this function will be used to print the menue for the user 
void print_Menue()
{
  printf("Menue:\n");
  printf("1: Enter 1 to print the unsorted input Data\n");
  printf("2: Enter 2 to run selection sort\n"); 
  printf("3: Enter 3 to run bubble sort\n");
  printf("4: Enter 4 to run insertion sort\n");
  printf("5: Enter 5 to run merge sort\n");
  printf("6: Enter 6 to run quick sort\n");
  printf("7: Enter 7 to print the sorted Data, you must have run one of the sorting algorithms before doing this\n");
  printf("8: Enter 8 to exit the program\n");
  printf("Please Enter option here: ");
}



//This is the main function used to run the program
void main(int argc, char* argv[])
{
  //check the command line arguments
  if(argc != 2)
  {
    printf("Error: incorect number of arguments passed to the program\n");
    printf("Please Read README.txt and try again\n");
    return;
  }

  FILE* inputFile = fopen(argv[1], "r");

  if(inputFile == NULL)
  {
    printf("Error: An invalid file name was entered, please make sure the argument to the program is a file in the current directory\n");
  }

  //count the number of floatz in the input file
  int numberOfFloats = 0;

  
  float currentInput;
  while(fscanf(inputFile, "%f", &currentInput) != EOF)
  {
    numberOfFloats++;
  }
  fclose(inputFile);
  printf("The input file had %d floats, building an unsorted array with input data\n", numberOfFloats);


  //fill the input array
  float* inputArr = (float*)malloc(numberOfFloats*(sizeof(float)));
  FILE* inputArrFile = fopen(argv[1], "r");//this is another file pointer used to write to the input array
  for(int i = 0; i < numberOfFloats; i++)
  {
    fscanf(inputArrFile,"%f", &inputArr[i]);
  }

  

  float* sorted = NULL;//float pointer, should point to the sorted data
  int option;//int to hold the user option
  print_Menue();//print the menue 
  scanf("%i", &option);//read the user input
  while(option != 8)
  {
    handle_option(option, inputArr, sorted, numberOfFloats);

    if(option != 8)
    {
      print_Menue();
      scanf("%i", &option);
    }

  }

  printf("Exiting the program, have a nice day :)\n");

}


