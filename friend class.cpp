#include<iostream>
using namespace std;

class A{
	private:
		int length=10;
		int breadth=3;
		friend class B;
		void area();
};

class B{
	public:
	void area(A &a)
	{ 
	cout<<a.length*a.breadth;
	}
};

int main()
{
	A a;
	B b;
	b.area(a);
	
}
