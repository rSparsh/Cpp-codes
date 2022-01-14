#include<iostream>
#include<iomanip>
using namespace std;

double area(float len, float bre)
{
	return (len*bre);	
 }

double area(float top, float bottom, float height)
{
	return (height*(top+bottom)/2);
}

double area(float radius)
{
	return (3.14*radius*radius);
}

  
int main()
{
	float len,bre,top,bottom,height,radius;
	double a;
	cin>>len>>bre;
	a = area(len,bre);
	cout<<fixed<<setprecision(2)<<a<<endl;
	cin>>top>>bottom>>height;
	a = area(top,bottom,height);
	cout<<fixed<<setprecision(2)<<a<<endl;
	cin>>radius;
	a = area(radius);
	cout<<fixed<<setprecision(2)<<a<<endl;
}
