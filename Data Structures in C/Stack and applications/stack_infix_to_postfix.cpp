#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char stack[50],infix[50],postfix[50];
int top = -1,i=0,j=0;

void push(char a);
char pop();
int prec(char c);
void infixToPostfix(char infix[]);

int main()
{
	printf("Enter Infix Expression:\n");
	gets(infix);
	infixToPostfix(infix);
	printf("Post Expression is:\n");
	puts(postfix);
	return 0;
}

void push(char a)
{
	stack[++top] = a;
}

char pop()
{
	return stack[top--];
}

int prec(char c)
{
	if(c=='*'||c=='/'||c=='%')
	return 3;
	if(c=='+'||c=='-')
	return 2;
	if(c=='(')
	return 1;
}
void infixToPostfix(char infix[])
{
	char temp;
	for(i=0;i<strlen(infix);i++)
	{
		if(infix[i] == '(')          //If token is left parenthesis push on stack
		push(infix[i]);
		else if (isalpha(infix[i]))  //If character display directly
		postfix[j++]=infix[i];
		else if(infix[i]==')') //If right parenthesis pop and display elements in stack till left parenthesis and pop left parenthesis dont display it 
		{
			while(stack[top]!='(')
			postfix[j++]=pop();
			temp = pop();
		}
		else  //If token has less precendence that stack top element, then pop and display and push the token onto the stack
		{
			while(prec(stack[top])>=prec(infix[i]))
			postfix[j++]=pop();
			push(infix[i]);
		}
	}
	while(top!=-1) //After loop pop and display all elements in the stack and empty it
	postfix[j++]=pop();
	postfix[j]='\0';
}
