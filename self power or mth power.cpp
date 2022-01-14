/*Given two number ‘n’ and ‘m’, write a C++ function to find Sum. Where Sum = 1m+2m+3m+...+nm, when m > 0 and Sum = 11+22+33+...+nn when m = 0.

For example, when n = 5 and m = 3, Sum = 13+23+33+43+53 = 225 and when n = 5 and when m = 0, Sum = 11+22+33+44+55 = 3413
*/

#include<iostream>
using namespace std;
#include<math.h>
long int sum_pow(int n, int m=0)
{
	int sum=0;
	if(m=0)
	{
		for(int i=0;i<=n;i++)
		{
			sum+=(pow(i,i));
		}
		}	
	else
	{
		for(int i=0;i<=n;i++)
		{
			sum+=(pow(i,n));
		}
		}
		
		return sum;
	}
	


int main()
{	
	long int sum,n,m;
	cin>>n>>m;
	if(m<0)
	cout<<"Invalid input";
	else
	{
	if(m!=0)
	sum=sum_pow(n, m);
	else
	sum=sum_pow(n);
	cout<<sum;
	}
}
