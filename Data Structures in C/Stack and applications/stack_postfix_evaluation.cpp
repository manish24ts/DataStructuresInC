#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

char postfix[50],stack[50];
int top=-1;

void push(char item);
int pop();

int main()
{
	int a,b,res,i;
	char ele;
	printf("Enter Postfix Expression:\n");
	gets(postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		ele = postfix[i];
		if(isdigit(ele))  //If token is digit then push on stack
		{
			push(ele-'0');//This is for converting Character datatype into integer (ASCII convertion)
		}
		else
		{
			a = pop();//If it's an operator, pop from stack twice and perform operation on the popped elements
			b = pop();
			switch(ele)
			{
				case '+': res = b+a;break;
				case '-': res = b-a;break;
				case '*': res = b*a;break;
				case '/': res = b/a;break;
				case '%': res = b%a;break;
				case '^': res = pow(b,a);break;
				default : printf("INVALID POSTFIX EXPRESSION\n"); exit(1);
			}
			push(res); //Push the result onto the stack
		}
	}
    printf("Evaluation of expression: %d",stack[top]); //The last remaining element on stack is the final result.
}


void push(char item)
{
	stack[++top] = item;
}

int pop()
{
	if(top==-1)
	{
		printf("INVALID POSTFIX EXPRESSION\n");
		exit(1);
	}
	return stack[top--];
}
