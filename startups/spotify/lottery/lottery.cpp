#include <iostream>
#include <cstdio>
using namespace std;

long double nCr(long double n, long double r)
{
    if(n<0||r<0||n<r)
        return 0;
	long double j, ans=1;
	if(r>n/2)
	{
		r=n-r;
	}
	for(j=0;j<r;j++)
	{
		ans*=(n-j);
		ans/=j+1;
	}
	return ans;
}

int main()
{
    long double m,n,t,p;
    long double prob=0;
//    scanf("%d %d %d %d\n", &m, &n, &t, &p);
    cin>>m>>n>>t>>p;
    for(int i=n;i>=1 && p<=i*t;i--)
    {
        cout<<i<<"  ";
        prob += nCr(p,i)*nCr(m-p,n-i);
        prob /= nCr(m,n);
        cout<<nCr(p,i)<<"  "<<nCr(m-p,n-i)<<"   "<<nCr(m,n)<<"  "<<endl;
    }
    cout.precision(15);
    cout<<prob;
    return 0;
}
