#include<stdio.h>
void merge(int a[],int low,int mid,int high);
void mergesort(int a[],int low,int high);
int a[50],n,i,j,low,high,k,c[50],mid;
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
	mergesort(a, 0, n - 1); 
	printf("\nAfter sorting\n");
	for(i=0;i<n;i++)
	   printf("%d\t",a[i]);
	return 0;
}
void mergesort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergesort(a, beg, mid);  
        mergesort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  
void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0, /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}   

/*
 It has a time complexity of
Best case O(nlog(n))
Average case O(nlog(n))
Worst case O(nlog(n))
*/ 
