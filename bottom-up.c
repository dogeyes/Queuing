#include <stdio.h>
#include <time.h>
#define max(x,y) ((x)>(y)?(x):(y))

typedef struct{
	double val;
	int start;
} arrB;

void compute_B(double a[], arrB b[], int n){
	int i;
	if (a[0] > 0){
		b[0].val = a[0];
		b[0].start = 0;
	}
	else{
		b[0].val = 0;
		b[0].start = -1;
	}

	for (i=1; i<n; i++){
		if ((b[i].val = b[i-1].val + a[i])>0){
			if (b[i-1].start == -1)
				b[i].start = i;
			else
				b[i].start = b[i-1].start;
		}
		else{
			b[i].val = 0;
			b[i].start = -1;
		}
	}
}

//test data
int main(void){
	int i, maxEndIndex = 0, n = 30;
	double maxval = 0;
	double a[] = {-2, -3, 2, -1, 4, -1, -10, 6, 1, 7, -3, 10, -2, 0, -1, 2, 3, 5, -12, 30, -1, 23, 34, -12, -2, -4, 2, 4, -5, 2};
	arrB b[n];

	clock_t begin = clock()*1000;
	compute_B(a, b, n);
	for (i=0; i<n; i++)
		if (maxval<b[i].val){
			maxval = b[i].val;
			maxEndIndex = i;
		}
	clock_t end = clock()*1000;
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n%.2f\t\t%d --> %d\t%f ms\n", b[maxEndIndex].val, b[maxEndIndex].start+1, maxEndIndex+1, time_spent);

	return 0;
}
