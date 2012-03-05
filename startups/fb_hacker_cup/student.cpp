#include <iostream>
#include <string>
using namespace std;

int partion(string*,int,int);
void quicksort(string*,int,int);
bool check(string,string);

int main()
{
	int n,words;
	string s[9];
	cin>>n;
	while(n--)
	{
		cin>>words;
		for(int i=0;i<words;i++)
		{
			cin>>s[i];
		}
		quicksort(s,0,words-1);
		for(int j=0;j<words;j++)
		{
			cout<<s[j];
		}
		cout<<endl;
	}
return 0;
}

int partition(string* a,int p,int r)
{
	string key=a[p];
	string temp;
	int j=p+1;
	int i=p;
	for(;j<=r;j++)
	{
		if(a[j]<key && check(a[j],key)!=true)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i];
	a[i]=a[p];
	a[p]=temp;
	return i;
}

void quicksort(string* a,int p,int r)
{
if (p<r)
{	
	int q=partition(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);
}
}

bool check(string a,string b)
{
	if(a.length()<b.length() && a==b.substr(0,a.length()))
		return true;
	return false;
}		
