/*Given a set of 'n' elements in an order, identify all the leaders and print them. An element is said to be a leader if all the elements to its right are smaller than it.
For example, if the elements are 12, 13, 16, 7, 10 then there is only one leader element 16. If there are no leaders in the given set of elements then print 'No leaders'.
*/

#include<iostream>
using namespace std;

void leader(int series[5],int n);

int main()
{
	int n;
	cin>>n;
	int series[n];
	
	for(int i=0;i<n;i++)
		cin>>series[i];
	
	leader(series,n);
}

void leader(int series[5],int n)
{
	int leader;
	
	cout<<"Leader elements are: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(series[i]<series[j])
				break;	
			
			if(j=(n-1))
				cout<<series[i]<<endl;			
		}
		
	}
}
