#include<iostream>
#include<cstdlib>
using namespace std;
 
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
int part(int arr[], int low, int high)
{
	int pivot=high, index=low;
	
	for(int i=low; i < high; i++)
	{
		if(arr[i] < arr[pivot])
		{
			swap(&arr[i], &arr[index]);
			index++;
		}
	}
	swap(&arr[pivot], &arr[index]);
 
	return index;
}
 
int pivot_partition(int arr[], int low, int high)
{
	int pivot, n, temp;
	n = rand();
	pivot = low + n%(high-low+1);
 
	swap(&arr[high], &arr[pivot]);
 
	return part(arr, low, high);
}
 
int quicksort(int arr[], int low, int high)
{
	int pivot_index;
	if(low < high)
	{
		pivot_index = pivot_partition(arr, low, high);
		quicksort(arr, low, pivot_index-1);
		quicksort(arr, pivot_index+1, high);
	}
	return 0;
}
 
void max(int arr[], int n) 
{ 
	int max = arr[0]; 
	int i; 
	for (i=1; i <= n; i++) 
	{ 
    	if (arr[i] > max) 
        	max = i; 
		else
        	break; 
	} 
	swap(&arr[max],&arr[n]);
} 

void median(int arr[],int n)
{
	int med=n/2;
	swap(&arr[med],&arr[n]);
}

int main()
{
	int n, i;
	cout<<"\nEnter the array size: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
	
	cout<<"\nSelect from the options below:\n1.Choose the first element as the pivot.\n2.Choose the maximum element as the pivot.\n3.Choose the last element as the pivot.\n4.Choose the median index of the array as the pivot.\n5.Choose a random element as pivot.\n\nEnter the choice number: ";
	int choice,random;
	cin>>choice;
	switch(choice)
	{
		case 1:
			swap(&arr[0],&arr[n-1]);
			cout<<"Pivot="<<arr[n-1];
			quicksort(arr, 0, n-1);break;
		case 2:
			max(arr,n);
			cout<<"Pivot="<<arr[n-1];
			quicksort(arr, 0, n-1);break;
		case 3:
			cout<<"Pivot="<<arr[n-1];
			quicksort(arr, 0, n-1);break;
		case 4:
			median(arr,n-1);
			cout<<"Pivot="<<arr[n-1];
			quicksort(arr, 0, n-1);break;
		case 5:
			cout<<"Enter the random index position";
			cin>>random;
			swap(&arr[random],&arr[n-1]);
			cout<<"Pivot="<<arr[n-1];
			quicksort(arr,0,n-1);break;
		
		default:printf("Wrong input.");
	} 
 	cout<<"\nSorted Array: ";
	for (i = 0; i < n; i++)
        	cout<<arr[i]<<", ";
 
	return 0;
}
