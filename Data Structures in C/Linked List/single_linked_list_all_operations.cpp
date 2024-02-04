// Single or Singly linked list

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
void numberOfNodes();
void alternativeDisplay();
void reverseDisplay();
void searching();

int main()
{
	int ch;
	printf("1.Create\n2.Display\n3.Insert start\n4.Insert end\n5.Insert After key\n6.Insert Before key\n7.Delete start\n8.Delete end\n9.Delete key\n10.Count of nodes\n11.Alternative node display\n12.Reverse display\n13.Searching\n14.Exit\n");
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
			case 10: numberOfNodes();break;
            case 11: alternativeDisplay();break;
            case 12: reverseDisplay();break;
            case 13: searching();break;
			case 14: printf("Exiting the process\n");exit(1);
			default: printf("Wrong option\n");
		}
	}while(ch<=14);
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
}

void display()
{
	temp = head;
	if(temp==NULL)
	printf("Empty list\n");
	else
	{
		printf("The linked list is:\n");
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
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
}

void insertEnd()
{
	n = (struct node*)malloc(sizeof(struct node)); //Initallising a node
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	n->next=NULL;
	last->next = n;  //new node and last node linking
	last = n;        //re-assiging last
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

void numberOfNodes()
{
	int count=0;
	temp = head;
	while(temp!=NULL) //Traversing the linked list 
	{
		temp=temp->next;
		count++;
	}
	printf("There are %d node in the Linked list\n",count);
}

void alternativeDisplay()
{
	temp = head;
	printf("The alternative display is:\n");
	while(temp!=NULL && temp->next!=NULL) //Traversing the linked list 
	{
		printf("%d->",temp->data);
		temp=temp->next->next;
	}
	printf("\n");
}

void reverseDisplay()
{
	int n = 0,a[10];
	temp = head;
	printf("The reverse display is:\n");
	while(temp!=NULL) //Traversing the linked list 
	{
		a[n] = temp->data;
		temp=temp->next;
		n++;
	}
	for(int i=n-1;i>=0;i--)
	printf("<-%d",a[i]);
	printf("\n");
}

void searching()
{
	int flag = 0,key;
	printf("Enter the key:\n");
	scanf("%d",&key);
	temp = head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			flag = 1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1)
	printf("Key is available\n");
	else
	printf("Key is not availabe\n");	
}

/* 
Concatination of two single linked list 

struct node* concat(struct node* head1,struct node* head2)
{
    temp=head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head2;
    return head1;
}
*/
