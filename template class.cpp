#include<iostream>
using namespace std;

template<class T,class U>
class student{
	
	T roll;
	U name[20];
	
	public:
	void get();
	void print();

	};

template<class M,class N>
void student<M,N>::get()
{cin>>roll>>name;
}

template<class T,class U>
void student<T,U>::print()
{cout<<roll<<endl<<name;
}

int main()
{
	student<int,char> s1;
	s1.get();
	s1.print();
}
