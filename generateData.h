/****************************************************
REFERENCE

Author: Samuel Sam
Link: https://www.tutorialspoint.com/rand-and-srand-in-c
****************************************************/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


#include <stdlib.h> 
#include <time.h> 

void generateData (int A[], int n) {   
    //	your code here
    int g;
    for(g = 0; g < n; g++)
      A[g] = rand() % n; // % n
      // just remove or change the modulo <num>
      // this is to limit the range of 
      // generated numbers when testing
}
