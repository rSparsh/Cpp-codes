#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	string a="adfd";
	int n=a.length();
	char c[n];
	strcpy(c,a.c_str());
	
	for(int i=0;i<n;i++)
		cout<<c[i]<<endl;
	
}
