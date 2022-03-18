/****************************************************
REFERENCE

Author: GeeksForGeeks
Link: https://www.geeksforgeeks.org/selection-sort/
****************************************************/


/* 
	You may declare additional functions here
*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using selection sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void selectionSort(int A[], int n, double *dCounter) {
	//	your code here
  int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          {
            if (A[j] < A[min_idx])
            {
              min_idx = j;
              ++*dCounter;
            } 
            
          }
        // Swap the found minimum element with the first element
        swap(&A[min_idx], &A[i]);
    } 
 
}
