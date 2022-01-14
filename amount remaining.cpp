#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bCustomers{
	char name[50];
	int accountNumber;
	float balance;
};

struct mCustomers{
	char name[50];
	int nItems;
	char itemName[10][50];
	float cost[10];
};

int main()
{
	int n,m,i,j;
	int SherleyBIndex=-1;
	int SherleyMIndex=-1;
	int SherleyItem;
	scanf("%d",&n);
	struct bCustomers bCustomers[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",bCustomers[i].name);
		if(strcmp(bCustomers[i].name,"Sherley")==0)
		{
			SherleyBIndex=i;
		}
		scanf("%d",&bCustomers[i].accountNumber);
		scanf("%f",&bCustomers[i].balance);
	}
	
	scanf("%d",&m);
	struct mCustomers mCustomers[m];
	for(i=0;i<m;i++)
	{
		scanf("%s",mCustomers[i].name);
		if(strcmp(mCustomers[i].name,"Sherley")==0)
		{
			SherleyMIndex=i;
		}
		
		scanf("%d",&mCustomers[i].nItems);
		for(j=0;j<mCustomers[i].nItems;j++)
		{
			scanf("%s",mCustomers[i].itemName[j]);
			scanf("%f",&mCustomers[i].cost[j]);
			if(i==SherleyMIndex)
			{
				SherleyItem=mCustomers[i].nItems;
				bCustomers[SherleyBIndex].balance=bCustomers[SherleyBIndex].balance-mCustomers[i].cost[j];
			}
			
		}
	}
	
	for(int i=0;i<=SherleyItem;i++)
	{
		printf("%s",mCustomers[SherleyMIndex].itemName[i]);
		if(i<SherleyItem)
		printf("\n");
	}
		printf("%.2f",bCustomers[SherleyBIndex].balance);
	
	
}
