#include<iostream>
#include<fstream>
#include<map>
using namespace std;

long long total(long long&);
long long s;
map <long long,long long> yo;

int main()
{
	long long no;
	cin>>no;
	while(!feof(stdin))
	{
	cout<<total(no)<<endl;
	yo.clear();
	cin>>no;
	}
	return 0;
}

long long total(long long& n)
{
long long nby2=n/2;
long long nby3=n/3;
long long nby4=n/4;
if(nby2+nby3+nby4<=n)
	return n;
else
{
	if(!yo.count(n))
		yo[n]=total(nby2)+total(nby3)+total(nby4);
		//s=total(nby2)+total(nby3)+total(nby4);
	return yo[n];//s;
}
}
