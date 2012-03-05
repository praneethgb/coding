#include <stdio.h>

int main()
{
    int N,total=0,Q,a,b,i,q1,q2,q3,q4;
    char query;
    int point[100000][3]; // x,y,quadrant for each point, nth quad = n
    scanf("%d\n",&N);
    while(N--)
    {
        scanf("%d %d\n",&point[total][0],&point[total][1]);
        if(point[total][0]>0 && point[total][1]>0)
            point[total][2]=1;
        else if(point[total][0]<0 && point[total][1]>0)
            point[total][2]=2;
        else if(point[total][0]<0 && point[total][1]<0)
            point[total][2]=3;
        else
            point[total][2]=4;
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
                    point[i][1]=-point[i][1]; // reflection along x axis y -> -y
                    switch(point[i][2])
                    {
                        case 1:
                            point[i][2]=4;
                            break;
                        case 2:
                            point[i][2]=3;
                            break;
                        case 3:
                            point[i][2]=2;
                            break;
                        case 4:
                            point[i][2]=1;
                            break;
                    }
                }
                break;
            case 'Y':
                for(i=a;i<=b;i++)
                {
                    point[i][0]=-point[i][0]; // reflection along y axis x -> -x
                    switch(point[i][2])
                    {
                        case 1:
                            point[i][2]=2;
                            break;
                        case 2:
                            point[i][2]=1;
                            break;
                        case 3:
                            point[i][2]=4;
                            break;
                        case 4:
                            point[i][2]=3;
                            break;
                    }
                }
                break;
            case 'C':
                q1=0;q2=0;q3=0;q4=0;
                for(i=a;i<=b;i++)
                {
                    switch(point[i][2])
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
