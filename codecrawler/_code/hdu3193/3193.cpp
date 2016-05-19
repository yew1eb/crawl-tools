#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
struct Node
{
    int p,d;
}node[MAXN];
bool cmp(Node a,Node b)
{
    if(a.p != b.p)return a.p < b.p;
    else return a.d < b.d;
}
bool f[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&node[i].p,&node[i].d);
        sort(node,node+n,cmp);
        int Min = 100000000;
        int tmp = 100000000;
        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            if(i > 0 && node[i].p != node[i-1].p)
            {
                Min = min(Min,tmp);
                tmp = 100000000;
            }
            tmp = min(tmp,node[i].d);
            if(Min < node[i].d)f[i] = false;
            else{f[i] = true; cnt++;}
        }
        printf("%d\n",cnt);
        for(int i = 0;i < n;i++)
            if(f[i])
               printf("%d %d\n",node[i].p,node[i].d);
    }
    return 0;
}