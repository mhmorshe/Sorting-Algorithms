#include <stdio.h>
#include "sorting_algorithms.c"

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

  while(fscanf(inputFile, ))
  {

  }


}
