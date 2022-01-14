
#include <iostream> 
#include<stack>
using namespace std; 

struct Queue { 
	stack<char> s1, s2;  
	void enQueue(char x) 
	{  
		s1.push(x); 
	} 	 
	char deQueue() 
	{ 
		
		if (s1.empty() && s2.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		}  
		if (s2.empty()) { 
			while (!s1.empty()) { 
				s2.push(s1.top()); 
				s1.pop(); 
			} 
		} 
		char x = s2.top(); 
		s2.pop(); 
		return x; 
	} 
}; 


int main() 
{ 	int n;
	cin>>n;
	Queue q;
	char ch;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		q.enQueue(ch);
	 } 
	 
	 for(int i=0;i<n;i++)
	{
		cout << q.deQueue() << '\n';
	 }  
	return 0; 
} 

