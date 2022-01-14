#include<stdio.h>
#include<stdlib.h>

#define MAX 20
char stack[MAX];
int top=-1;

void push()
{
	char new_item;
	
	if(top==MAX-1)
		printf("\nStack is full.");
	else 
	{
		printf("\nEnter the element to insert: ");
		scanf("%s",&new_item);
		top+=1;
		stack[top]=new_item;
		
	}	
}

void pop()
{
	if(top==-1)
		printf("\nStack is empty.");
	else
	{
		printf("\nDeleted element is: %c",stack[top]);
		top-=1;
	}
}

void display()
{
	if(top==-1)
		printf("\nStack is empty.");
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf("\nElement: %c",stack[i]);
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
			case 1:push();break;
			
			case 2:pop();break;
			
			case 3:display();break;
			
			case 4:exit();break;
			
			default:printf("Wrong input.");break;
		}
		
	}
	
	while(1);
	
	return 0;
}
