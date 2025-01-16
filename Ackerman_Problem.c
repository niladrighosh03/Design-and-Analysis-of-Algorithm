#include<stdio.h>
int akr(int m, int n)
{
	if(m==0)
		return n+1;
	else if(n==0)	
		return akr(m-1,1);
	else
		return akr(m-1,akr(m,n-1));	
}

int main()
{
	int m,n;
	printf("Enter m,n respectively ");
	scanf("%d%d",&m,&n);
	printf("The akerman function is %d",akr(m,n));
}
