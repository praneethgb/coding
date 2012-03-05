#include <iostream>
using namespace std;

int fib(int n)
{
//	cout<<n<<endl;
	if (n<=1)
		return n;
	else
		return fib(n-1)+fib(n-2);
}

int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}
