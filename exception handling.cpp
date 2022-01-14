#include<iostream>
#include<iomanip>
using namespace std;

double div(double a, double b)
{
	if(b==0)
	{
		throw "Error! Division By Zero.";
	}
	else{
		return a/b;
	}
}

int main()
{
	double a, b;
	cin>>a>>b;
	
	try{
		double z = div(a,b);
		cout<<fixed<<setprecision(3)<<z<<endl;
	}
	
	catch(const char* err){
		cout<<err<<endl;
	}
}
