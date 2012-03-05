#include <iostream>
using namespace std;

int main()
{
	int T, cities, balls,count,initial,final,flag;
	int* heights;
	cin>>T;
	while(T--)
	{
		count=0;
		cin>>cities>>balls;
		heights = new int[cities];
		for(int i=0;i<cities;i++)
			cin>>heights[i];
		while(balls--)
		{
			flag=0;
			cin>>initial>>final;
			for(int i=0;i<final-initial;i++)
			{
				if(heights[initial-1]<heights[initial+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
