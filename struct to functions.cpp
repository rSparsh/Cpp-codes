//the program checks whether the entered item details are valid or not and if not, then whetehr its available in the stock
//passing struct to function 

#include<iostream>
using namespace std;

struct itemDetail
{
	int itemCode;
	double cost;
	int stock;
};


/*void input(itemDetail *detail,int n)
{
		for(int i=0;i<n;i++)
	{
		cin>>detail[i].itemCode;
		cin>>detail[i].cost;
		cin>>detail[i].stock;
	}

}
*/

void check(itemDetail *detail,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>detail[i].itemCode;
		cin>>detail[i].cost;
		cin>>detail[i].stock;
	}
	
	int itemCode;
	double cost;
	cin>>itemCode;
	cin>>cost;
	
	
	int j=1;
	for(int i=0;i<n;i++)
	{
		try{
		
		j+=1;
		if(detail[i].itemCode==itemCode)
			if(detail[i].stock!=0)
				if(detail[i].cost<cost)
					cout<<detail[i].itemCode;
					
				else
					throw 1.0;
					
			else
				throw "error";
		else
			if(j==n)
				throw 1;
		}
		catch(double a)
		{
			cout<<"\nInsufficient amount."<<endl;
		}
		catch(string b)
		{
			cout<<"\nLess stock."<<endl;
		}
		catch(int c)
		{
			cout<<"\nInvalid code."<<endl;
		}
	}
}


int main()
{
	int n;
	cin>>n;
	itemDetail detail;
	
	
	check(&detail,n);
	//input(&detail,n);
	//check(&detail,n,userItemCode,userCost);
	
}
