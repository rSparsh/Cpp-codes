#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[]={4,8,2,5,7,1,0,3};
	sort(a,a+8);
	for(int i=0;i<8;i++)
	{
		cout<<a[i];
	}
}
