#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 200020
int set[N],sum[N];

int n,m;

int find(int x)
{
    if(set[x] == x) return x;
    int t = set[x];
    set[x] = find(set[x]);
    sum[x] += sum[t];
    return set[x];
}

void merge(int x,int y,int a,int b,int v)
{
    if(x > y)
    {
        set[y] = x;
        sum[y] = sum[a]-v-sum[b];
    }else
    {
        set[x] = y;
        sum[x] = v + sum[b] - sum[a];
    }
}

void init()
{
    memset(sum,0,sizeof(sum));
    for(int i = 0;i <= n;i++)   set[i] = i;
}

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        init();
        int a,b,v,re = 0;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&a,&b,&v);
            a--;
            //b++;
            int x = find(a);
            int y = find(b);
            if(x == y && sum[a] != sum[b] + v)
            {
                re++;
            }
            else if(x != y)
                merge(x,y,a,b,v);
        }
        printf("%d\n",re);
    }
    return 0;
}