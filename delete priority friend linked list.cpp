/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<iostream>
#include<cstdlib>
using namespace std;

struct list{
	struct list* prev;
	int priority;
	struct list* next;
};

struct list *head=NULL;

void print_List(){
	struct list *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->priority<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void delete_Friends(int n_Friend, int n_Delete)
{
	struct list *temp, *currNode=NULL;
	for(int i=0;i<n_Friend;i++)
	{
		temp=(struct list*)malloc(sizeof(struct list));
		temp->prev=NULL;
		cin>>temp->priority;
		temp->next=NULL;

		if(head==NULL)
		{
			head=currNode=temp;
		}
		else{
			currNode->next=temp;
			temp->prev=currNode;
			currNode=temp;
		}
	}
	
	int count=0;
	temp=head;
		
	while(temp->next!=NULL)
		{	
		if(count!=n_Delete)
		{
			if(temp->priority<temp->next->priority)
			{
				if(temp==head)
					{
					//cout<<"head";
					temp->next->prev=NULL;
					head=head->next;
					temp=head;
					count+=1;
					continue;
					}
				else{
					
					//cout<<"else";
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					temp=head;
					count+=1;
					continue;
					}
			}
			else{
				temp=temp->next;
				}
			}
			else
			break;
		}
		
		if(count==0)
			{
			temp->prev->next=NULL;
			temp->prev=NULL;
			}
		print_List();
		head=NULL;
}

int main()
{
	int n_Test, n_Friend, n_Delete;
	cin>>n_Test;
	for(int i=0;i<n_Test;i++)
	{
		cin>>n_Friend>>n_Delete;
		delete_Friends(n_Friend, n_Delete);
	}
}
