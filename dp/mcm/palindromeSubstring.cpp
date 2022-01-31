#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[100][100];


bool isPalindrome(string str, int i, int j)
{
	if(i==j)
		return true;
		
	if(i>=j)
		return false;
	
	while(j>=i)
	{
		if(str[i]==str[j])
		{
			i+=1;
			j-=1;
			continue;
		}
		else
			return false;
	}
	return true;
}

int pSs(string str, int i, int j)
{
	if(i>=j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];
				
	if(isPalindrome(str,i,j))
		return 0;

	int mn=INT_MAX;
	for(int k=i;k<j;k++)
	{
		int left, right;
		if(dp[i][k]!=-1)
			left=dp[i][k];
		else
			left=pSs(str,i,k);

		if(dp[k+1][j]!=-1)
			right=dp[k+1][j];
		else
			right=pSs(str,k+1,j);
			
		int temp=1+ left+ right; 
		mn = min(temp,mn);
	}
	
	return dp[i][j]=mn;
}

int main()
{
	string str;
	cin>>str;
	
	memset(dp,-1,sizeof(dp));
	cout<<pSs(str,0,str.length()-1);
}
