#include <cstdio>
//#include<iostream>
//using namespace std;

int temp;
inline void swap(int& a,int& b)
{
	temp=a;
	a=b;
	b=temp;
}


int main()
{
	int T,a,b,ans=0,final,quot;
	scanf("%d",&T);
//	T=1000000000;
	while(T--)
	{
//		if(T==999999999)
			scanf("%d %d",&a,&b);
//		cout<<"scanned"<<endl;
		if(a<b)
			swap(a,b);
		while(a%b!=0)
		{
//			cout<<"in"<<endl;
			quot=a/b;
			ans+=quot;
			a-=quot*b;
//			if(a<b) always
			swap(a,b);
//			if(a%b==0)
//				break;
//			quot=b/a;
//			ans+=quot;
//			b-=quot*a;

//			cout<<"__________________"<<endl<<"a is"<<a<<endl<<"b is"<<b<<endl<<"___________";
		}
		ans+=(a/b);
		if(ans%2==0)
			printf("2\n");
		else
			printf("1\n");
		ans=0;
	}
	return 0;
}
