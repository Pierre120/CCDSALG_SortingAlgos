/****************************************************
REFERENCE

Author: GeeksforGeeks, improved by Sam007 and splevel62 
Link: https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using gnome (stupid) sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void sort6(int A[], int n, double *dCounter) {
	//	your code here

  //documentation unfinished
  
  int pos = 0;
  int temp;

  // might change != to <
  while(pos != n){

    if(pos == 0 || A[pos - 1] <= A[pos]){

      //If at index 0 or when no swaps are made, move forward by 1 index
      pos++;

    }else if(A[pos - 1] > A[pos]){

      //swap
      temp = A[pos - 1];
      A[pos - 1] = A[pos];
      A[pos] = temp;

      ++*dCounter;

      //If a swap is made, compare preceding pair by going 1 index back
      pos--;
    }

  }


 
}
