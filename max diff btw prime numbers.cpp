#include <stdio.h>

int prime()
{
	int  count;
	int prime_list[20];
	int p=-1;
	for(int num=1;num<100;num++)
  {
    count = 0;
    for (int i=2; i <= num/2; i++)
    {
  	if(num%i == 0)
  	{
     	  count++;
  	  break;
	}
    }
    if(count == 0 && num != 1 )
    {
	 p+=1;
    }  
    prime_list[p]=num;
}
	return prime_list[];
}

void max_diff(int prime_list,int n)
{
	int diff=0;
	for(int i=0;i<n;i++)
	{
		if (((prime_list[i+1])-(prime_list[i]))>diff)
			diff=((prime_list[i+1])-(prime_list[i]));
	}
	
	printf("Max difference between 2 consecutive prime number is: %d", diff);
}

int main()
{
  int prime_list[]=prime();
  max_diff(prime_list,sizeof(prime_list/prime_list[0]));
  return 0;
}
