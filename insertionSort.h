/****************************************************
REFERENCE

Author: Faizan Parvez, Great Learning
Link: https://www.mygreatlearning.com/blog/insertion-sort-algorithm/
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using insertion sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/


// function to sort the elements of the array
void insertionSort(int A[], int n, double *dCounter) {
  int i;
  for (i = 1; i < n; i++) {
    int tmp = A[i];
    int j = i - 1;

    while (tmp < A[j] && j >= 0) {
      A[j + 1] = A[j];
      j--;
      ++*dCounter; 
    }
    
     A[j + 1] = tmp;
  }

}
