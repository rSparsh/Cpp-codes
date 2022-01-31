#include<iostream>
#include<string.h>
using namespace std;

int dp[100][100][2];

int evalExp(string exp, int i, int j, int isTrue){
	
	if(i>j)
		return false;
	
	if(i==j)
	{
		if(isTrue==1)
			return dp[i][j][1]=exp[i]=='1';
		else	
			return dp[i][j][0]=exp[i]=='0';
	}
	
	if(dp[i][j][isTrue]!=-1)
		return dp[i][j][isTrue];
	
	int ans=0;
	for(int k=i+1;k<j;k+=2)
	{
		int lt=evalExp(exp,i,k-1,1);
		int lf=evalExp(exp,i,k-1,0);
		int rt=evalExp(exp,k+1,j,1);
		int rf=evalExp(exp,k+1,j,0);
		
		if(exp[k]=='&')
		{
			if(isTrue==1)
				ans+=(lt*rt);
			else
				ans+=(lf*rf)+(lt*rf)+(lf*rt);
		}
		else if(exp[k]=='|')
		{
			if(isTrue==1)
				ans+=(lt*rf)+(lf*rt)+(lt*rt);
			else
				ans+=(lf*rf);
		}
		else
		{
			if(isTrue==1)
				ans+=(lt*rf)+(lf*rt);
			else
				ans+=(lt*rt)+(lf*rf);
		}
	}
	
	return dp[i][j][isTrue]=ans;
}

int main(){
	string exp;
	cout<<"Enter the expression as a combination of 'T-->1' or 'F-->0' and symbols of '&' or '|' or '^' : ";
	cin>>exp;
	cout<<"\n\nThe number of ways of evaluating the input to the given output are: "<<evalExp(exp,0,exp.length()-1,1)<<endl;
	
}
