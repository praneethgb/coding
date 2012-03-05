#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int cases,no1,no2,a,digits=0,carry=0,sum=0,length=0,prev=0;
	cin>>cases;
	while(cases--)
	{
		cin>>no1>>no2;
		a=no2;
		while(a!=0)
		{
			a/=10;
			digits++;
		}
		int b[digits];
		int c[digits];
		for(int i=0;i<digits;i++)
		{
			b[i]=no2 % 10;
			no2/=10;
			c[i]=b[i]*no1*pow(10,i);
		}/*
		//dsf
		for(int i=0;i<digits;i++)
			cout<<c[i]<<endl;
		//safdf
		*/
		a=c[digits-1];
		while(a!=0)
		{
			a/=10;
			length++;
		}
		int d[digits][length];
		memset(d,0,digits*length*sizeof(int));
		for(int i=0;i<digits;i++)
		{
			for(int j=0;j<length;j++)
			{
				d[i][j]=c[i] % 10;
				c[i]/=10;
			}
		}
		//delete
	/*	
		for(int i=0;i<digits;i++)
		{
			for(int j=0;j<length;j++)
			{
				cout<<d[i][j];
			}
			cout<<endl;
		}
		//dsaf
		*/
		for(int i=0;i<length;i++)
		{
			for(int j=0;j<digits;j++)
			{
				sum+=d[j][i];
			}
			sum+=prev;
			if(sum>=10)
			{
				prev=sum/10; 
				carry++;
			}
			sum=0;
		}
		cout<<carry<<endl;
		carry=0;
		digits=0;
		length=0;
		prev=0;
	}
return 0;
}
