//Minesweeper
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=29&page=show_problem&problem=1130

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 102; //two padding

void update(int mtrx[MAX][MAX], int a, int b)
{
    mtrx[a][b]=42;
    for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++)
        {
            if(i==0 && j==0)
                continue;
            else
            {
               // cout<<"a"<<i<<"  b"<<j<<endl;
                if(mtrx[a+i][b+j]!=42)
                    mtrx[a+i][b+j]++;
            }
        }
//    mtrx[a-1][b]++;
//    mtrx[a-1][b-1]++;
//    mtrx[a-1][b+1]++;
//    mtrx[a][b-1]++;
//    mtrx[a][b+1]++;
//    mtrx[a+1][b-1]++;
//    mtrx[a+1][b]++;
//    mtrx[a+1][b+1]++;
}

int main()
{
    int matrix[MAX][MAX];
    int m=-1, n=-1,count=1,j,caseno=0;
    char input;
    while(1)
    {
        memset(matrix,0,sizeof(matrix[0][0])* MAX*MAX);
        caseno++;
        scanf("%d %d\n",&n,&m);
        //cout<<"m : "<<m<<"n : "<<n;
        if(m==0 && n==0)
            break;
        if(caseno!=1)
            printf("\n");
        printf("Field #%d:\n",caseno);
        for(int i=1;i<=n;i++)
        {
            j=1;
            while((input=getchar())!='\n')
            {
          //      cout<<"Flag 1 "<<input<<endl;
                if(input=='*')
                {
                    update(matrix, i,j);
                }
                j++;
            //    cout<<"i is "<<i<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i][j]==42)
                    printf("%c", matrix[i][j]);
                else
                    printf("%d", matrix[i][j]);
            }
        printf("\n");
        }
        //printf("\n");
    }
    return 0;
}
