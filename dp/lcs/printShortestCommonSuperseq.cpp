#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

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


string findlcs(string x, int m, string y, int n)
{
	string str;
	while(m>0 && n>0)	
	{
		if(x[m-1]==y[n-1])
	{
		//cout<<x[m-1]<<endl;
		str.push_back(x[m-1]);
		m-=1;
		n-=1;
		
	}
	
	else{
		
		
		if(dp[m-1][n]>dp[m][n-1])
		{
			str.push_back(x[m-1]);
			m-=1;
		}
		else
		{
			str.push_back(y[n-1]);
			n-=1;
		}
	}
	
	}
	
	while(m>0)
	{
		str.push_back(x[m-1]);
		m-=1;		
	}
	
	while(n>0)
	{
		str.push_back(y[n-1]);
		n-=1;		
	}
	
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	string x, y;
	cout<<"Enter the strings: \n";
	cin>>x>>y;
	int m,n;
	m=x.length();
	n=y.length();
	
	cout<<lcs(x,m,y,n)<<endl; 
	cout<<findlcs(x,m,y,n);
}
