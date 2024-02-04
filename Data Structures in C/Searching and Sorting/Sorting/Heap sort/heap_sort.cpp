#include<stdio.h>
void heapSort(int a[],int n);
void heapify(int a[],int n,int i);
int i,a[20],n,left,right,temp,largest;
int main()
{
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter elements into array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Array before heap sort:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	heapSort(a,n);
	printf("Array after heap sort:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
void heapSort(int a[],int n)
{
	for(i=(n/2)-1;i>=0;i--)
	heapify(a,n,i);
	for(i=n-1;i>=0;i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a,i,0);
	}
}
void heapify(int a[],int n,int i)
{
	largest = i;
	left = 2*i+1;
	right = 2*i+2;
	if(left < n && a[largest] < a[left])
	largest = left;
	if(right < n && a[largest] < a[right])
	largest = right;
	if(largest!=i)
	{
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a,n,i);
	}
}

/*
It's time complixity is
best case O(nlog(n))
average case O(nlog(n))
worst case O(nlog(n))
*/
