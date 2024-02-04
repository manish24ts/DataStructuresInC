#include<stdio.h>
void quicksort(int a[],int first,int last);
int a[50],n,i,j,first,last;
int main()
{
	printf("Enter size of an array:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	printf("\nBefore sorting\n");
	for(i=0;i<n;i++)
	   printf("%d\t",a[i]);
	quicksort(a,0,n-1);
	printf("\nAfter sorting\n");
	for(i=0;i<n;i++)
	   printf("%d\t",a[i]);
	return 0;
}
void quicksort(int a[],int first,int last)
{
	int pivot,temp;
	if(first<last)
	{
		i = first;
		j = last;
		pivot = first;
		while(i<j)
		{
			while(a[i]<=a[pivot])
			i++;
			while(a[j]>a[pivot])
			j--;
			if(i<j)
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
			temp = a[j];
			a[j] = a[pivot];
			a[pivot] = temp;
			quicksort(a,first,j-1);
			quicksort(a,j+1,last);
		}
	}
}

/*
 It has a time complexity of
Best case O(nlog(n))
Average case O(nlog(n))
Worst case O((n)^2)
*/
