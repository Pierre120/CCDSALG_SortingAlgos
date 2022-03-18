/****************************************************
REFERENCE

Author: GeeksforGeeks and Course Modules?
Link: https://www.geeksforgeeks.org/bubble-sort/
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using bubble sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void bubbleSort(int A[], int n, double *dCounter) {
	//	your code here

    int i, j;
    int temp;

    for(i= 0; i < n; i++){

      //checks two numbers at a time, []
      for(j = n - 1; j >= i+1; j--){

        if (A[j] < A[j-1]){
        
          //Swap
          temp = A[j-1];
          A[j-1] = A[j];
          A[j]= temp;

          //swaps if the number at current index is smaller than the previous one

          ++*dCounter;

        }

      }
    }
  
  
  
}
