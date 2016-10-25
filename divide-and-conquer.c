#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(x,y) ((x)>(y)?(x):(y))

double trimax(double a, double b, double c){
	return max(max(a, b), c);
}

double maxCrossoverSum(double a[], int first, int mid, int last){
	double leftSum =0, rightSum = 0;
	double leftReturn = a[mid];
	double rightReturn = a[mid+1];
	int i, j;
	for (i=mid; i>first-1; i--){
		leftSum += a[i];
		if (leftSum > leftReturn)
			leftReturn = leftSum;
	}
	for (j=mid+1; j<last+1; j++){
	     rightSum += a[j];
	     if (rightSum > rightReturn)
	    	 rightReturn = rightSum;
	}
	return leftReturn + rightReturn;
}


double maxSum_DC(double a[], int first, int last){
    int mid;
    if (first == last)
        return a[first];
    else{
        mid = (first + last) / 2;
        return trimax(maxSum_DC(a, first, mid), maxSum_DC(a, mid + 1, last), maxCrossoverSum(a, first, mid, last));
    }
}

//test data
int main(void){
	clock_t start = clock()*1000;
	double a[] = {-2, -3, 2, -1, 4, -1, -10, 6, 1, 7, -3, 10, -2, 0, -1, 2, 3, 5, -12, 30, -1, 23, 34, -12, -2, -4, 2, 4, -5, 2};
	int n = 30;
	printf("Sum of maximum subarray is %f\n", maxSum_DC(a, 0, n-1));
	clock_t end = clock()*1000;
	printf("Time:\t%f\n", (double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
