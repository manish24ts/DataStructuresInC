#include<stdio.h>
int a[20],i,pos,n,ele;
//Create of an array
void create()
{
	printf("Enter size of Array:\n");
	scanf("%d",&n);
	printf("Enter elements into an Array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}

//Display the array
void display()
{
	printf("Array elements\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
}

//Inserting an Element in array
void insert()
{
	printf("Enter element value:\n");
	scanf("%d",&ele);
	printf("Enter the index to insert new element:\n");
	scanf("%d",&pos);
	for(i=n;i>pos;i--)
	a[i]=a[i-1];
	a[pos]=ele;
	n++;
}

//Deletion of an element
void deletion()
{
	printf("Enter position to be deleted:\n");
	scanf("%d",&pos);
	for(i=pos;i<n-1;i++)
	a[i] = a[i+1];
	n--;
}

int main()
{
	int ch;
	printf("1.Create\n2.Display\n3.Insert\n4.Delete\n");
	do
	{
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();break;
			case 2: display();break;
			case 3: insert();break;
			case 4: deletion();break;
		}
	}while(ch<=4);
	return 0;
}
