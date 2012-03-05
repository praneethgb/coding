//Dutch national flag problem
//http://en.wikipedia.org/wiki/Dutch_national_flag_problem
#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void three_partition(int data[], int size, int low, int high)
{
    int x = -1;
    int y = size;
    for(int i = 0;i<y;)
    {
        if(data[i]<low)
        {
            swap(data[i], data[++x]);
            i++;
        }
        else if(data[i]>=high)
        {
            swap(data[i], data[--y]);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {0,0,1,2,0,0,2,2,1,0,1};
    three_partition(a,11,1,2);
    for(int i=0;i<11;i++)
        cout<<a[i]<<" ";
    return 0;
}
