#include <iostream>
using namespace std;

int q;

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
	int A[5]={2,6,4,3,7};
	quicksort(A,0,4);
	for(int i=0;i<5;i++)
		cout<<A[i]<<endl;
	return 0;
}
