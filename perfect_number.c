#include<stdio.h>
int horner(int num)
{
	int i,k=1,sum=0;
	int count[100];
	for(i=1;i<=num/2;i++)
	{
		if(num%i==0)
		{
			count[k++]=i;
		}
	}
	printf("\nDivisors are:-\n");
	for(i=1;i<k;i++)
	{
		printf("%-5d",count[i]);
		sum+=count[i];
	}
	if(sum==num)
		//printf("\nPerfect Number");
		return 1;
	else
		//printf("\nNot Perfect Number");
		return 0;	
}
int main()
{
	int n,f;
	printf("Enter a number ");
	scanf("%d",&n);
	f=horner(n);
	if(f==1)
	printf("\nPerfect Number");
	else
	printf("\nNot Perfect Number");
	//horner(n);
	
}
