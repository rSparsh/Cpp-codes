#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>

void print(vector<T> vect)
{
	for(int i=0;i<5;i++)
	{
		cout<<vect[i]<<" ";
	}
	cout<<endl;
}

template<class T>

vector<T> change(vector<T> vect)
{
	for(int i=0;i<vect.size();i++)
		vect[i]+=1;
	return vect;
}

int main()
{
	vector<string> vect1;
	vector<int> vect2, vect;
	vector<char> vect3;
	
	for(int i=0;i<5;i++)
		vect.push_back(i+1);
	
	for(int i=0;i<5;i++)
		vect1.push_back("ab");
	for(int i=0;i<5;i++)
		vect2.push_back('a');
		
	for(int i=0;i<5;i++)
		vect3.push_back('a');	
	
	cout<<"Calling print function: "<<endl;
	print(vect1);
	print(vect2);
	print(vect3);
	
	cout<<"Calling change function: "<<endl;
	vect2=change(vect2);
	print(vect2);
	
	cout<<"Begin: "<<*vect.begin()<<endl;
	cout<<"rBegin: "<<*vect.rbegin()<<endl;
	cout<<"Size: "<<vect.size()<<endl;
	cout<<"Empty: "<<vect.empty()<<endl;
	cout<<"At: "<<vect1.at(2)<<endl; //used as "[]" reference operator
	cout<<"Front: "<<vect.front()<<endl;
	cout<<"Back: "<<vect.back()<<endl;
	
		
}
