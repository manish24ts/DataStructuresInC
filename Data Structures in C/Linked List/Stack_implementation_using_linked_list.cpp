//Stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*n,*top=NULL,*temp;

void push();
void pop();
void peek();
void display();
void isEmpty();

int main()
{
	int ch;
	printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Is empty\n6.Exit\n");
	do
	{
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();break;
			case 2: pop();break;
			case 3: peek();break;
			case 4: display();break;
			case 5: isEmpty();break;
			case 6: printf("Exiting process...\n");exit(1);
		}
	}while(ch<=6);
	return 0;
}

void push()
{
	n = (struct node*)malloc(sizeof(struct node));
	printf("Enter date value:\n");
	scanf("%d",&n->data);
	n->next=NULL;
	if(top==NULL)
	top = n;
	else
	{
		n->next=top;
		top = n;
	}
}

void pop()
{
	if(top==NULL)
	printf("Stack underflow\n");
	else
	{
		
		temp = top;
		top = top->next;
		free(temp);
	}
}

void peek()
{
	printf("%d is at the Top of the Stack\n",top->data);
}

void display()
{
	if(top==NULL)
	printf("Stack is Empty\n");
	temp = top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

void isEmpty()
{
	if(top==NULL)
	printf("Stack is Empty\n");
	else 
	printf("Stack is not Empty\n");
}
