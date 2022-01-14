#include<iostream>
#include<vector>
using namespace std;

int arr[1000][1000];

int knapsack(vector<int> &A, vector<int> &B, int C, int i)
{	
    if(i<0 || C==0)
        return 0;

    if(arr[i][C]!=-1)
        {
        	
            return arr[i][C];
        }

    if( B[i]>C)
       {
           arr[i][C]=knapsack(A,B,C ,i-1);
           return arr[i][C];
       }
    else{
        arr[i][C]= max(A[i]+knapsack(A,B,C-B[i],i),knapsack(A,B,C,i-1)) ;
        return arr[i][C];
    }
        
}

int solve(vector<int> &A, vector<int> &B, int C) {
    return knapsack(A, B, C, A.size()-1);
}

int main()
{
	int n, w, input;
	cin>>n;
	vector<int> val, wt;
	for(int i=0;i<n;i++)
	{
		cin>>input;
		val.push_back(input);
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>input;
		wt.push_back(input);
	}
	
	cin>>w;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
			arr[i][j]=-1;
	}
	

	
	cout<<solve(val, wt, w);
}
