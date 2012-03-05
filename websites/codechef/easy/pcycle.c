//url : http://www.codechef.com/problems/PCYCLE/
#include "stdio.h"

int main()
{
    int N,min=1,count=0,i=0,j=0,next=0,k; //min 1 since 0 will be visited first time
    int no[1000],visited[1000]={0},output[1600];
    scanf("%d\n",&N);
    for(k=0;k<N;k++)
        scanf("%d ",&no[k]);
    while(i<=N) //i is the count of numbers
    {
        if(visited[next]==1) // if already visted cycle complete, choose new minimum next element
        {
            output[j++]=next+1;
            output[j++]=-1; // for printing \n
            count++;        // for no. of cycles
            next=min;
//          printf("cycle");
        }
        else
        {
            visited[next]=1; // mark visited no.s as 1
            output[j++]=next+1; //store the index of next in 1...N format
            if(next==min)       
            {
                while(visited[min]!=0&&i<N)
                    min++;      //choose minimum unvisited no
//                printf("\n min is %d",min);
            }

            next=no[next]-1;    //new value of next given by no. at next, convert to  0..N format
//            printf("\n next is: %d",next);
            i++;
//            printf("nahi");
        }
    }
    printf("%d\n",count);
    for(i=0;i<j-1;i++) // j has maximum index of output
    {
        if(output[i]==-1)
            printf("\n");
        else
            printf("%d ", output[i]);
    }
    return 0;
}
