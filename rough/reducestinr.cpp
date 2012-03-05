#include <iostream>
#include <string>
using namespace std;

int main()
{
string s;
string small[30];
int n,x;
cin>>s>>n;
for(int i=0;n>0;n--,i++)
{
	cin>>small[i];
	x=s.find(small[i]);
	while(x<s.size())
	{	
		s.erase(x,small[i].size());
		string sub=s.substr(x,s.size());
		if(sub.find(small[i])<sub.size())
		{
		x+=sub.find(small[i]);
		}
		else
			break;
	}
}
cout<<s.size();
return 0;
}
