#include <stdio>
int temp;

inline void swap(int& a,int& b)
{
	temp=a;
	a=b;
	b=temp;

}
int main()
{
	int T,a,b,ans=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&a,&b);
		if(a<b)
			swap(a,b);
		while(a%b
