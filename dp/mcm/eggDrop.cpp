#include<iostream>
#include<string.h>
using namespace std;

int dp[100][100];

int eggDrop(int e, int f)
{
	if(f==0 || f ==1)
		return f;
	
	if(e==1)
		return f;
	
	if(dp[e][f]!=-1)
		return dp[e][f];
		
	int mn=INT_MAX;
	
	for(int k=1;k<=f;k++)
	{
		int temp=1;
		
		int br, nbr;
		if(dp[e-1][k-1]!=-1)
			br=dp[e-1][k-1];
		else
		{
			br=dp[e-1][k-1]=eggDrop(e-1,k-1);
		}

		
		if(dp[e][f-k]!=-1)
			nbr=dp[e][f-k];
		else
		{
			nbr=dp[e][f-k]=eggDrop(e,f-k);
				}		
		
		temp+=max(br,nbr);
		mn=min(mn,temp);
	}
	
	return dp[e][f]=mn;
	
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int e,f;
	cin>>e>>f;
	cout<<eggDrop(e,f);
}
