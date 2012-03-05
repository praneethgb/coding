// http://www.spoj.pl/problems/FCTRL/
#include <iostream>
using namespace std;

int power(int a)
{
int b=1;
for(int i=1;i<=a;i++)
	b*=5;
return b;
}

int main()
{
int test,copy,count,help,i;
int* tes;
cin>>test;
tes= new int[test];
for(i=0;i<test;i++)
{
count=0;
cin>>tes[i];
copy=tes[i];
int j=1;
while(copy>1)
{
help=tes[i]/power(j);
count+=help;
copy/=5;
j++;
}
cout<<count<<endl;
}
return 0;
}
