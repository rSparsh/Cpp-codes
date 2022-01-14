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
 #include<stack>
 #include<cstdlib>
 using namespace std;

 struct Node{
	 int data;
	 struct Node *next;
 };

 struct Node *head=NULL;

 void get_Input(int n)
 {
	struct Node *temp,  *currNode=NULL;
	for(int i=0;i<n;i++)
	{
	temp=(struct Node*)malloc(sizeof(struct Node));
	cin>>temp->data;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=currNode=temp;
	} 
	else
	{
		currNode->next=temp;
		currNode=temp;
	}
	
 }
 }

 void reverseEven()
 {
	 stack <int> st;
	 int count=0, val;
	
	 struct Node *temp, *currNode;
	 temp=head;
	
	while(temp!=NULL){
		if((temp->data)%2==0)
		{	
			currNode=temp;
			while(currNode->data%2==0)
			{	//cout<<"\t"<<currNode->data<<"\t"<<count<<endl;
				st.push(currNode->data);
				currNode=currNode->next;
				count+=1;
				
				if(currNode==NULL)
					break;
			}
			
			for(;count>0;count-=1)
			{
				//cout<<"st"<<st.top()<<endl;
				val=st.top();
				temp->data=val;
				st.pop();
				temp=temp->next;
			}
		}
		else 
		temp=temp->next;
	}
	
 }

void printList()
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

 int main()
 {
	 int n,val;
	 cin>>n;

	get_Input(n);
	reverseEven();
	printList();
 }
