// url: http://www.codechef.com/problems/NOTATRI/
#include "stdio.h"

int partition(int* a,int p,int r)
{
	int key=a[p];
	int j=p+1,temp,k;
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

int main()
{
    int N,i,first,second,third,count;
    int len[2000];
    while(1)
    {
        scanf("%d\n",&N);
        if(N==0)
            break;
        count=0;
        for(i=0;i<N;i++)
            scanf("%d",&len[i]);
        quicksort(len,0,N-1);
        for(third=N-1;third>1;third--)
        {
            first=0;
            second=third-1;
            while(second>first)
            {
                if(len[first]+len[second]<len[third])
                {
                    count+=second-first;
                    first++;
                }
                else
                {
                    second--;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}


