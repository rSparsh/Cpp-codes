#include<stdio.h>
#include<stdlib.h>

#define MAX 5
char queue[MAX];
int front=-1;
int rear=-1;

void enQueue()
{
	char new_item;
	if((front==0 && rear==MAX-1)||(front==rear+1))
		printf("\nQueue overflown.");
	else
	{
		if(rear==MAX-1)
			rear=-1;
			
		printf("\nEnter the element to insert: ");
		scanf("%s",&new_item);
		rear+=1;
		queue[rear]=new_item;
		
		if(front==-1)
			front+=1;
	}
}

void deQueue()
{
	if(front==-1)
	{
		printf("\nQueue underflown.");
		return;
		}	
	 
	printf("\nDeleted element: %c",queue[front]);
			
	if(rear==front) //queue has single element only
	{ 	
		front=-1;
	 	rear=-1;
	}
	else
	{
	if(front == MAX-1)
		front = 0;
	else
		front = front+1;
	}
		 		
}

void disp()
{
	if(front==-1)
	{
		printf("\nQueue underflown.");
		return;
		}	
	
	if(rear>=front)
		{
			for(int i=front;i<=rear;i++)
				printf("\nElement: %c",queue[i]);
		}
	else
		{
			for(int i=front;i<MAX;i++)
				printf("\nElement: %c",queue[i]);
				
			for(int i=0;i<=rear;i++)
				printf("\nElement: %c",queue[i]);
		}	
}

int main()
{
	int choice;
	
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enQueue();break;
			
			case 2:deQueue();break;
			
			case 3:disp();break;
			
			case 4:exit(0);break;
			
			default:
				printf("\nWrong Input.");break;
		}
	}
	return 0;
}
