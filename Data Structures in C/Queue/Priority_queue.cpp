// Min Priority Queue
#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size],front=-1,rear=-1,i;

void enqueue();
void dequeue();
void display();
void check(int x);

int main()
{
	int ch;
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	do
	{
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();break;
			case 2: dequeue();break;
			case 3: display();break;
			case 4: printf("Exiting the process\n");exit(1);
			default: printf("Wrong option\n");
		}
	}while(ch<=4);
}

void enqueue()
{
	int temp;
	if(rear == size - 1) //Priority Queue overflow condition
	   printf("Priority Queue overflow\n");
	else
	{
	printf("Enter data value:\n");
	scanf("%d",&temp);
    if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = temp;
	}
	else
	{
		check(temp);
		rear++;
	}
	}
}

void dequeue()
{
	if(front == -1 && rear == -1) //Priority Queue underflow condition
	   printf("Priority Queue underflow\n");
	else if (front == rear)
	{
		printf("%d is deleted from the Priority Queue\n",queue[front]);
		front = rear = -1;
	}
	else
	printf("%d is deleted from the Priority Queue\n",queue[front++]);
}

void display()
{
	if(front == -1 && rear == -1)
	   printf("Priority Queue is empty\n");
	else
	{
		for(i=front;i<=rear;i++)
		printf("%d\t",queue[i]);
		printf("\n");
	}
}

void check(int x) //Priority queue uses Insertion Sort
{
	int j;
	for(j=rear;j>=front;j--)
	{
		if(x<=queue[j]) //for min <= for max >=
		queue[j+1] = queue[j];
		else
		break;
	}
	queue[j+1]=x;
}

