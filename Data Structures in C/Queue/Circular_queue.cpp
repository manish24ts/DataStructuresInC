#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size],front=-1,rear=-1,i;

void enqueue();
void dequeue();
void display();

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
	if(front == ((rear+1)%size))//Circular Queue overflow condition
	   printf("Circular Queue is Full\n");
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
		rear = (rear+1)%size;
		queue[rear] = temp;
	}
	}
}

void dequeue()
{
	if(front == -1 && rear == -1) //Circular Queue underflow condition
	   printf("Circular Queue is Empty\n");
	else if (front == rear)
	{
		printf("%d is deleted from the Circular Queue\n",queue[front]);
		front = rear = -1;
	}
	else
	{
		printf("%d is deleted from the Circular Queue\n",queue[front]);
		front = (front+1)%size;
	}
}

void display()
{
	if(front == -1 && rear == -1)
	   printf("Circular Queue is empty\n");
	else
	{
		for(i=front;i!=rear;i=(i+1)%size)
		printf("%d\t",queue[i]);
		printf("%d\n",queue[i]);
	}
}
