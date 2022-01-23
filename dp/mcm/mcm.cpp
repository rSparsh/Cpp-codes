#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int dp[50][50];

int mcm(vector<int> matrix,int i, int j)
{
	if(i>=j)
	{
		return 0;
	}
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	int min=INT_MAX;
	
	for(int k=i;k<j;k++)
	{
		int temp=mcm(matrix,i,k)+mcm(matrix,k+1,j)+(matrix[i-1]*matrix[k]*matrix[j]);
		
		if(temp<min)
			min=temp;
	}
	
	return dp[i][j]=min;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n,input;
	cout<<"Enter the number of matrices: ";
	cin>>n;
	vector<int> matrix;
	
	for(int i=0;i<=n;i++)
	{
		cin>>input;
		matrix.push_back(input);
	}
	
	cout<<mcm(matrix,1,n);
}
