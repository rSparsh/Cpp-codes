#include<iostream>
using namespace std;
#include<stack>

stack <int> st;

void insertSt()
{
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	//return st;
}

int main()
{
	//stack <int> st;
	
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
	
	insertSt();
	for(int i=0;i<4;i++)
	{
		printf("\n%d",st.top());
		st.pop();
	}
}
