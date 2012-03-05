#include <stdio.h>

main()
{
	int T,A,B,C,maxcount,count,temp,prev;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&A,&B,&C);
		maxcount=count=0;
		prev=100*A+B;
		while(count<10000 && (100*A+B>C))
		{
			if(B<C)
			{
				A--;
				B+=100;
			}
			B-=C;
			temp=A;
			A=B;
			B=temp;
			count++;
			if(100*A+B>prev)
			{
				prev=100*A+B;
				maxcount=count;
			}
		}
		printf("%d\n",maxcount);
	}
}
