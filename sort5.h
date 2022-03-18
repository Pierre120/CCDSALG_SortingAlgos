/****************************************************
REFERENCE

Author: Austin G. Walters
Link: https://austingwalters.com/radix-sort-in-c/
****************************************************/


/* 
	You may declare additional functions here
*/
int findLargestNum(int Array[], int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(Array[i] > largestNum)
      largestNum = Array[i];
  }
  
  return largestNum;
}


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using Radix sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void sort5(int A[], int n, double *dCounter) {
	//	your code here
  int i;
  int semiSorted[n];
  int significantDigit = 1;
  int largestNum = findLargestNum(A, n);

  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0)
  {
    int bucket[10] = {}; // empty set

    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < n; i++)
    {
      bucket[(A[i] / significantDigit) % 10]++;
      ++*dCounter;
    }
      
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a "semiSorted" array
    for (i = n - 1; i >= 0; i--)
      semiSorted[--bucket[(A[i] / significantDigit) % 10]] = A[i];
    
    for (i = 0; i < n; i++)
      A[i] = semiSorted[i];
    
    // Move to next significant digit
    significantDigit *= 10;
  }
}
