#include<iostream>
#include<cstring>
using namespace std;


/////////////////////////
////ALWAYS END THE STRING WITH '\0'
/////////////////////////



int main()
{
	string s;
	getline(cin,s);
	cout<<s<<"\t"<<s.length()<<endl;
	
	char c[]="John"; //for this the null character is not counted
	cout<<"strlen: "<<strlen(c)<<"\tsizeof: "<<sizeof(c)<<endl;
	
	char c1[]={'a','p','p','l','e','\0'}; //for this the null character is counted
	cout<<"strlen: "<<strlen(c1)<<"\tsizeof: "<<sizeof(c1)<<endl;
	
	char c2[]={"Mango"};
	cout<<c2;
}
