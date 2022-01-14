#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int dp[100][2000];

int findSubset(vector<int> set, int sum, int n)
{	
	if(sum==0)
		return 1;
	if(n<=0)
		return 0;
	
	if(dp[n-1][sum]!= -1)
		return dp[n-1][sum];
	
	else if(set[n-1]<=sum)
	{
		dp[n-1][sum]=(findSubset(set, sum-set[n-1],n-1))|| (findSubset(set, sum, n-1));
		return dp[n-1][sum];
	}
	else
	{
		dp[n-1][sum]=findSubset(set, sum, n-1);
		return dp[n-1][sum];
	}
	
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n, input, sum=0;
	cin>>n;
	vector<int> set;
	for(int i=0;i<n;i++)
	{
		cin>>input;
		set.push_back(input);
		sum+=input;
	}
	
//	cin>>sum;
//    for (int i = 0; i < 1; i++)
//    {
//    	for (int j = 0; j < n+1; j++)
//        {
//        		cout<<dp[j][i]<<endl;
//        }
//        	  
//	}   

	int mn;
	for(int i=0;i<=sum/2;i++)
	{
		if(findSubset(set, i, n))
		{
			mn=sum-(2*i);
		}
	}
	
	cout<<mn;	
}



