#include "stdio.h"

long long nCr(int n, int r)
{
	long long j, ans=1;
	if(r>n/2)
	{
		r=n-r;
	}
	for(j=0;j<r;j++)
	{
		ans*=(n-j);
		ans/=j+1;
	}
	return ans;
}

int main()
{
	int T,n,r;
	scanf("%d\n",&T);
	while(T--)
	{
		scanf("%d %d\n",&n,&r);
		printf("%lld\n",nCr(n-1,r-1));
	}
	return 0;
}
