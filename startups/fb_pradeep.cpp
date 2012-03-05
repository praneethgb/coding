#include <stdio.h>
#include <algorithm>
#include <iostream>

int cmp(const void* a, const void* b){
    int* x = (int*)a;
    int* y = (int*)b;
    int count1 = __builtin_popcount(*x);
    int count2 = __builtin_popcount(*y);
    if(count1 < count2) return true;
    if(count1 > count2) return false;
    return *x < *y;
}

//int cmp(const void * a, const void  * b) {
//    int *aa = (int *)a;
//    int *bb = (int *)b;
//
//    int lenA = bitC(*aa);
//    int lenB = bitC(*bb);
//
//    if((lenA > lenB) || ((lenA==lenB) && ((*aa)>(*bb))) )
//        return 1;
//    else
//        return -1;
//}
int main()
{
    int N,K;
    scanf("%d %d", &N, &K);
    int* a = new int[1<<N];
    for(int i=0;i<(1<<N);i++)
        a[i]=i;
    qsort(a,1<<N,sizeof(int),cmp);
    std::cout.write(reinterpret_cast<const char*>(&a[K-1]), sizeof a[K-1]);
    return 0;
}
