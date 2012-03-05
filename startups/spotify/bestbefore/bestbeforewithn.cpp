#include <stdio.h>

void swap(int& p, int& q)
{
    int temp = p;
    p=q;
    q=temp;
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
    return (!y%4 && (y%100) || !(y%400));
}

bool check(int& d, int& m, int& y)
{
    int month_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(d<=0||m<=0||m>12)
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
                    printf("%04d-%02d-%02d\n",a[i],a[k],a[j]);
                    return 1;
                }
               // else{
               // printf("%d %d %d\n",a[j],a[k],a[i]);}
            }
        }
    }
    return 0;
}

int main()
{
    int odate[3], date[3]; //original and copies
    scanf("%d/%d/%d\n",&odate[0],&odate[1],&odate[2]);
    for(int i=0;i<3;i++)
    {
        date[i]=odate[i];
    }
    sort(date[0],date[1],date[2]);
//    if(day == 0)
//    {
//        swap(day,year);
//        swap(day,month);
//    }
    
    if(!all_check(date))
        printf("%d/%d/%d is illegal\n",odate[0],odate[1],odate[2]);
    return 0;
}
