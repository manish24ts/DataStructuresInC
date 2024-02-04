#include<stdio.h>
#define size 5
int stack[size],top=-1,temp,i;
void push();
void pop();
void peek();
void display();
void isFull();
void isEmpty();

int main()
{
	int ch;
	printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Is full\n6.Is empty\n");
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
			case 5: isFull();break;
			case 6: isEmpty();break;
		}
	}while(ch<=6);
	return 0;
}

void push()
{
	if(top==size-1)
	printf("Stack overflow\n");
	else
	{
		printf("Enter Value:\n");
		scanf("%d",&stack[++top]);
	}
}

void pop()
{
	if(top==-1)
	printf("Stack underflow\n");
	else
	{
		printf("%d is deleted from the Stack\n",stack[top--]);
	}
}

void peek()
{
	printf("%d is at the Top of the Stack\n",stack[top]);
}

void display()
{
	if(top==-1)
	printf("Stack is Empty\n");
	for(i=top;i>=0;i--)
	printf("|%d|\n",stack[i]);
}

void isFull()
{
	if(top==size-1)
	printf("Stack is full\n");
	else 
	{
		temp = size - top -1;
		printf("Stack is not full, more %d elements can be added\n",temp);
	}
}

void isEmpty()
{
	if(top==-1)
	printf("Stack is Empty\n");
	else 
	{
		printf("Stack has %d elements\n",top+1);
	}
}
