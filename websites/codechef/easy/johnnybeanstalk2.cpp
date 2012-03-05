#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T,levels,prev=0;
	bool flag=1;
	cin>>T;
	while(T--)
	{
		cin>>levels;
		int leaves[levels];
		for(int i=0;i<levels;i++)
		{
			cin>>leaves[i];
			if(leaves[i]>pow(2,i-prev))
			{
				flag=0;
				break;
			}
			if(i!=levels-1)
				prev=leaves[i]+2*prev;
		}
		if(leaves[levels-1]!=pow(2,levels-1-prev))
			flag=0;
		if(flag==0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		prev=0;
		flag=1;
	}
	return 0;
}
