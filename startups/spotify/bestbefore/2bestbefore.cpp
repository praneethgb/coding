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
    if(d==0||m==0||y<2000)
        return 0;
    if(m>12)
    {
        if(d>12)
            return 0;
        else
            swap(d,m);
    }

    if(leap_year(y) && m==2)
        month_length[1]++;
    if(d>month_length[m-1])
        return 0;
    return 1;
}

int main()
{
    int oday, day, omonth, month, oyear, year; //original and copies
    scanf("%d/%d/%d",&oday,&omonth,&oyear);
    day = oday;
    month = omonth;
    year = oyear;
    sort(day,month,year);
    if(day == 0)
    {
        swap(day,year);
        swap(day,month);
    }
    
    if(year<1000)
        year+=2000;
    if(check(day,month,year))
        printf("%04d-%02d-%02d",year,month,day);
    else
        printf("%d/%d/%d is illegal",oday,omonth,oyear);
    return 0;
}
