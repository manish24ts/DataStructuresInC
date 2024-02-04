/*
 * AVL Tree Program in C
 */
 
#include<stdio.h>
#include<stdlib.h>
 
// structure of the tree node
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int ht;
}*n;
 
// global initialization of root node
struct node* root = NULL;
 
// function prototyping
struct node* create(int);
struct node* insert(struct node*, int);
struct node* delet(struct node*, int);
struct node* search(struct node*, int);
struct node* rotate_left(struct node*);
struct node* rotate_right(struct node*);
int balance_factor(struct node*);
int height(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
 
int main()
{
    int ch, data;
    struct node* result = NULL;
        printf("\n\n------- AVL TREE --------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder");
        printf("\n5. Preorder");
        printf("\n6. Postorder");
        printf("\n7. EXIT");
   do
    {
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &ch);
        
         switch(ch)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
 
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = delet(root, data);
                break;
 
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL)
                {
                    printf("\nNode not found!");
                }
                else
                {
                    printf("\n Node found");
                }
                break;
            case 4:
                inorder(root);
                break;
 
            case 5:
                preorder(root);
                break;
 
            case 6:
                postorder(root);
                break;
 
            }
 
    }while(ch<=6);
 
    return 0;
}
 

// rotates to the left
struct node* rotate_left(struct node* root)
{
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
 
    // update the heights of the nodes
    root->ht = height(root);
    right_child->ht = height(right_child);
 
    // return the new node after rotation
    return right_child;
}
 
// rotates to the right
struct node* rotate_right(struct node* root)
{
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
 
    // update the heights of the nodes
    root->ht = height(root);
    left_child->ht = height(left_child);
 
    // return the new node after rotation
    return left_child;
}
 
// calculates the balance factor of a node
int balance_factor(struct node* root)
{
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
 
// calculate the height of the node
int height(struct node* root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
 
    if (lh > rh)
        return (lh);
    return (rh);
}
 // creates a new tree node
struct node* create(int data)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
 
    // if a memory error has occurred
    if (n == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

 
// inserts a new node in the AVL tree
struct node* insert(struct node* root, int data)
{
      if (root == NULL)
    {
        struct node* n = create(data);
        if (n == NULL)
        {
            return NULL;
        }
        root = n;
    }
    
    else if (data > root->data)
    {
        // insert the new node to the right
        root->right = insert(root->right, data);
 
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == -2)
        {
            if (data > root->right->data)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        // insert the new node to the left
        root->left = insert(root->left, data);
 
        // tree is unbalanced, then rotate it
        if (balance_factor(root) == 2)
        {
            if (data < root->left->data)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    // update the heights of the nodes
    root->ht = height(root);
    return root;
}
 
// deletes a node from the AVL tree
struct node * delet(struct node *root, int x)
{
    struct node * temp = NULL;
 
    if (root == NULL)
    {
        return NULL;
    }
 
    if (x > root->data)
    {
        root->right = delet(root->right, x);
        if (balance_factor(root) == 2)
        {
            if (balance_factor(root->left) >= 0)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    else if (x < root->data)
    {
        root->left = delet(root->left, x);
        if (balance_factor(root) == -2)
        {
            if (balance_factor(root->right) <= 0)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        {
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
 
            root->data = temp->data;
            root->right = delet(root->right, temp->data);
            if (balance_factor(root) == 2)
            {
                if (balance_factor(root->left) >= 0)
                {
                    root = rotate_right(root);
                }
                else
                {
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        }
        else
        {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}
 
// search a node in the AVL tree
struct node* search(struct node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
 
    // Key is greater than root's key
    if (key>root->data )
        return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
 
// inorder traversal of the tree
void inorder(struct node* root)
{
    if (root!= NULL)
    {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    }
}
 
// preorder traversal of the tree
void preorder(struct node* root)
{
    if (root!= NULL)
    {
        printf("%d ", root->data);
       preorder(root->left);
       preorder(root->right);
    }
}
 
// postorder traversal of the tree
void postorder(struct node* root)
{
    if (root != NULL)
    {
     postorder(root->left);
     postorder(root->right);
     printf("%d ", root->data);
    }
}



