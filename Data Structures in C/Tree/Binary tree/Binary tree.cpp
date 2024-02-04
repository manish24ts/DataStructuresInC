#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
}*temp,*root=NULL,*n;
void create();
void inoreder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int main()
{
	int ch;
	printf("1.create\n2.inorder\n3.preorder\n4.postorder\n5.Exit\n");
	do
	{
		printf("Enter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();break;
			case 2:inoreder(root);break;
			case 3:preorder(root);break;
			case 4:postorder(root);break;
			case 5:printf("Exiting process... \n");exit(1);
		}
	}while(ch<=5);
	return 0;
}
void create()
{
	int op;
	n = (struct node*)malloc(sizeof(struct node));
	printf("Enter data value:\n");
	scanf("%d",&n->data);
	n->left=NULL;
	n->right=NULL;
	if(root==NULL)
	root = n;
	else
	{
		temp = root;
		while(temp!=NULL)
		{
			printf("1.left\n2.right\n");
			printf("Enter your option:\n");
			scanf("%d",&op);
			if(op==1)
			{
				if(temp->left==NULL)
				{
					temp->left=n;
					return;
				}
				else
				  temp=temp->left;
			}
			if(op==2)
			{
				if(temp->right==NULL)
				{
					temp->right=n;
					return;
				}
				else
				  temp=temp->right;
			}
		}
	}
}
void inoreder(struct node *root)
{
	if(root!=NULL)
	{
		inoreder(root->left);
		printf("%d ",root->data);
		inoreder(root->right);
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}	
}
