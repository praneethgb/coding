#include <iostream>
#include <queue>
using namespace std;

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
	int T,N,K,G,current=0,flag=0,cont=0,aux,maxaux=0; //n elements, k elements in each group,g= n/k groups
	cin>>T;
	while(T--)
	{
	cin>>N>>K;
	G=N/K;
	int seq[N];
	for(int i=0;i<N;i++)
		cin>>seq[i];
	quicksort(seq,0,N-1);
	//dfffffffff
	for(int i=0;i<N;i++)
		cout<<seq[i];
	//fffffffffff
	seq[-1]=1000000001;
	queue<int> groups[G];
	for(int i=0;i<N;i++)
	{
		cout<<"Current: "<<current<<endl;
		if(seq[i-1]!=seq[i] && groups[G-1].size()<K)
		{
			groups[current].push(seq[i]); cout<<"pushed"<<seq[i]<<endl;
			cont=0;
		}
		else if(seq[i-1]==seq[i])
		{
		if(cont==0)
			{
				cont=1;
				aux=current;
				cout<<"Aux is"<<aux<<endl;
			}
		if(aux+1==G)
		{
			cout<<"aux if"<<endl;
			flag=1;
			break;
		}
		groups[++aux].push(seq[i]);
		//ds
		cout<<"push\n";
		//ds
		if(aux-current+1>maxaux)
		{
			maxaux=aux-current+1;
			cout<<maxaux;
		}
		}
		if(groups[current].size()==K)
			current++;
		if(current==G && i!=N-1)
		{
			flag=1;
			break;
		}

	}
	if(flag==1)
	{
		if(maxaux>G)
			cout<<"-1"<<endl;
		else
		{
		for(int i=0;i<G;i++)
			while(groups[i].size()!=0)
				groups[i].pop();
		for(int i=0;i<N;i++)
			groups[i%K].push(seq[i]);
		flag=0;
		}
		
	}
	if(flag==0)
	{
	for(int i=0;i<G;i++)
		for(int j=0;j<K;j++)
		{
			cout<<groups[i].front();
			groups[i].pop();
			if(i==G-1 && j==K-1)
				cout<<endl;
			else
				cout<<" ";
		}
	}
	current=0;
	flag=0;
	maxaux=0;
	cont=0;
//	delete [] groups;
	}
return 0;
}
