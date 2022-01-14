#include<iostream>
using namespace std;

class area{

	private:
	int length;
	int breadth;
	
	public:
		void input()
		{
			cin>>length	>>breadth;
		}
	friend void calcArea(area A);
	
};


void calcArea(area A){
	
	A.input();
	cout<<A.length*A.breadth;
}

int main()
{
	area A;
	//A.input();
	calcArea(A);
}
