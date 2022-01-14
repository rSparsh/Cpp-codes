#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char delimiter[n];
	char ch;
	cin>>ch;
	int i=0;
	while(ch!='\0')
	{		
				
		if(ch=='(' || ch=='{' || ch=='[')
		{
			delimiter[i]=ch;
			i++;
		}
		
		else if(ch==')' && delimiter[i-1]=='(')
		{
			
			delimiter[i-1]='\0';
			i=i-2;			
		}
		
		else if(ch==']' && delimiter[i-1]=='[')
		{
			delimiter[i-1]='\0';
			i=i-2;			
		}
		
		else if(ch=='}' && delimiter[i-1]=='{')
		{
			delimiter[i-1]='\0';
			i=i-2;			
		}
		
		cin>>ch;
		
		
	}
	
	
	if(delimiter[0]=='\0')
		cout<<"Balanced Delimiter.";
	else
		cout<<"Unbalanced Delimiter.";
}
