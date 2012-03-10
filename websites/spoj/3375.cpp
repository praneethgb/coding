// http://www.spoj.pl/problems/STAMPS/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int T, min, frnds, val[1001], sum, flag;
    scanf("%d", &T);
    for(int i=1;i<=T;i++)
    {
        printf("Scenario #%d:\n", i);
        sum=0;flag=0;
        scanf("%d %d", &min, &frnds);
        for(int j=0;j<frnds;j++)
            scanf("%d", val+j);
        sort(val, val+frnds);
        for(int j=0;j<frnds;j++)
        {
            sum+=val[frnds-j-1];
            if(sum>=min)
            {
                printf("%d\n\n", j+1);
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            printf("impossible\n\n");
        }
    }
    return 0;
}



