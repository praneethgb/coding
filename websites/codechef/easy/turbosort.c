#include<stdio.h>
#include<iostream>
using namespace std;

void radsort(int*,int);

int main()
{
	int no;
	int i1[1000001]={0};
	scanf("%d",&no);
	radsort(i1,no);
	return 0;
}

void radsort(int* aux,int pies)
{
	int n;
	register int j,k,i;
	for(j=0;j<pies;j++)
		{
		scanf("%d",&n);
		aux[n]++;
		}
	for(k=0;k<1000001;k++)
	{
		for(i=1;i<=aux[k];i++)
		{
			printf("%d\n",k);
		}
	}

}
