#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

// #of insertion = #of deletion to make the string palindrome, so same code will be used

//for lcs we need 2 strings, x & y, but in this ques, we only get 1 string as input, then how to apply LCS??
//the other string is obtained as the reverse of the input string, and then we find the lcs on these 2 strings


int dp[100][200];

int lcs(string x, int m, string y, int n)
{
	if(m==0 || n==0)
		return 0;
	
	if(dp[m][n]!=-1)
		return dp[m][n];
	
	if(x[m-1]==y[n-1])
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
	cout<<"Enter the string: \n";
	cin>>x;
	y=x;
	reverse(y.begin(),y.end());
	int m,n;
	m=x.length();
	n=m;
	
	cout<<m-lcs(x,m,y,n);
	
}
