#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

Node *newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

bool isSymmetric(struct Node* root) 
{ 
	if(root == NULL) 
		return true; 
	
	if(!root->left && !root->right) 
		return true; 
	
	queue <Node*> q; 
	
	q.push(root); 
	q.push(root); 
	Node* leftNode, *rightNode; 
	
	while(!q.empty()){ 
		leftNode = q.front(); 
		q.pop(); 
		
		rightNode = q.front(); 
		q.pop(); 
		if(leftNode->key != rightNode->key){ 
		return false; 
		} 
		
		if(leftNode->left && rightNode->right){ 
			q.push(leftNode->left); 
			q.push(rightNode->right); 
		} 
		else if (leftNode->left || rightNode->right) 
		return false; 
		if(leftNode->right && rightNode->left){ 
			q.push(leftNode->right); 
			q.push(rightNode->left); 
		} 
		
		else if(leftNode->right || rightNode->left) 
		return false; 
	} 
	
	return true; 
} 

void inorder(struct Node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d, ", root->key); 
		inorder(root->right); 
	} 
}

int main() 
{ 
	Node *root = newNode(3); 
	root->left = newNode(2); 
	root->right = newNode(2); 
	root->left->left = newNode(5); 
	root->left->right = newNode(4); 
	root->right->left = newNode(4); 
	root->right->right = newNode(5); 
	root->left->right->left=newNode(1);
	root->left->right->right=newNode(2);
	root->right->left->left=newNode(2);
	root->right->left->right=newNode(1);
	
	cout<<"Binary tree(inorder): ";
	inorder(root);
	if(isSymmetric(root)) 
		cout << "\n\nThe given tree is Symmetric."; 
	else
		cout << "\n\nThe given tree is Asymmetric."; 
	return 0; 
} 


