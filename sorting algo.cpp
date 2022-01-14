#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////////////////
//insertion sort
vector<int> insertionSort(vector<int> A){
	int temp, key;
	for(int i=1;i<A.size();i++)
	{	key=i;
		for(int j=i-1;j>=0;j--)
		{
			if(A[key]<A[j])
			{
				temp=A[j];
				A[j]=A[key];
				A[key]=temp;
				key=j;
			}
		}
		}	
	return A;
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//merge sort

vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         } 
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}
vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;
 
   vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);
 
   return result;
}

///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//quicksort

int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void quickSort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		quickSort(v,start,p-1);
		quickSort(v,p+1,end);
	}
	
}

////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//selection sort

void selectionSort(vector<int> &vect)
{
	for(int i=0;i<vect.size();i++)
	{	
		int min=i; //4,6,9,2,8
		for(int j=i+1;j<vect.size();j++)
		{
			if(vect[j]<vect[min])
			{
				min=j;
			}
		}
		
		if(min!=i)
		{
			vect[i]=vect[i]+vect[min];
			vect[min]=vect[i]-vect[min];
			vect[i]=vect[i]-vect[min];
		}
			
	}
}
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//bubble sort

void bubbleSort(vector<int> &vect)
{
	for(int i=0;i<vect.size()-1;i++)
	{
		for(int j=0;j<vect.size()-1-i;j++)
		{
			if(vect[j]>vect[j+1])
			{
				vect[j]+=vect[j+1];
				vect[j+1]=vect[j]-vect[j+1];
				vect[j]=vect[j]-vect[j+1];
			}
		}
	}
}

////////////////////////////////////////////////////////////

int main()
{
	int n, input;
	cout<<"Enter the number of inputs: ";
	cin>>n;
	
	vector<int> num, sorted;
	cout<<"Enter the values: ";
	for(int i=0;i<n;i++)
	{
		cin>>input;
		num.push_back(input);
	}
	
	sorted=insertionSort(num);
	cout<<"\nInsertion sort: ";
	for(int i=0;i<sorted.size();i++)
	{
		cout<<sorted[i]<<" ";
	}
	
	sorted=mergeSort(num);
	cout<<"\nMerge sort: ";
	for(int i=0;i<sorted.size();i++)
	{
		cout<<sorted[i]<<" ";
	}
	
	sorted=num;
	quickSort(sorted, 0, sorted.size()-1);
	cout<<"\nQuick Sort: ";
	for(int i=0;i<sorted.size();i++)
	{
		cout<<sorted[i]<<" ";
	}

	sorted=num;
	selectionSort(sorted);
	cout<<"\nSelection Sort: ";
	for(int i=0;i<sorted.size();i++)
	{
		cout<<sorted[i]<<" ";
	}

	sorted=num;
	bubbleSort(sorted);
	cout<<"\nBubble Sort: ";
	for(int i=0;i<sorted.size();i++)
	{
		cout<<sorted[i]<<" ";
	}
	return 0;
}


