#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char array[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	
	for(int i=(n-1);i>=0;i--)
	{
		cout<<"\n"<<array[i];
	}
	
}
