#include <iostream>
using namespace std;

int xpos[3];
int ypos[3];

int sqdistance(int a)
{
	int x=xpos[a%3]-xpos[(a+1)%3];
	int y=ypos[a%3]-ypos[(a+1)%3];
	return x*x+y*y;
}


int main()
{
int T,R,count=0;

cin>>T;
while(T--)
{
	cin>>R;
	for(int i=0;i<3;i++)
	{
		cin>>xpos[i]>>ypos[i];
	}
	for(int j=0;j<3;j++)
	{
		if(sqdistance(j)<=R*R)
			count++;
	}
	if(count>=2)
		cout<<"yes\n";
	else
		cout<<"no\n";
	count=0;
}
return 0;
}
