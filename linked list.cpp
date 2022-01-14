
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	struct node* prev;
	int num;
	struct node* next;
};

struct node* head=NULL;
struct node* tail=NULL;

void newnode(int n){
	
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->num=n;
	if(head==NULL)
	{
		head=tail=temp;
	}
	else 
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
		
}

int main()
{
	for(int i=0;i<5;i++)
	{
		newnode(i);
	}
	
	struct node* root;
	root=head;
	
	for(int i=0;i<5;i++)
	{	
		cout<<(root->num);
		root=root->next;
		cout<<endl;	
	}
		
	
}
