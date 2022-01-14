#include<stdio.h>
#include<stdlib.h>

#define MAX 20
char queue[MAX];
int front=-1;
int rear=-1;

void enqueue()
{
	char new_item;
	
	if(rear==MAX-1)
		printf("\nQueue is full.");
	else 
	{
		if(front==-1)
		front+=1;
		
		printf("\nEnter the element to insert: ");
		scanf("%s",&new_item);
		rear+=1;
		queue[rear]=new_item;
	}	
}

void dequeue()
{
	if(front==-1 || front>=rear)
		printf("\nQueue is empty.");
	else
	{
		printf("\nDeleted element is: %c",queue[front]);
		front+=1;
	}
}

void display()
{
	if(front==-1 || front>=rear)
		printf("\nQueue is empty.");
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("\nElement: %c",queue[i]);
		}
	}
}

void exit()
{
	exit(0);
}

int main()
{
	int choice;
	
	do
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:enqueue();break;
			
			case 2:dequeue();break;
			
			case 3:display();break;
			
			case 4:exit();break;
			
			default:printf("Wrong input.");break;
		}
		
	}
	
	while(1);
	
	return 0;
}
