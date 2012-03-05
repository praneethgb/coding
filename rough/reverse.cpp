#include <iostream>
using namespace std;

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char a[], int s, int e)
{
    for(int i=0;i<(e-s+1)/2;i++)
    {
        swap(a[s+i],a[e-i]);
    }
}


char* reverseWordsInPlace(char a[]){
    int length=0;
    char t = a[0];
    while(t != '\0')
    {
        t = a[++length];
    }
    cout<<length;
    reverse(a,0,length-1);
    cout<<a;
    int sw=0,ew;
    for(int i=0;i<=length;i++)
    {
        if(a[i] == ' ' || a[i] == '\0')
        {
            ew=i-1;
            reverse(a,sw,ew);
            sw=i+1;
        }  
    }
    return a;
}

int main()
{
    int length = -1;
    char a[] = "I am a boy";
    //reverse(a,2,3);
    char* b = reverseWordsInPlace(a);
    while(a[length] != '\0')
    {
        cout << a[++length];
    }
    return 0;
}
