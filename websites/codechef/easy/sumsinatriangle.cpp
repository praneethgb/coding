#include <cstdio>

int max2(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    int triangle[100][100];
    int T,lines,ans;
    scanf("%d\n",&T);
    while(T--)
    {
        scanf("%d\n",&lines);
        scanf("%d\n",&triangle[0][0]);
        for(int i=1;i<lines;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&triangle[i][j]);
                if(j==0)
                {
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j==i)
                {
                    triangle[i][j]+=triangle[i-1][j-1];
                }
                else
                {
                    triangle[i][j]+=max2(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        ans=triangle[lines-1][0];
        for(int k=1;k<lines;k++)
        {
            if(triangle[lines-1][k]>ans)
                ans=triangle[lines-1][k];
        }
        printf("%d\n",ans);
    }
    return 0;
}
