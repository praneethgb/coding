#include "stdio.h"

int main()
{
    int A,N,K;
    scanf("%d %d %d\n",&A,&N,&K);
    while(K--)
    {
        printf("%d ",A%(N+1));
        A/=(N+1);
    }
    return 0;
}
