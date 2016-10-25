#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(x,y) ((x)>(y)?(x):(y))

double maxSubArraySum(double a[], int n)
{
double max_Sum = a[0];
double curr_max = a[0];

int curStartIndex = 0;
int maxStartIndex;
int maxEndIndex;

for (int i = 1; i < n; i++)
{
    curr_max = max(a[i], curr_max+a[i]);
    if(curr_max > max_Sum){
        max_Sum = curr_max;
        maxStartIndex = curStartIndex;
        maxEndIndex = i;
    }
    if(curr_max < 0){
        curStartIndex = i+1;
    }
}
    printf("\n%.2f\t\t%d --> %d\t",max_Sum, maxStartIndex+1, maxEndIndex+1);

return max_Sum;
}


//test data
int main(void)
{
	clock_t start = clock()*1000;
	double a[] = {-2, -3, 2, -1, 4, -1, -10, 6, 1, 7, -3, 10, -2, 0, -1, 2, 3, 5, -12, 30, -1, 23, 34, -12, -2, -4, 2, 4, -5, 2};
	int n = 30;
	double max_sum = maxSubArraySum(a, n);
	clock_t end = clock()*1000;
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f ms\n", time_spent);

	return 0;
}
