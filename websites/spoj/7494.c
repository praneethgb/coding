#include "stdio.h"
int main()
{
	int a,b,c,next;
	while(1)
	{
		scanf("%d %d %d\n",&a,&b,&c);
		if(a==0 && b==0 && c==0)
			break;
		if(a+c==2*b)
		{
			next=2*c-b;
			printf("%s %d\n","AP",next);
		}
		else
		{
			next=c*c/b;
			printf("%s %d\n","GP",next);
		}
	}
    return 0;
}
