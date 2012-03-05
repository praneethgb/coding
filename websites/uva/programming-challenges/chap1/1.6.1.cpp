//3n+1 Problem
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=29&page=show_problem&problem=36

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b,max,current,temp,i,j;
    while(scanf("%d %d\n",&a,&b)!=EOF)
    {
        max = 0;
        if(a>b)
        {
            i=b;
            j=a;
        }
        else
        {
            i=a;
            j=b;
        }
        for(int k=i;k<=j;k++)
        {
            temp = k;
            current = 1;
            while(temp!=1)
            {
                if(temp%2 !=0)
                    temp = (3*temp+1);
                else
                    temp =temp/2;
                current += 1;
            }
            if(current>max)
                max = current;
        }
        printf("%d %d %d\n",a,b,max);
    }
    return 0;
}
