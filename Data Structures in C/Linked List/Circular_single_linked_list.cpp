//Circular Single or Singly linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next; //Self referential Structure
}*head=NULL,*last,*n,*temp,*p;

void create();
void display();
void insertBegin();
void insertEnd();
void insertAfterKey();
void insertBeforeKey();
void deleteBegin();
void deleteEnd();
void deleteKey();


int main()
{
	int ch;
	printf("1.Create\n2.Display\n3.Insert start\n4.Insert end\n5.Insert After key\n6.Insert Before key\n7.Delete start\n8.Delete end\n9.Delete key\n10.Exit\n");
	do
	{
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();break;
			case 2: display();break;
			case 3: insertBegin();break;
			case 4: insertEnd();break;
			case 5: insertAfterKey();break;
			case 6: insertBeforeKey();break;
			case 7: deleteBegin();break;
			case 8: deleteEnd();break;
			case 9: deleteKey();break;
			case 10: printf("Exiting the process\n");exit(1);
			default: printf("Wrong option\n");
		}
	}while(ch<=10);
}

void create()
{
	n = (struct node*)malloc(sizeof(struct node)); //Initallising a node
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	n->next=NULL;
	if(head==NULL) //If head is Null, assign n to head and last
	{
		head = n;
		last = n;
	}
	else
	{
		last->next=n; //new node and last node linking
		last=n;       // re-assignning last
	}
	last->next=head;
}

void display()
{
	temp = head;
	if(temp==NULL)
	printf("Empty list\n");
	else
	{
		printf("The linked list is:\n");
		do
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}while(temp!=head);
		printf("\n");
	}
}

void insertBegin()
{
	n = (struct node*)malloc(sizeof(struct node)); //Initallising a node
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	n->next=head;  //new node and head node linking
	head = n;      //re-assiging head
	last->next=head;
}

void insertEnd()
{
	n = (struct node*)malloc(sizeof(struct node)); //Initallising a node
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	n->next=NULL;
	last->next = n;  //new node and last node linking
	last = n;        //re-assiging last
	last->next=head;
}

void insertAfterKey()
{
	int key;
	n = (struct node*)malloc(sizeof(struct node)); //Initallising a node
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	printf("Enter key:\n");
	scanf("%d",&key);
	temp = head;
	while(temp!=NULL) //Traversing to find key
	{
		if(temp->data==key)
		break;
		temp = temp->next;
	}
	n->next=temp->next;
	temp->next=n;
}

void insertBeforeKey()
{
	int key;
	n = (struct node*)malloc(sizeof(struct node)); //Initallising a node
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	printf("Enter key:\n");
	scanf("%d",&key);
	temp = head;
	while(temp!=NULL) //Traversing to find key
	{
		if(temp->data==key)
		break;
		else
		{
			p = temp;
			temp = temp->next;
		}
	}
	n->next=p->next;
	p->next=n;
}

void deleteBegin()
{
	temp = head;
	head = head->next;
	free(temp);
	last->next=head;
}

void deleteEnd()
{
	temp = head;
	while(temp!=last)
	{
		p = temp;
		temp = temp->next;
	}
	p->next = NULL;
	last = p;
	free(temp);
	last->next=head;
}

void deleteKey()
{
	int key;
	temp = head;
	printf("Enter key:\n");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data==key)
		break;
		else
		{
			p = temp;
			temp = temp->next;
		}
	}
	p->next=temp->next;
	temp->next=NULL;
	free(temp);
}
