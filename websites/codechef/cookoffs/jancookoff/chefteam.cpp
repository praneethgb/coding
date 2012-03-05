#include <iostream>
using namespace std;

int main()
{
int cases;
long n,k;
long result;
cin>>cases;
while(cases--)
{
	cin>>n>>k;
	if(k>n/2)
		k=n-k;
	result=1;
	for(int i=1;i<=k;i++)
	{
		result*=(n-i+1);
		result/=i;
	}
	cout<<result<<endl;
}
return 0;
}
