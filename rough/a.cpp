#include <iostream>
using namespace std;

int lg(int);
int twopr(int);

int main()
{
	int in,d,p,flag=0;
	cin>>in;
	d=lg(in+1);
	p=twopr(d);
	while(d!=0)
	{
		for(int i=0;i<d/2;i++)
		{
			if((in+1)%p==i)
				flag=1;
			else
				flag=0;
			if(flag==1)
				cout<<5;break;
		}
		if(flag==0) cout<<6;
		d--;
	}
	return 0;
}

int lg(int a)
{
	int k=0;
	while(a>1)
	{a=a/2;k++;}
	return k;
}

int twopr(int b)
{
	int k=1;
	for(;b>0;b--)
	{
		k*=2;
	}
	return k;
}
