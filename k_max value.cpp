#include <stdio.h>

void swap(int *a, int *b) 
{ 
int temp = *a; 
*a = *b; 
*b = temp; 
}   

void k_max(int array[], int n,int k) 
{ 
int i, j, min_element; 
for (i = 0; i < n-1; i++) 
{
min_element = i; 
for (j = i+1; j < n; j++) 
if (array[j] < array[min_element]) 
min_element = j; 
swap(&array[min_element], &array[i]); 
} 

printf("%d",array[n-k]);
}  

int main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the number in the array: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
		
	int k;
	printf("Enter the value of k: ");
	scanf("%d",&k);
	k_max(arr,n,k);
	
}
