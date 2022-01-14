/*
Given an nXn matrix with entries as numbers, write an algorithm and C program to print the maximum value in each row of the matrix.
*/

#include<iostream>
using namespace std;

void max_print(int m,int n,int matrix[][n])
{
	int max=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{	
			max=matrix[i][0];
			if(matrix[i][j]>max)
				max=matrix[i][j];
		} 
		cout<<"Max element in row"<<i<<"is: "<<max<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	int matrix[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}
	
	int m=n;
	max_print(m,n,matrix);
}
