#include<iostream>
#include<string.h>
using namespace std;

int dp[100][200];

int lcs(string x, int m, string y, int n)
{
	if(m==0 || n==0)
		return 0;
	
	if(dp[m][n]!=-1)
		return dp[m][n];
	
	if(x[m-1]==y[n-1] && m!=n)
	{
		return dp[m][n]=1+lcs(x,m-1, y, n-1);
	}
	else{
		return dp[m][n]=max(lcs(x,m-1,y,n),lcs(x,m,y, n-1));
	}
}


int main()
{
	memset(dp, -1, sizeof(dp));
	string x, y;
	cout<<"Enter the strings: \n";
	cin>>x;
	int m,n;
	y=x;
	m=x.length();
	n=m;
	
	cout<<lcs(x,m,y,n);
	
}
