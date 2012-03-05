// The Trip
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=29&page=show_problem&problem=1078

#include <iostream>
#include <cstdio>

using namespace std;

//void round2(double& a) //rounds off to two digits of decimal place
//{
//    if(int(a*1000) % 10 <5)
//        a = int(a*100)/100;
//    else
//        a = (int(a*100)+1)/100;
//}

int main()
{
    int n;
    double sum,average,ndeviation,pdeviation,answer,diff;
    double students[1000];
    scanf("%d\n",&n);
    while(n!=0)
    {
        sum=0;
        pdeviation = 0;
        ndeviation = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf\n",&students[i]);
            sum +=students[i];
        }
        average = sum/n;
        //round2(average);
        //cout<<"average is "<<average<<endl;
        for(int i=0;i<n;i++)
        {
            //we need to redistribute so that we reach mean
            //transfer higher -> lower only when needed to
            diff = (double)(long)((average - students[i])*100.0)/100.0;
            if(students[i]<average)
            {
                ndeviation += diff;
                //cout<<"\tdeviation becomes\t"<<deviation<<"\t";
            }
            else
            {
                pdeviation += -diff;
            }
            //cout<<endl;
        }
        answer = ndeviation<pdeviation?ndeviation:pdeviation;
        printf("$%.2lf\n", answer);
        scanf("%d\n",&n);
    }
    return 0;
}
