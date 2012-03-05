// ARRAY TANSFORM http://www.codechef.com/problems/ARRAYTRM/

/* Algorithm
 *
 * Let total operations on an element a[i] be z
 * 1. Either it get's decreased by 1 : say x times
 * 2. or increased by k:say y times
 *
 * x+y=z
 * a[i]+k*x-y=0 (for n-1 elements)
 * => z=(k+1)x +a[i]
 * => z mod k+1 = a[i] mod k+1 for n-1 values for true
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T,n,K,count,common;
    int a[100];
    cin>>T;
    while(T--)
    {
        count=0;
        cin>>n>>K;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]=a[i]%(K+1);
        }
        if(n==2) //YES for two elements
        {
            printf("YES\n");
            continue;
        }
        if(a[0]==a[1])
            common=a[0];
        else if(a[1]==a[2])
            common=a[1];
        else if(a[2]==a[0])
            common=a[2];
        else
        {
            printf("NO\n");
            break;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]!=common)
            {
                count++;
                if(count==2)
                {
                printf("NO\n");
                break;
                }
            }
        }
        if(count!=2)
            printf("YES\n");
    }
    return 0;
}
