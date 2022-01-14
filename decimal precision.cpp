#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float n;
	cin>>n;
	n=(n/3);
	cout<<fixed<<setprecision(8)<<n; //setprecision(x) x=number of digits after after decimal.
}
