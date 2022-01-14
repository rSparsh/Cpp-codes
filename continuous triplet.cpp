#include <stdio.h>

void triplet(int arr[],int n)
{
	int min;
	for(int i=0;i<n-2;i++)
	{
		if (arr[i]<arr[i+1] and arr[i+1]<arr[i+2])
		{
			printf("Triplet is: %d, %d, %d",arr[i],arr[i+1],arr[i+2]);
		}
	}
}

int main()
{
	int n;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the numbers in the array:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	triplet(arr,n);
	
}
