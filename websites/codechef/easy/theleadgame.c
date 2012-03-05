#include "stdio.h"

int main()
{
    int rounds,i,prevf=0,prevs=0,f,s,winner,max=0;
    scanf("%d\n",&rounds);
    for(i=0;i<rounds;i++)
    {
        scanf("%d %d\n",&f,&s);
        f+=prevf;
        s+=prevs;
        prevf=f;
        prevs=s;
        if(f>s)
        {
            if(f-s>max)
            {
                max=f-s;
                winner=1;
            }
        }
        else
        {
            if(s-f>max)
            {
                max=s-f;
                winner=2;
            }
        }
    }
    printf("%d %d\n",winner,max);
    return 0;
}
