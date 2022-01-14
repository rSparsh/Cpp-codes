#include<iostream>
using namespace std;

template<class T>
void bubbleSort(T a[], int n) { 
	for (int i = 0; i < n - 1; i++) 
		for (int j = n - 1; i < j; j--) 
			if (a[j] < a[j - 1]) 
			swap(a[j], a[j - 1]); 
}

template<class T>
void print(T a[],int n)
{
	for(int i=0;i<n;i++)
	{cout<<a[i]<<endl;
	}
}

int  main()
{int a[5]={1,3,5,7,2};
char b[6]={'f','t','a','w','b','l'};
bubbleSort(a,5);
print(a,5);
bubbleSort(b,6);
print(b,6);

}
