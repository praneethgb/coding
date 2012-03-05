#include <stdio.h>

int main()
{
int n;
scanf("%d",&n);
while(n--)
{
	int a,count=0;
	scanf("%d",&a);
	while(a!=0)
	{
	a=a/2;
	count++;
	}
	printf("%d\n",1<<(count-1));
}
return 0;
}
