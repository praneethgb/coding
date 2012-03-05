// url : http://www.codechef.com/problems/DPC101/
#include "stdio.h"

int main()
{
    int first,second, faux, saux,carrys, prevc;
    while(1)
    {
        carrys=0;
        prevc=0;
        scanf("%d %d\n",&first,&second);
        if(first==0 && second==0)
            break;
        while((first!=0 && second!=0) || prevc!=0)
        {
            //printf("first : %d second : %d, prevc : %d\n", first, second, prevc);
            faux=first%10;
            saux=second%10;
            prevc=(faux+saux+prevc)/10;
            if(prevc)
                carrys++;
            first/=10;
            second/=10;
        }
        if (carrys==0)
            printf("No carry operation.\n");
        else if (carrys==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",carrys);
    }
    return 0;
}
