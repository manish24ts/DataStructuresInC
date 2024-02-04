#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*n,*temp;

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
	n = (struct node*)malloc(sizeof(struct node));//Node intialization 
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	n->next=NULL;
	if(front == NULL && rear == NULL)
	{
		front = n;
		rear = n;
	}
	else
	{
	rear->next=n;
	rear=n;
	}
}

void dequeue()
{
	if(front == NULL) 
	   printf("Queue underflow\n");
	else 
	{
		temp = front;
		front = front->next;
		free(temp);
	}
}

void display()
{
	if(front == NULL && rear == NULL)
	   printf("Queue is empty\n");
	else
	{
		temp = front;
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
