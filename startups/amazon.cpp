int searchElement(int[] a, int x, int start, int end){
    int size = end-start+1;
    if(x<a[size/2])
    {
        if(x<=size/2 && start<=x)
            searchElement(a,x,start,size/2);
        else
            searchElement(a,x,size/2+1,end);
    }
    else if(x>a[size/2])
    {
        if(x>=size/2+1 && end<=x)
            searchElement(a,x,size/2+1,end);
        else
            searchElement(a,x,start,size/2);
    }
    else
        return (size/2);
} 

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char[] a, int s, int e)
{
    for(int i=s;i<=e/2;i++)
    {
        swap(a[i],a[e-i]);
    }
}


char[] reverseWordsInPlace(char[] a){
    int length=0;
    char t = a[0];
    while(t != '\0')
    {
        t = a[++length];
    }
    reverse(a,0,length-1);
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
