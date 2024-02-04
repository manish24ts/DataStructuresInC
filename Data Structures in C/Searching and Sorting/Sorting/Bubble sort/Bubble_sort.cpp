#include<stdio.h>
int bubble_sort(int a[],int n);
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
	bubble_sort(a,n);
	printf("\nAfter sorting:\n");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	return 0;
}
bubble_sort(int a[],int n)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

/*
 It has a time complexity of
Best case O((n)^2)
Worst case O((n)^2)
Average case O((n)^2)
*/
