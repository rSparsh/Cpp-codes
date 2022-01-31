#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

unordered_map <string, int> dp;

bool scrambled(string a, string b)
{
	if(a.compare(b)==0)
		return true;
		
	if(a.length()<=1)
		return false;
		
	string key=a+" "+b;
	if(dp.find(key)!=dp.end())
		return dp[key];
	
	for(int k=1;k<a.length();k++)
	{
		if(scrambled(a.substr(0,k),b.substr(a.length()-k,k)) && scrambled(a.substr(k,a.length()-k),b.substr(0,a.length()-k)))
			return dp[key]=1;
		else if(scrambled(a.substr(0,k),b.substr(0,k)) && scrambled(a.substr(k,a.length()-k),b.substr(k,a.length()-k)))
			return dp[key]=1;
	}
	
	return dp[key]=0;
}   



int main()
{
	string a, b;
	cin>>a>>b;
	
	if(a.length()!=b.length())
		cout<<"Invalid input.";
	else if(a.compare(b)==0)
		cout<<"Yes, the input strings are scrambled.";
	else if(scrambled(a,b)==1)
			cout<<"Yes, the input strings are scrambled.";
		
		else
			cout<<"No, the input strings are not scrambled.";
		
		
}
