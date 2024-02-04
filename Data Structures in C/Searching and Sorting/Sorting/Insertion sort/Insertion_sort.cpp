#include<stdio.h>
int insertion_sort(int a[],int n);
int a[20],i,j,n,temp;
int main()
{
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	printf("Before sorting:\n");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	insertion_sort(a,n);
	printf("\nAfter sorting:\n");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	return 0;
}

insertion_sort(int a[],int n)
{
	for(i=0;i<n;i++)
	{
		temp = a[i];
		j = i-1;
		while(a[j]>temp && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
	    a[j+1]=temp;
	}
}

/*
 It has a time complexity of
Best case O((n)^2)
Worst case O((n)^2)
Average case O((n)^2)

If its a sorted array then O(n)
*/
