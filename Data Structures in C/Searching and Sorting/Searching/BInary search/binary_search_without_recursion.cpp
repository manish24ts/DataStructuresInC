//Binary search without recursion 
#include<stdio.h>
int bsearch(int a[],int low,int high,int key);
int a[20],i,n,key,mid,low,high;
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
	result = bsearch(a,0,n-1,key);
	if(result == -1)
	   printf("Key element is not present\n");
	else
	   printf("Key element found at %d position\n",result);
	return 0;
}

bsearch(int a[],int low,int high,int key)
{
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key == a[mid])
		return mid;
		else if(key>a[mid])
		low = mid+1;
		else if(key<a[mid])
		high = mid-1;
	}
	return -1;
}

/*
 It has a time complexity of
Best case O(1)
Worst case O(log(n))
Average case O(log(n))
*/
