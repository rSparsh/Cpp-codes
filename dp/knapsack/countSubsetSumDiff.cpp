#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


//S1 + S2 = Sum
//S1 - S2 = Diff
//=> S1 = (Sum+Diff)/2
//So, we need to change the countSubsetSum accordingly for S1 = (Sum+Diff)/2


int dp[100][2000];

int countSubsetSum(vector<int> set, int sum, int n)
{	
	if(sum==0)
		return 1;
	if(n<=0)
		return 0;
	
	if(dp[n][sum]!=-1)
		return dp[n-1][sum];
	
	else if(set[n-1]<=sum)
	{
		dp[n-1][sum]=(countSubsetSum(set, sum-set[n-1],n-1))+ (countSubsetSum(set, sum, n-1));
		return dp[n-1][sum];
	}
	else if(set[n-1]>sum)
	{
		dp[n-1][sum]=countSubsetSum(set, sum, n-1);
		return dp[n-1][sum];
	}
	
}

int main()
{
	memset(dp, -1, sizeof(dp)); //include <string.h>
	int n, input, sum=0;
	cin>>n;
	vector<int> set;
	for(int i=0;i<n;i++)
	{
		cin>>input;
		set.push_back(input);
		sum+=input;
	}
	
	int diff;
	cin>>diff;

    for (int i = 0; i < 1; i++)
    {
    	for (int j = 0; j < n+1; j++)
        {
        		dp[j][i] =1;
        }
        	  
	}   
	
	for (int i = 0; i < 1; i++)
    {
    	for (int j = 0; j < n+1; j++)
        {
        		dp[i][j] =0;
        }
        	  
	}   
	
	
	cout<<countSubsetSum(set, (sum+diff)/2, n);
	
}


