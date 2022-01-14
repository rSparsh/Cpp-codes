#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node *head1=NULL, *head2=NULL;

void input(int n1,int n2)
{	
	struct Node *temp,*newnode, *head=NULL;
	int n=n1;
	for(int j=0;j<2;j++)
	{
	for(int i=0;i<n;i++)
	{
		newnode=(struct Node*)malloc(sizeof(struct Node));
		newnode->prev=NULL;
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newnode;
		}
		
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		
	}
		
			if(j==0)
			{
				head1=head;
			}
			if(j==1)
			{
				head2=head;
			}
	n=n2;
	head=NULL;
	
}
}

void intersection()
{	struct Node *temp1,*temp2;
	temp1=head1;
	temp2=head2;
	int count=0;
	
	while(temp1!=NULL)
	{
		while(temp2!=NULL)
		{
			if(temp1->data==temp2->data)
			{
				count+=1;
				break;
			}
			temp2=temp2->next;
		}
		
		temp1=temp1->next;
		temp2=head2;
	}

	if(count==0)
		printf("yes");
	else
		printf("no");
}

int main()
{
	int n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);
	
	input(n1,n2);
	intersection();	
	
}
