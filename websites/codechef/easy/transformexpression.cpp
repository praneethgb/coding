#include "stdio.h"
#include <stack>
using namespace std;

int main()
{
    int T;
    scanf("%d\n",&T);
    char a=' ';
    stack<char> symbol;
    while(T--)
    {
        while(a=getchar())
        {
            if(a=='\n')
            {
                putchar(a);
                break;
            }
            if ((a>64&&a<91)||(a>96&&a<123))
            {
                putchar(a);
            }
            else if(a=='(')
            {
            }
            else if(a==')')
            {
                printf("%c",symbol.top());
                symbol.pop();
            }
            else
            {
                symbol.push(a);
            }
        }
    }
    return 0;
}
