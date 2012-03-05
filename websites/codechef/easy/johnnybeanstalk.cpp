#include <iostream>
using namespace std;

int main()
{
	int T,levels,prev=1;
	bool flag=1;
	cin>>T;
	while(T--)
	{
		cin>>levels;
		int leaves[levels];
		for(int i=0;i<levels;i++)
		{
			cin>>leaves[i];
			if(i==0)
			{
			if(leaves[0]>1)
				{
//					cout<<"1\n";
					flag=0;
					break;
				}
				else
				{
//					cout<<"2\n";
					prev=1-leaves[i];
					continue;
				}
			}
			else if(leaves[i]>2*prev)
			{
//				cout<<"3\n";
				flag=0;
				break;
			}
			if(i!=levels-1)
			{
//				cout<<"4\n";
				prev=2*prev-leaves[i];
			}
		}
		if(leaves[levels-1]!=2*prev)
			{
					flag=0;
//					cout<<"Yo\n";
			}
		if(flag==0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		prev=1;
		flag=1;
	}
	return 0;
}

