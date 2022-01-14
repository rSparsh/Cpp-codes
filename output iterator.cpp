#include<iostream>
using namespace std;
#include<vector>

template<class T>
void print(T arr[30],int n)
{
std::vector<T> vect(arr,arr+n);

vector<int>::iterator ptr;
for(ptr=vect.begin();ptr<vect.end();ptr++)
{	
	*ptr+=3;
	cout<<*ptr<<endl;
}
	
}

int main()
{
	int ar1[]={1,2,3,4,5,6};
	char ar2[]={'a','s','d','f'};
	
	print(ar1,6);
	//print(ar2,4);
}

