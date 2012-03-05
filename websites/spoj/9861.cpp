#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N,M,sum=0,start=0,end;
    int cost[300000];
    scanf("%d %d\n", &N, &M);
    end = N-1;
    for(int i=0;i<N;i++)
        scanf("%d ", &cost[i]);
    for(int i=0;i<N;i++)
    {
        sum += cost[i];
    }
    while(sum>M)
    {
        if(cost[end] < cost[start])
        {
            sum -= cost[end];
            end--;
        }
        else
        {
            sum -= cost[start];
            start++;
        }
    }
    printf("%d",sum);
//    for(int i = 0;i<N;i++)
//        printf("%d ", cost[i]);
    return 0;
}
