
#include<iostream>
using namespace std;
#include<map>

struct input{
	int n;
	char ch;
};

int main()
{
	map<char,int> map1; //map definition
	map<char,int>::iterator itr;  //iterator definition in map
	
	int n[]={1,2,3,4,5};
	char ch[]={'a','b','c','d','e'};

	for(int i=0;i<(sizeof(n)/sizeof(n[0]));i++) //input to map from arrays
	{
		map1.insert({ch[i],n[i]});
	}
	
	/*map1.insert({1,'a'});  //common input method to map
	map1.insert({2,'b'});
	map1.insert({3,'c'});
	map1.insert({4,'d'});
	map1.insert({5,'e'});
	*/
	
	
	
	cout<<"Printing the map1"<<endl;
	for(itr=map1.begin();itr!=map1.end();itr++)  //printing the map
	{
		cout<<"Key="<<itr->first<<"\n";
		cout<<"Value: "<<itr->second<<"\n";
	}
	
	cout<<"\nUsing find()"<<endl;
	itr=map1.find('a');  //map.find(), if there is no  match for the argument then returns 0
	cout<<itr->second<<endl;
	
	cout<<"\nUsing at()"<<endl;
	if(map1.at('o'))
		cout<<map1.at('o');
//	for(int i=1;i<8;i++)  //map.at()
//	{
//		cout<<map1.at(i)<<"\n";
//	}
//	
//	map<char, int> map2; //using struct with maps
//	struct input in[8];
//	for(int i=0;i<8;i++)
//	{
//		in[i].n=(i+101);
//		in[i].ch=(char)(i+65);
//		map2.insert({in[i].ch,in[i].n});
//	}
//
///*	map2.insert({101,'A'}); 
//	map2.insert({102,'B'});
//	map2.insert({103,'C'});
//	map2.insert({104,'D'});
//	map2.insert({105,'E'});
//	map2.insert({106,'F'});
//	map2.insert({107,'G'});
//	map2.insert({108,'H'});
//*/
//	
//	cout<<"\nPrinting the map2 before swap"<<endl;
//	for(itr=map2.begin();itr!=map2.end();itr++)  //printing the map
//	{
//		cout<<"Key="<<itr->first<<"\n";
//		cout<<"Value: "<<itr->second<<"\n";
//	}
//	
//	map1.swap(map2); //swap(), only map type should be same, size may be different
//	//swap(map1,map2);//swap() definition2
//	
//	cout<<"\nPrinting the map1 after swap()"<<endl;
//	for(itr=map1.begin();itr!=map1.end();itr++)  //printing the map1 after swap()
//	{
//		cout<<"Key="<<itr->first<<"\n";
//		cout<<"Value: "<<itr->second<<"\n";
//	}
//	
//	cout<<"\nPrinting the map2 after swap"<<endl;
//	for(itr=map2.begin();itr!=map2.end();itr++)  //printing the map2 after swap()
//	{
//		cout<<"Key="<<itr->first<<"\n";
//		cout<<"Value: "<<itr->second<<"\n";
//	}
//	
//	
}
