//http://www.codechef.com/ACMKAN11/problems/CLNDR
//
#include <stdio.h>
#include <iostream>

using namespace std;


bool leap_year(int y)
{
    return (y%400 ==0 || (y%100 != 0 && y%4 == 0));
}

int main()
{
    int days;
    int day,month,year;
    char month_s[4]; 
    int month_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int T;
    scanf("%d\n",&T);
    while(T--)
    {
        days = 0;
        month_length[1] = 28;
        scanf("%d-%s-%d\n",&day,month_s,&year);
        if(month_s == "JAN")
            month = 1;
        else if(month_s == "FEB")
            month = 2;
        else if(month_s == "MAR")
            month = 3;
        else if(month_s == "APR")
            month = 4;
        else if(month_s == "MAY")
            month = 5;
        else if(month_s == "JUN")
            month = 6;
        else if(month_s == "JUL")
            month = 7;
        else if(month_s == "AUG")
            month = 8;
        else if(month_s == "SEP")
            month = 9;
        else if(month_s == "OCT")
            month = 10;
        else if(month_s == "NOV")
            month = 11;
        else if(month_s == "DEC")
            month = 12;

        if(leap_year(year))
            month_length[1]++;

        days += day;
        if(month>1)
        {    
        for(int i = 0;i<month-1;i++) //completed months and 0 index
        {
            days += month_length[i];
        }
        printf("%d",days);
        }
    }
    return 0;
}
