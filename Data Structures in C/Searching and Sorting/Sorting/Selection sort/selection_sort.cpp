#include<stdio.h>
int selection_sort(int a[],int n);
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
	selection_sort(a,n);
	printf("\nAfter sorting:\n");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	return 0;
}

selection_sort(int a[],int n)
{
	int min;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

/*
 It has a time complexity of
Best case O((n)^2)
Worst case O((n)^2)
Average case O((n)^2)
*/
