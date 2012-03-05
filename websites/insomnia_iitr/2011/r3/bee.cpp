#include <iostream>
using namespace std;


long totalcombs(int n, int r){
	long c=1;
	if (r > n) return 0;
	for (long d=1; d <= r; d++) {
		c *= n--;
		c /= d;
	}
	return c;
}

int main()
{
	int T,n,ans=0,one;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			one=n-1-2*i;
			cout<<"x1 is "<<one<<endl;
			cout<<"x2 is "<<i<<endl;
			cout<<"no. of combinations are "<<totalcombs(i+one,one)<<endl;
			if(one<0)
				break;
			ans+=totalcombs(i+one,one);//one+1 C two else two+1 C one
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
