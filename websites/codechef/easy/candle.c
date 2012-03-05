#include "stdio.h"

int main()
{
    int T,i,min,no,j,k;
    scanf("%d\n",&T);
    while(T--)
    {
        j=0;
        scanf("%d",&no);
        min=no+1;
        for(i=1;i<10;i++)
        {
            scanf(" %d",&no);
            if(no<min)
            {
                min=no;
                j=i;
            }
        }
        scanf("\n");
        if(j==0)
        {
            printf("1");
            min--;
        }
            for(k=0;k<=min;k++)
                printf("%d",j);
            printf("\n");
    }
    return 0;
}
