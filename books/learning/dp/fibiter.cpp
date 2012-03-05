#include <iostream>
using namespace std;
int calls=0;

int fib(int a)
{
	calls++;
	int b=1,c=1;
	if(a==1||a==2)
		return 1;
	else if(a<1)
		return 0;
	else
	{
		for(int i=0;i<a-2;i++) //Iterative method
		{
		b+=c;
		c=b-c;
		}
		return b;
	}
}

int main()
{
int n;
cin>>n;
cout<<"Fib: "<<fib(n)<<endl;
cout<<"No. of calls: "<<calls<<endl;
return 0;
}
