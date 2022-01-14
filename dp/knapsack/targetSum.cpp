#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

// it is same as a+b-c-d+... =0, let the +ve numbers be in S1 and the -ve in S2, here it is S1-S2=0 (same as subsetSumDiff) => sum = sum/2

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
	


	if(findSubset(set, sum/2, n))
	{
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
}



