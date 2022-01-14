/*In geometry, a Heronian triangle is a triangle that has side lengths and area that are all integers. Heronian triangles are named after Hero of Alexandria. Design a class to represent a triangle and provide functions to calculate perimeter of triangle, area of triangle and a function to check if the given triangle is Heronian triangle.

Boundary Conditions

Sides a,b,c are integers and the values are given such that they can be sides of a triangle

Note:

Given sides of the triangle a,b and c, area of the triangle, S is calculated as:

 


 

Print only two decimal places when the area is not an integer and print only integral part when decimal part of area is zero.
*/

#include<iostream>
using namespace std;
#include<iomanip>
#include<math.h>

class triangle
{	
	int a;
	int b;
	int c;
	double area;
	int perimeter;
	public:
	//function to read data members of class
	void read();
	//function to calculate area
	void compute_area();
	//function to calculate perimeter
	void compute_perimeter();
	//function to check if the triangle is Heronian
	bool is_Heronian();
	//function to print perimeter of triangle
	void print_perimeter();
	//function to print area of triangle
	void print_area();
	
};


void triangle::read()
{
	cin>>a;
	cin>>b;
	cin>>c;
}

void triangle::compute_perimeter()
{
	perimeter=a+b+c;
}

void triangle::print_perimeter()
{
	cout<<perimeter<<endl;
}

void triangle::compute_area()
{
	double s;
	s=perimeter/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
}

void triangle::print_area()
{
	cout<<fixed<<setprecision(2)<<area<<endl;
}

bool triangle::is_Heronian()
{
	return area==perimeter; 
}

int main()
{
	triangle t;
	t.read();
	t.compute_perimeter();
	t.print_perimeter();
	t.compute_area();	
	t.print_area();
	if(t.is_Heronian())
	cout<<"Yes";
	else
	cout<<"No";
}



