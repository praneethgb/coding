#include <iostream>
#include <string>
using namespace std;

long long fib(long long a)
{
	long long b=1,c=1;
	if(a==1||a==2)
		return 1;
	else if(a<1)
		return 0;
	else
	{
		for(long long i=0;i<a-2;i++) //Iterative method
		{
		b+=c;
		c=b-c;
		}
		return b;
	}
}

int main()
{
long long n,T;
cin>>T;
string fib1[8]={"12200160415121876738","19740274219868223167","31940434634990099905","51680708854858323072","83621143489848422977","135301852344706746049","218922995834555169026","354224848179261915075"};
while(T--)
{
	cin>>n;
	if(n<93)
		cout<<fib(n)<<endl;
	else
		cout<<fib1[n-93]<<endl;		
}
return 0;
}
