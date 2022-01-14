#include <bits/stdc++.h> 
using namespace std; 

class node { 
public: 
	int data; 
	node* next; 
}; 

node* merge(node* temp1, node* temp2) 
{ 
	node* Node= NULL; 

	if (temp1 == NULL) 
		return (temp2); 
	else if (temp2 == NULL) 
		return (temp1); 
	
	if (temp1->data <= temp2->data) { 
		Node = temp1; 
		Node->next = merge(temp1->next, temp2); 
	} 
	else { 
		Node = temp2; 
		Node->next = merge(temp1, temp2->next); 
	} 
	return Node; 
} 

void split(node* source, node** front, node** back) 
{ 
	node* ptr1; 
	node* ptr2; 
	ptr2 = source; 
	ptr1 = source->next; 

	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 

	*front = source; 
	*back = ptr2->next; 
	ptr2->next = NULL; 
} 

void mergesort(node** temp_head) 
{ 
	node* head = *temp_head; 
	node* temp1; 
	node* temp2; 

	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 
	split(head, &temp1, &temp2); 
	mergesort(&temp1); 
	mergesort(&temp2); 
	*temp_head = merge(temp1, temp2); 
} 


void print(node* head) 
{ 
	while (head != NULL) { 
		cout << head->data << " "; 
		head = head->next; 
	} 
} 

void push(node** head, int data) 
{ 
	node* new_node = new node(); 
	new_node->data = data; 
	new_node->next = (*head); 
	(*head) = new_node; 
} 

int main() 
{ 
  	
  	int n,element;
  	cout<<"Enter the list size: ";
  	cin>>n;
	node*  Node= NULL; 
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the element"<<i+1<<": ";
		cin>>element;
		push(&Node,element);
	}


	mergesort(&Node); 

	cout << "Sorted Linked List: "; 
	print(Node); 

	return 0; 
}
