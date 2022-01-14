#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};

class LinkedList{
	public: 
	Node *head;
	
	LinkedList(){
		this->head=NULL;
	}
	
	void addNode(int data){
		Node *temp=new Node(data);
		if(!this->head)
			this->head=temp;
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
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
		}
};


int main()
{
	LinkedList* num=new LinkedList();
	int n, data;
	cin>>n;
	for(int i=0;i<5;i++)
	{
		cin>>data;
		num->addNode(data);
	}
	
	num->print_List();
}
