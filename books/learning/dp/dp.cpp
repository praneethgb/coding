#include <iostream>
using namespace std;
int calls=0;
const int MAX=100001;
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
	{
		if(arr[a]==0) //0th index goes waste
			arr[a]=fib(a-1)+fib(a-2);
		return arr[a];
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
