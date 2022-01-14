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
	int  w, input;
	vector<int> val, wt;
	
	//here the wt vector is same as the length array and it will have value for each rod length from 1 to w
	cin>>w;
	
	for(int i=0;i<w;i++)
	{
		cout<<"Enter value for length "<<i+1<<": ";
		cin>>input;
		val.push_back(input);
		wt.push_back(i+1);
	}
	
	
	
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=w;j++)
			arr[i][j]=-1;
	}
	

	
	cout<<solve(val, wt, w);
}
