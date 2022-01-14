#include<iostream>
using namespace std;
#include<map>

int main()
{
	map<int,char> findMethod;
	map<int,char>::iterator itr;
	int n[]={1,2,3,4,5};
	char ch[]={'a','b','c','d','e'};
	for(int i=0;i<(sizeof(n)/sizeof(n[0]));i++)
	{
		findMethod.insert({n[i],ch[i]});
	}
	
	/*findMethod.insert({1,'a'});
	findMethod.insert({2,'b'});
	findMethod.insert({3,'c'});
	findMethod.insert({4,'d'});
	findMethod.insert({5,'e'});
	*/
	
	findMethod.insert({6,'f'});
	
	
	for(itr=findMethod.begin();itr!=findMethod.end();itr++)
	{
		cout<<itr->first<<" --> ";
		cout<<itr->second<<"\n";
	}
	
	
}
