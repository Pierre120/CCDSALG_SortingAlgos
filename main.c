/****************************************************
Group: 		6
Section:	S13
Members:	Enrico Tolentino, Airon Cruz, Pierre Hernandez
****************************************************/

#include <stdio.h>
#include <time.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "sort5.h"
#include "sort6.h"
#include "generateData.h"
#include "timer.h"
#include <string.h>

int main() {
	
	//	your code here
  
	// sets seed for rand num generator
  srand(time(NULL));

  int N = 1024; 
  int *A; // array to be sorted
  int *arrCopy; // copy of the generated random values (unsorted)
  double dCounter; // stores counter value
  int M, nSortAlgo, d; // used for for-loops
  struct timespec startTime, endTime;
  double nAverageMET[6]; // stores MET of each sorting algo
  double nAverageCount[6]; // stores counter values of each sorting algo
  char sortingAlgo[6][15] = {"Bubble Sort", "Insertion Sort", 
        "Selection Sort", "Merge Sort", "Sort 5", "Sort 6"};

  // allocate memory for array
  A = (int*)calloc(N, sizeof(int));
  arrCopy = (int*)calloc(N, sizeof(int));

  // -- START OF THE LOOP OF INCREASING N STARTS HERE --

  // continues to increase N while
  // the memroy for tha arrays can be allocated
  while(A != NULL && arrCopy != NULL)
  {
    generateData(A, N); // generate & store N random values in A
 
    // make a copy of the generated values
    for(d = 0; d < N; d++)
      arrCopy[d] = A[d];

    // at least 10 runs
    for(M = 1; M <= 10; M++)
    {
      
      // for each sorting algorithm
      for(nSortAlgo = 0; nSortAlgo < 6; nSortAlgo++)
      {
        switch(nSortAlgo)
        {
          case 0:
            // bubble sort
            startTime = getTime(); // start CPU time
            bubbleSort(A, N, &dCounter); // sort the array
            endTime = getTime(); // end CPU time
            break;

          case 1:
            // insertion sort
            startTime = getTime(); // start CPU time
            insertionSort(A, N, &dCounter); // sort the array
            endTime = getTime(); // end CPU time
            break;
        
          case 2:
            // selection sort
            startTime = getTime(); // start CPU time
            selectionSort(A, N, &dCounter); // sort the array
            endTime = getTime(); // end CPU time
            break;

          case 3:
            // merge sort
            startTime = getTime(); // start CPU time
            mergeSort(A, N, &dCounter); // sort the array
            endTime = getTime(); // end CPU time
            break;
        
          case 4:
            // sort 5 (Radix Sort)
            startTime = getTime(); // start CPU time
            sort5(A, N, &dCounter); // sort the array
            endTime = getTime(); // end CPU time
            break;

          case 5:
            // sort 6 (Gnome Sort)
            startTime = getTime(); // start CPU time
            sort6(A, N, &dCounter); // sort the array
            endTime = getTime(); // end CPU time
            break;
        }

        nAverageMET[nSortAlgo] += getElapsed(startTime, endTime); // store MET
        nAverageCount[nSortAlgo] += dCounter; // store counter value 
      
        // copies the copy of generated random 
        // values (unsorted) to A
        for(d = 0; d < N; d++)
          A[d] = arrCopy[d];
          
        // resets counter value to 0
        dCounter = 0;
      }

    }

    // number of data
    printf("-- N: %d --\n\n", N);

    // print results of each sorting algo
    for(nSortAlgo = 0; nSortAlgo < 6; nSortAlgo++)   
    {
      printf("%s:\nAverage MET: %f milliseconds\nAverage counter value: %d\n\n",
            sortingAlgo[nSortAlgo], nAverageMET[nSortAlgo] / 10 * 1000,
            (int)(nAverageCount[nSortAlgo] / 10)); 
            // instead of 10 we can also do M - 1
            // so when we manipulate the number of times to run the
            // algorithms we only need to change 1 part of the line
      
      nAverageMET[nSortAlgo] = 0; // reset to 0
      nAverageCount[nSortAlgo] = 0; // reset to 0
    }

    /*
    This is to check if N * 2 will go beyond
    the value limit that an integer data type
    could store.
    
    Source of info about the limit of int data types:
    https://iq.opengenus.org/integer-datatype-in-c/
    */
    if(N * 2 > 2147483647)
      break; // exits the while loop
    else N *= 2; // multiply N by 2

    // reallocate number of elements to be stored by the arrays
    A = realloc(A, sizeof(int) * N);
    arrCopy = realloc(arrCopy, sizeof(int) * N);

    /*
    Values will be overriden during the generateData(),
    so no need for setting the values of array A and
    arrCopy to 0
    */
  }
  /*
  End program if it can't allocate
  sufficent memory for the arrays
  or limit of the integer data type
  is reached.
  */

  // deallocate allocated memory of arrays
  free(A);
  free(arrCopy);

	return 0;
}

