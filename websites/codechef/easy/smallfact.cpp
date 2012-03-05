#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int n,t,carry,digit,x,i;
cin>>n;
int b[200];

while(n--)
{
carry=0;digit=1;
cin>>t;

b[0]=1;

for(;t>0;t--)
{
	for(i=0;i<digit;i++)
	{	
		x=b[i]*t;
		b[i]=(x+carry)%100000;
		carry=(x+carry)/100000;
	}
	if(carry!=0)
	{
		b[digit++]=carry;
		carry=0;
	}
}

cout<<b[digit-1];
for(int j=digit-2;j>=0;j--)
	cout<<setw(5)<<setfill('0')<<b[j];
cout<<endl;
}
return 0;
}
