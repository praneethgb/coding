#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
//#include <vector>

using namespace std;

void swap(int& p, int& q)
{
    int temp = p;
    p=q;
    q=temp;
}

void split(string str, string delim, string* results) //for fixed size
{
    int cut_at,i=0;
    while( (cut_at = str.find_first_of(delim)) != str.npos )
    {
        if(cut_at > 0)
        {
            results[i++]=str.substr(0,cut_at);
        }
        str = str.substr(cut_at+1);
    }
    if(str.length() > 0)
    {
        results[i]=str;
    }
}

void sort(int& a, int& b, int& c)
{
    if(a>b)
    {
        if(b>c)
        {
            swap(a, c);
        }
        else
        {
            if(a>c)
            {
                swap(a,b);
                swap(b,c);
            }
            else
            {
                swap(a,b);
            }
        }
    }
    else
    {
        if(b>c)
        {
            if(a>c)
            {
                swap(a,c);
                swap(b,c);
            }
            else
            {
                swap(b,c);
            }
        }
    }
}

bool leap_year(int y)
{
    return (y%400 ==0 || (y%100 != 0 && y%4 == 0));
}

bool check(int& d, int& m, int& y)
{
    int month_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(d<=0||m<=0||m>12||(y>999&&y<2000))
        return 0;
    if(leap_year(y) && m==2)
        month_length[1]++;
    if(d>month_length[m-1])
        return 0;
    return 1;
}

bool all_check(int* a)
{
    for(int i=0;i<3;i++)
    {
        for(int j=2;j>=0;j--)
        {
            if(j==i)
                continue;
            for(int k=2;k>=0;k--)
            {
                if(k==j || k==i)
                    continue;
                if(check(a[j],a[k],a[i])) // j-> day, k -> month, i-> year
                {
                    if(a[i]<1000)
                        a[i]+=2000;
                    printf("%04d-%02d-%02d",a[i],a[k],a[j]);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    string input;
    string odate[3];
    int date[3]; //original and copies
    int k=0;
    cin>>input;
    split(input,"/",odate);
    for(int i=0;i<3;i++)
    {
//        cout<<odate[i];
        date[i]= atoi(odate[i].data());
      //  printf("%d",date[i]);
    }
    sort(date[0],date[1],date[2]);
    
    if(!all_check(date))
        cout<<odate[0]<<"/"<<odate[1]<<"/"<<odate[2]<<" is illegal";
    //    printf("%s/%s/%s is illegal",odate[0],odate[1],odate[2]);
    return 0;
}
