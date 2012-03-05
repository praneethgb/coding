#include <stdio.h>

int main()
{
    int N,total=0,Q,a,b,i,q1,q2,q3,q4,x,y;
    char query;
    int quad[10000]; // quadrant for each point, nth quad = n
    scanf("%d\n",&N);
    while(N--)
    {
        scanf("%d %d\n",&x,&y);
        if(x>0 && y>0)
            quad[total]=1;
        else if(x<0 && y>0)
            quad[total]=2;
        else if(x<0 && y<0)
            quad[total]=3;
        else
            quad[total]=4;
        total++;
    }    
    scanf("%d\n",&Q);
    while(Q--)
    {
        scanf("%c %d %d\n",&query,&a,&b);
        a--; //Convert a,b into 0 index form
        b--;
        switch(query)
        {
            case 'X':
                for(i=a;i<=b;i++)
                {
                   // point[i][1]=-point[i][1]; // reflection along x axis y -> -y
                    switch(quad[i])
                    {
                        case 1:
                            quad[i]=4;
                            break;
                        case 2:
                            quad[i]=3;
                            break;
                        case 3:
                            quad[i]=2;
                            break;
                        case 4:
                            quad[i]=1;
                            break;
                    }
                }
                break;
            case 'Y':
                for(i=a;i<=b;i++)
                {
                    //point[i][0]=-point[i][0]; // reflection along y axis x -> -x
                    switch(quad[i])
                    {
                        case 1:
                            quad[i]=2;
                            break;
                        case 2:
                            quad[i]=1;
                            break;
                        case 3:
                            quad[i]=4;
                            break;
                        case 4:
                            quad[i]=3;
                            break;
                    }
                }
                break;
            case 'C':
                q1=0;q2=0;q3=0;q4=0;
                for(i=a;i<=b;i++)
                {
                    switch(quad[i])
                    {
                        case 1:
                            q1++;
                            break;
                        case 2:
                            q2++;
                            break;
                        case 3:
                            q3++;
                            break;
                        case 4:
                            q4++;
                            break;
                    }
                }
                printf("%d %d %d %d\n",q1,q2,q3,q4);
                break;
        }
    }
    return 0;
}
