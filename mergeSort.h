/****************************************************
REFERENCE

Author: Obtained from Prof. Arren Antioquia's CCDSALG course slides (T3 AY2020-2021)
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
void merge(int arr[], int nSize, int nMid, double *dCounter) 
{
  int i, j, k = 0; 
  int nLeft = nMid; 
  int nRight = nSize - nMid; 
  int L[nLeft], R[nRight]; 
  
  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < nLeft; i++) 
    L[i] = arr[i]; 
    
  for (j = 0; j < nRight; j++) 
    R[j] = arr[nMid + j];
  
  i = 0, j = 0; // initialize back to zero

  // MERGE & SORT
  while (i < nLeft && j < nRight) 
  { 
    if (L[i] <= R[j]) { 
      arr[k] = L[i]; 
      i++; 
    } 
    else { 
      arr[k] = R[j]; 
      j++; 
    } 
    
    ++*dCounter;
    k++; 
  }


  // MERGE ONLY

  /* Copy the remaining elements of temporary arrays */
  while (i< nLeft) 
  { 
    arr[k] = L[i]; 
    i++; 
    k++; 
  } 
  
  while (j < nRight) 
  { 
    arr[k] = R[j]; 
    j++; 
    k++; 
  }
}



/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void mergeSort(int A[], int n, double *dCounter) {
	//	your code here
  if(1 < n) 
  {
    int nMid = n / 2;
    mergeSort(A, nMid, dCounter);
    mergeSort(&A[nMid], n - nMid, dCounter);
    merge(A, n, nMid, dCounter);
  }
}