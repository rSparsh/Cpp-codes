#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

bool dp[100][2000];

bool equalSubsetSum(vector<int> set, int sum, int n)
{	
	if(sum==0)
		return true;
	if(n<=0)
		return false;
	
	if(dp[n][sum]!='\0')
		return dp[n][sum];
	
	if(set[n]<=sum)
	{
		dp[n][sum]=(equalSubsetSum(set, sum-set[n],n-1))|| (equalSubsetSum(set, sum, n-1));
		return dp[n][sum];
	}
	else if(set[n]>sum)
	{
		dp[n][sum]=equalSubsetSum(set, sum, n-1);
		return dp[n][sum];
	}
	
}

int main()
{
	memset(dp, false, sizeof(dp)); //include <string.h>
	int n, input;
	cin>>n;
	vector<int> set;
	for(int i=0;i<n;i++)
	{
		cin>>input;
		set.push_back(input);
	}
	

    for (int i = 0; i < 1; i++)
    {
    	for (int j = 0; j < n+1; j++)
        {
        		dp[j][i] =true;
        }
        	  
	}   
	
	long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=set[i];
	}
	
	if(sum%2==0)
		cout<<equalSubsetSum(set, sum/2, n-1);
	else
		cout<<false;	
}



