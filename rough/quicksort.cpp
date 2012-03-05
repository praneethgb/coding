#include <iostream>
using namespace std;
const int MAX=6;

int partition(int*,int,int);
void quicksort(int*,int,int);

int main()
{
int a[MAX]={6,4,1,5,2,3};
quicksort(a,0,MAX-1);
for(int i=0;i<MAX;i++)
	cout<<a[i];
}

int partition(int* a,int p,int r)
{
	int key=a[p];
	int j=p+1,temp;
	int i=p;
	for(;j<=r;j++)
	{
		if(a[j]<key)
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
	for(int k=0;k<MAX;k++)
		cout<<a[k];
	cout<<endl;
	return i;
}

void quicksort(int* a,int p,int r)
{
if (p<r)
{	
	int q=partition(a,p,r);
	quicksort(a,p,q-1);
	quicksort(a,q+1,r);
}
}
