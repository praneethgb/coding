//6818. Capital City  http://www.spoj.pl/problems/CAPCITY/

#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

struct vertex
{
    int i;
    vector<vertex> adjlist; //adjacency list
    //for strongly connected components
    int index, lowlink;
};

int index = 0;
vector<vertex> S;
vector< vector<int> > components;
vector<int> temp;
int i;
void stronglyconnect(vertex& v)
{
    v.index = index;
    v.lowlink = index;
    index++;
    S.push_back(v);
    vector<vertex>::iterator it;
    for(it=v.adjlist.begin(); it<v.adjlist.end(); it++)
    {
        if(it->index == -1)
        {
            stronglyconnect(*it);
            v.lowlink = min(v.lowlink, it->lowlink);
        }
        else if(find(S.begin(), S.end(), (*it)) != S.end()) // check this line for errors
        {
            v.lowlink = min(v.lowlink, it->index);
        }
    }
    if(v.lowlink == v.index)
    {
        do
        {
            i = S.back().i;
            S.pop_back();
            temp.push_back(i);
        }while(i != v.i);
        components.push_back(temp);
        temp.clear();
    }
}

int main()
{
    int N, M; // N cities, M unidirectional roads
    int a, b; //road from a -> b
    vertex temp;
    temp.index = -1; // -1 -> undefined
    vector<int> cities;
    scanf("%d %d\n", &N, &M);
    //vector<vertex> adjlist[N+1]; //ignore 0 index
    vertex point[N+1]; //ignore 0
    for(int i=0;i<M;i++)
    {
        scanf("%d %d\n", &a, &b);
        temp.i = a;
        point[b].adjlist.push_back(temp); //reversing edges
    }
    //need to find strongly connected components
    for(int i=1;i<N+1;i++)
    {
        if(point[i].index == -1)
            stronglyconnect(point[i]);
    }
    //size = cities.size();
    //printf("%d\n", size);
    //if(size != 0)
    //    printf("%d", cities[0]);
    //for(int i=1;i<size;i++)
    //    printf(" %d", cities[i]);
    return 0;
}
