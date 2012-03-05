#include "stdio.h"

int main()
{
    int T,count,mugger,i,j,sum,flag;
    int notes[20];
    scanf("%d\n",&T);
    while(T--)
    {
        flag=0;
        scanf("%d %d\n",&count,&mugger);
        for(i=0;i<count;i++)
            scanf("%d\n",&notes[i]);
        for(i=0;i<(1<<count);i++) //2^n possible combinations
        {
            sum=0;
            for(j=0;j<count;j++)
            {
                if(i&(1<<j)) //if jth digit of i is 1
                {
                    sum+=notes[j];
                }
            }
            if(sum==mugger)
            {
                printf("Yes\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("No\n");
        }
    }
    return 0;
}
