#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data)
		{
			this->data=data;
		}
};

class LinkedList{
	public: 
	Node *head;
	
	void addNode(int data){
		Node *temp=new Node(data);
		if(head=NULL)
			head=temp;
		else{
			Node *currNode=head;
			while(currNode->next!=NULL)
				currNode=currNode->next;
			currNode->next=temp;
		}
	}
	
	void print_List()
	{
		Node *temp=head;
		while(temp->next!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
		}
};


int main()
{
	cout<<"Start";
	LinkedList num;
	int n, data;
	cin>>n;
	for(int i=0;i<5;i++)
	{
		cin>>data;
		num.addNode(i);
	}
	
	num.print_List();
}
