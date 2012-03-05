#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T,N,temp;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int mini = 1000000;
        cin>>N;
        int input[N][N];
        int ft[N][N][2];
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                cin>>input[j][k];
                ft[j][k][0]=0;
                ft[j][k][1]=0;
            }
        }
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                temp = input[j][k];
                while(temp%5 == 0 && temp!=0)
                {
                    ft[j][k][0]++;
                    temp /= 5;
                }
                temp = input[j][k];
                while(temp%2 ==0 && temp!=0)
                {
                    ft[j][k][1]++;
                    temp /= 2;
                }
            }
        }
        //for(int j=0;j<N;j++)
        //{
        //    for(int k=0;k<N;k++)
        //    {
        //        cout<<ft[j][k][0]<<" ";
        //    }
        //    cout<<endl;
        //}
        for(int j=1;j<N;j++)
            for(int l=0;l<2;l++)
            {
                ft[j][0][l] += ft[j-1][0][l];
                ft[0][j][l] += ft[0][j-1][l];
            }
        for(int j=1;j<N;j++)
            for(int k=1;k<N;k++)
                for(int l=0;l<2;l++)
                {
                    if(input[j-1][k]==0 && input[j][k-1]==0)
                        mini = 1000000;
                    else if(input[j-1][k] == 0)
                        mini = ft[j][k-1][l];
                    else if(input[j][k-1] == 0)
                        mini = ft[j-1][k][l];
                    else
                        mini = min(ft[j][k-1][l],ft[j-1][k][l]);
                    ft[j][k][l] += mini;
                }
        cout<<"Case "<<i<<" :"<<min(ft[N-1][N-1][0],ft[N-1][N-1][1])<<endl;
    }
    return 0;
}
