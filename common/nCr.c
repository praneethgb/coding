// nCr function

long long nCr(long long n, long long r)
{
	long long j, ans=1;
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
