#include <iostream>
using namespace std;

int q;
const int MAX=100;

int partition(int* A,int p,int q)
{
	int x=A[p];
	int i=p;
	int temp;
	for(int j=p+1;j<=q;j++)
	{
		if(A[j]<x)
		{
			i++;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
			temp=A[i];
			A[i]=A[p];
			A[p]=temp;			
	return i;
}

void quicksort(int* A,int p,int r)
{
	if(p<r)
	{
	q=partition(A,p,r);
	quicksort(A,p,q-1);
	quicksort(A,q+1,r);
	}
}

int main()
{
	int cases,pies;
	int count,l;
	int i1[MAX],i2[MAX];
	cin>>cases;
	while(cases--)
	{
		count=0;
		l=0;
		cin>>pies;
		for(int w=0;w<pies;w++)
			cin>>i1[w];
		for(int j=0;j<pies;j++)
			cin>>i2[j];

		quicksort(i1,0,pies-1);
		quicksort(i2,0,pies-1);
	
		for(int i=0;i<pies;i++)
		{
			if(i1[l]<=i2[i])
				{
					count++;
					l++;
				}
		}
		cout<<count<<endl;
	}
	return 0;
}
