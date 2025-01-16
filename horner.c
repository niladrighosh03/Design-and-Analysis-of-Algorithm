#include<stdio.h>
int hor(int a[],int n, int num)
{
	int i,r=a[0];
	for(i=1;i<n;i++)
		r=r*num + a[i];
	return r;	
}
int main()
{
	int n;
	int a[]={3,6,-1};
	int f=hor(a,3,2);
	printf("\nResult %d",f);
	
}
