// if list: 1,2,3,4,5,6,7,8,9,10 and rotate by 4 elements then list: 9,10,5,6,7,8,1,2,3,4
#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
}; 

struct node *head,*tail;

void input(int n)
{
	struct node *newnode,*temp;
	head=NULL;
	for(int i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->prev=NULL;
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
	}
	tail=temp;
}

void rotate(int count,int k)
{
	struct node *temp_tail,*temp1,*temp2;
	int n=count/k;//	printf("%d",n);
	int s1=count%k;	//printf("%d",s1);
	temp1=tail;
	
	while(s1!=0)
	{
		//printf("%d",temp1->data);
		temp1=temp1->prev;
		s1-=1;
	}
	temp2=temp1;
	temp_tail=temp1->next;
		//printf("%d",temp_tail->data);	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<k;j++)
		{	
			temp1=temp1->prev;
			//printf("\nd=%d",temp1->data);
			
		}
		//	printf("%d",temp1->data);
		if(temp1->prev!=NULL)
		{
			temp1->prev->next=temp2->next;
			temp2->next->prev=temp1->prev;
			temp1->prev=tail;
			tail->next=temp1;
			temp2->next=NULL;
			tail=temp2;
			temp1=temp_tail->prev;
			temp2=temp_tail->prev;
			
		}
		else{
			temp1->prev=tail;
			tail->next=temp1;
			temp2->next=NULL;
			temp_tail->prev=NULL;
			head=temp_tail;
			tail=temp2;
		}
	}
	
}

void print()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main()
{
	int n,k;
	scanf("%d",&n);
	input(n);
	scanf("%d",&k);
	rotate(n,k);
	print();
}
