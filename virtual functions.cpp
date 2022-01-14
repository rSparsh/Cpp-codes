#include<iostream>
using namespace std;

class shape{
	
	public:
	int x;
	int y;
	
		void input()
		{
			cin>>x>>y;
		}
		
		virtual void area()
		{
			cout<<"\n\nPerimeter of rectangle is: "<<x*y<<endl;
		}
};

class triangle:public shape{
	public:
	void area()
	{
		double ar=(double)(x*y)/2;
		cout<<"\nPerimeter of triangle is: "<<ar<<endl;
	}
};


int main()
{
	shape *shp, rect;
	triangle tri;
	
	shp=&rect;
	shp->input();
	shp->area();
	
	shp=&tri;
	shp->input();
	shp->area();
}
