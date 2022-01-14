#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string str="abcdef";
	reverse(str.begin(), str.end()); //include<algorithm> for reverse function
	cout<<str;
}
