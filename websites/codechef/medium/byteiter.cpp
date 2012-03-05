#include<iostream>
#include<fstream>
using namespace std;

long total(int&);
long s;

int main()
{
	int no;
	cin>>no;
	while(!feof(stdin))
	{
	cout<<total(no)<<endl;
	cin>>no;
	}
	return 0;
}

long total(int& n)
{
int nby2=n/2;
int nby3=n/3;
int nby4=n/4;
if(nby2+nby3+nby4<=n)
	return n;
else
{
	s=total(nby2)+total(nby3)+total(nby4);
	return s;
}
}
