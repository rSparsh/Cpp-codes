#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

struct Node* newNode(int value)
{
	Node* n = new Node;
	n->key = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct Node* insertValue(struct Node* root, int value,
						queue<Node *>& q)
{
	Node* node = newNode(value);
	if (root == NULL)
		root = node;


	else if (q.front()->left == NULL)
		q.front()->left = node;

	
	else {
		q.front()->right = node;
		q.pop();
	}


	q.push(node);
	return root;
}


Node* createTree(int arr[], int n)
{
	Node* root = NULL;
	queue<Node*> q;
	for (int i = 0; i < n; i++)
	root = insertValue(root, arr[i], q);
	return root;
}


void levelOrder(struct Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> n;
	n.push(root);
	while (!n.empty()) {
		cout << n.front()->key << "--> ";
		if (n.front()->left != NULL)
			n.push(n.front()->left);
		if (n.front()->right != NULL)
			n.push(n.front()->right);
		n.pop();
	}
}

int maxPathSum(struct Node* root, int& res)
{
	if(root==NULL)
		return 0;
	
	int l=maxPathSum(root->left,res);
	int r=maxPathSum(root->right,res);
	
	int temp=max(max(l,r)+root->key,root->key);
	int ans=max(temp,l+r+root->key);
	res=max(ans,res);
	
	return temp;
}


// Driver code
int main()
{
//	int n;
//	cin>>n;
//	int arr[n];
//	for(int i=0;i<n;i++)
//		cin>>arr[i];
//		
//	Node* root = createTree(arr, n);
//	levelOrder(root);

struct Node *root = newNode(10);
	root->left	 = newNode(2);
	root->right	 = newNode(10);
	root->left->left = newNode(20);
	root->left->right = newNode(1);
	root->right->right = newNode(-25);
	root->right->right->left = newNode(3);
	root->right->right->right = newNode(4);	
	
	levelOrder(root);
	int res=INT_MIN;
	maxPathSum(root,res);
	cout<<"\n"<<res ;
	
	
	return 0;
}

