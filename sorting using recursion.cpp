#include<stdio.h>
int sort(int arr[],int size,int min);
main()
{
    int i,size,min_n;
    printf("Enter size of array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter numbers in array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    min_n=sort(arr,size-1,arr[0]);
    printf("The smallest number is %d\n",min_n);
} 
int sort(int arr[],int size,int min_n)
{
 if(size>=0)
 {
  if(arr[size]<min_n)
  {
   min_n=arr[size];
  }
  size--;
  sort(arr,size,min_n);
 }
 else
 {
  return(min_n);
 }
 
}
