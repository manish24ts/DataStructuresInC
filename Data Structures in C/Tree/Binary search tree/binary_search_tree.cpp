#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left,*right;
	int data;
}*root=NULL,*temp,*current,*n,*res;
int key;

void create();
void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);
struct node* minValueNode(struct node* node);
struct node* deleteNode(struct node* root,int key);
struct node* search(struct node* root,int key);

int main()
{
	int op;
	printf("1.Create\n2.Search\n3.Inorder traversal\n4.Preorder traversal\n5.Postorder traversal \n6.Deletion\n");
	do
	{
		printf("Enter option:\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:create();break;
			case 2:{
				printf("Enter a key:\n");
				scanf("%d",&key);
				res = search(root,key);
				if(res==NULL)
				printf("Not present\n");
				else
				printf("Present at %d \n",res);
				break;
			}
			case 3:inorder(root);break;
			case 4:preorder(root);break;
			case 5:postorder(root);break;
			case 6:{
				printf("Enter a key:\n");
				scanf("%d",&key);
				deleteNode(root,key);
				break;
			}
		}
	}while(op<=6);
}

void create()
{
	n = (struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
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
			if(n->data<temp->data)
			{
				if(temp->left==NULL)
				{
				temp->left = n;
				return;
				}
				temp = temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
				temp->right = n;
				return;
				}
				temp = temp->right;
			}
		}
	}
}
struct node* search(struct node* root,int key)
{
	if(root==NULL || root->data==key)
	return root;
	else
	{
		if(root->data > key)
		return search(root->left,key);
		return search(root->right,key);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
struct node* minValueNode(struct node* node)
{
	struct node *current=node;
	while(current && current->left != NULL)
	current = current->left;
	return current;
}
struct node* deleteNode(struct node* root,int key)
{
	if(root==NULL)
	return root;
	if(key<root->data)
	root->left=deleteNode(root->left,key);
	else if(key>root->data)
	root->right=deleteNode(root->right,key);
	else
	{
		if(root->left == NULL && root->right==NULL)
		return NULL;
		else if(root->left==NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		temp = minValueNode(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
	return root;
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


