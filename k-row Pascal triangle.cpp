#include <iostream>
#include <vector>
using namespace std;

vector<int> kRow(int A)
{
	vector <int> res;

	long long num = 1;
	res.push_back(num);
	for(int i=1;i<=A;i++)
	{
		num*= (A-i+1);
		num /= i;
		res.push_back(num);
	}
	
	return res;
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> row;
	row=kRow(n);
	for(int i=0;i<row.size();i++)
	{
		cout<<row[i]<<",";
	}
	
	return 0;
}
