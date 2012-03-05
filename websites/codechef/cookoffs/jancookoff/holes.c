#include <stdio.h>

int main()
{
	int n,count=0;
	char c;
	scanf("%d\n",&n);
	while(n--)
	{
		do{
		c=getchar();
		if(c=='B')
			count=count+2;
		else if(c=='A'||c=='D'||c=='O'||c=='P'||c=='Q'||c=='R')
			count=count+1;
		else if(c!='\n');
		}while(c!='\n');
		printf("%d\n",count);
		count=0;
	}
return 0;
}
