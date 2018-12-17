#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *a, int start, int end, int mid)
{
	int p1, p2, i, j, k;
	p1 = (mid - start)+1;
	p2 = (end - mid);

	int L[p1+1], R[p2+1];
	for (i = 0; i < p1; ++i)
	{
		L[i] = a[start + i];
	}
	for (i = 0; i < p2; ++i)
	{
		R[i] = a[mid + i + 1];
	}
	L[p1] = INT_MAX;
	R[p2] = INT_MAX;

	for (i=0,j=0, k=start; k <= end; k++)
	{
	  	if(L[i] <= R[j])
	  	{
	  		a[k] = L[i]; i++;
	  	}
	  	else
	  	{
	  		a[k] = R[j]; j++;
	  	}
	}
}

void mergesort(int *a, int start , int end)
{
	if(start < end)
	{
	    int mid = start+(end-start)/2;
	    mergesort(a, start , mid);
	    mergesort(a, mid+1, end);
	    merge(a, start, end, mid);
	}
}

int main()
{
	int *a = (int *) malloc(sizeof(double));
	int n, i=0,size;

	while(1)
	{
		if(scanf("%d", (a+i))==EOF) break;
    i++;
		a = (int *) realloc(v, sizeof(double)*(i+1));

	}
	size = i;
	mergesort(a, 0, size-1);

	for (i = 0; i < size; i++) printf("%d", *(a+i));
	return 0;
}
