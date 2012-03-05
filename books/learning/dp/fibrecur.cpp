#include <iostream>
using namespace std;
int calls=0;
const int MAX=1000001;
int arr[MAX]={0};

int fib(int a)
{

	calls++;
	int b=1,c=1;
	if(a==1||a==2)
		return 1;
	else if(a<1)
		return 0;
	else
		return fib(a-1)+fib(a-2);
}

int main()
{
int n;
cin>>n;
cout<<"Fib: "<<fib(n)<<endl;
cout<<"No. of calls: "<<calls<<endl;
return 0;
}
