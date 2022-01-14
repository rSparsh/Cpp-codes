#include <iostream>
using namespace std;

void int_shift(int n)
{
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int m;
	cin>>m;
	
	int ar1[n];
	for(int k=0;k<n;k++)
	{
		int j=0;
		j=k+m;
		if(j<n)
		ar1[j]=arr[k];
		else
		ar1[j-n]=arr[k];
	}
	
	for(int l=0;l<n;l++)
	{
		cout<<ar1[l]<<endl;
	}
}

void ch_shift(int n)
{
	char arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int m;
	cin>>m;
	
	char ar1[n];
	for(int k=0;k<n;k++)
	{
		int j=0;
		j=k+m;
		if(j<n)
		ar1[j]=arr[k];
		else
		ar1[j-n]=arr[k];
	}
	
	for(int l=0;l<n;l++)
	{
		cout<<ar1[l]<<endl;
	}
}

int main()
{
	int choice;
	int n;
	cin>>choice;
	cin>>n;
	if(choice==0)
	{
	int_shift(n);
	}
	else
	{
	ch_shift(n);
	}
	
}
