#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d, ", root->key); 
		inorder(root->right); 
	} 
} 

void postorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     postorder(node->left); 
     postorder(node->right); 
     printf("%d, ", node->key); 
} 
  
void preorder(struct node* node) 
{ 
     if (node == NULL) 
	    return; 
  	printf("%d ", node->key);   
  	preorder(node->left);   
    preorder(node->right); 
}
     
struct node* insert(struct node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	return node; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) 
		return root; 
    
	if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
}
 
int height(struct node *node)
{
	if(node == NULL)
		return 0;
	else
	{
		int left_side;
		int right_side;
		left_side = height(node -> left);
		right_side = height(node -> right);
		if(left_side > right_side)
		{
			return left_side + 1;
			}
		else
			return right_side + 1;
	}
}

int depth(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       int lDepth = depth(node->left); 
       int rDepth = depth(node->right); 
  
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  

bool ancestors(struct node *root, int node)
{
    if (root == NULL)
        return false;

    if (root->key == node)
        return true;
    bool left = ancestors(root->left, node);
    bool right = false;
    if (!left)
        right = ancestors(root->right, node);
    if (left || right)
        printf("--> %d",root->key);
    return left || right;
}

void descendants(struct node *root, int node)
{
	if(root->key==node)
	{
		inorder(root);
		return;
		}	
	if(root->key>node)
	{	root=root->left;
		descendants(root,node);
		inorder(root);
		return;
		}
		
	if(root->key<node)
	{	root=root->right;
		descendants(root,node);
		inorder(root);
		return;
		}
		
}

int main() 
{ 
	struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 10); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 
	printf("The BST is:(Inorder) ");
	inorder(root); 
	
	int choice;
	while(1)
	{
	printf("\n\n1.Insert an element.\n2.Delete a node.\n3.Find the height of BST.\n4.Find the depth of BST.\n5.Find the ancestors of a node.\n6.Find the descendants of a node.\n7.Inorder traversal.\n8.Preorder Traversal.\n9.Postorder traversal.\nEnter the operation no.: ");
	scanf("%d",&choice);
	int n;
	switch(choice)
	{
		case 1:
			printf("Enter the element to insert: ");
			scanf("%d",&n);
			insert(root,n);
			printf("The BST is:(Inorder) ");
			inorder(root);
			break;
			
		case 2:
			printf("Enter the element to insert: ");
			scanf("%d",&n);
			deleteNode(root,n);
			printf("The BST is:(Inorder) ");
			inorder(root);
			break;
			
		case 3:
			printf("The height of the BST is: %d.",height(root));
			break;
		
		case 4:
			printf("The depth of the BST is: %d.",depth(root));
			break;
			
		case 5:
			printf("Enter the node to check the ancestors: ");
			scanf("%d",&n);
			printf("The ancestors of %d: ",n);
			ancestors(root,n);
			break;	
			
		case 6:
			printf("Enter the node to check the descendants: ");
			scanf("%d",&n);
			printf("The descendants of %d (inorder): ",n);
			descendants(root,n);
			break;
				
		case 7:
			printf("The inorder traversal: ");
			inorder(root);
			break;
		
		case 8:
			printf("The preorder traversal: ");
			preorder(root);
			break;
			
		case 9:
			printf("The postorder traversal: ");
			postorder(root);
			break;
		
		default:
			printf("Improper input.");
			exit(0);
								
			
		}	
}
	return 0; 
} 

