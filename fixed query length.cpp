#include<iostream>
#include<limits>
using namespace std;

void find_Min(int num[], int n_Num, int query);

int main()
{
	int n_Num, n_Query, query;
	cout<<"Enter the array count: ";
	cin>>n_Num;
	cout<<"Enter the query count: ";
	cin>>n_Query;
	int num[n_Num]; //query[n_Query];
	
	cout<<"Enter the array input: \n";
	for(int i=1;i<=n_Num;i++)
		cin>>num[i];
	
	cout<<"Enter the query input: \n";
	for(int i=1;i<=n_Query;i++)
	{
			cin>>query;
		
	find_Min(num, n_Num, query);
}
}

void find_Min(int num[], int n_Num, int query){
	int min, max=0, count=0;
	
		min=std::numeric_limits<int>::max();
	
		for(int j=1;j<=n_Num;j++)
		{
			count+=1;
			if(num[j]>max)
				max=num[j];
			if(count==query)
			{
				count=0;
				if(min>max)
				{
					min=max;
				}
				max=0;
			}
		}
		cout<<"\nFor "<<query<<": "<<min<<endl;
	
}
