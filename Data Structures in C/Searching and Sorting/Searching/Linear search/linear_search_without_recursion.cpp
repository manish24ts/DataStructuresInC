//Linear search without recursion 
#include<stdio.h>
int lsearch(int a[],int n,int key);
int a[20],i,n,key;
int main()
{
	int result;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	printf("Enter key:\n");
	scanf("%d",&key);
	result = lsearch(a,n,key);
	if(result == -1)
	   printf("Key element is not present\n");
	else
	   printf("Key element found at %d position\n",result);
	return 0;
}

lsearch(int a[],int n,int key)
{
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		return i;
	}
	return -1;
}

/*
 It has a time complexity of
Best case O(1)
Worst case O(n)
Average case O(n)
*/
