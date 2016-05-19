#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define CLR(arr,v) memset(arr,v,sizeof(arr))

int m,n;
const int size = 50;
const int INS = INT_MAX/2;
int val[size],dis[size];
int h[size],ed[1000],nex[1000],price[1000],que[size],inque[size];
int pos,head,total;

void init()
{
    pos = 1;head = total = 0;
    CLR(h,0); CLR(que,0);  CLR(price,0);
    CLR(ed,0);CLR(inque,0);CLR(nex,0);
    fill(dis,dis+size,INS);CLR(val,0);
}
void add(int u,int v,int f)
{
    ed[pos] = v;
    price[pos] = f;
    nex[pos] = h[u];
    h[u] = pos++;
}

void SPFA()
{
    dis[0] = 0;
    que[total++] = 0;
    inque[0] = true;
    while(head < total)
    {
        int p = que[head];    
        inque[p] = false;
        head = (head+1)%size;
        for(int i = h[p]; i ;i = nex[i])
        {
            int to = ed[i];
            if(dis[to] > dis[p] + price[i])
            {
                dis[to] = dis[p] + price[i];
                if(!inque[to])
                {
                    que[total] = to;
                    inque[to] = true;
                    total = (total+1)%size;
                }
            }
        }
    }
    for(int i = 1;i <= n;++i)
    {
        printf("%d %d\n",i,dis[i]);
    }
    int cnt = 0; CLR(val,0);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            for(int k = 1 + j;k <= n;++k)
                if(i != j && i != k && dis[i] == dis[k] + dis[j] && !val[i])
                {
                    val[i] = true;cnt++;
                }
    printf("%d\n",cnt);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        int b,money;
        for(int i = 1;i <= n;++i)
        {
            scanf("%d%d",&b,&money);
            val[b] = money;
            add(0,b,money-1);
        }
        scanf("%d",&m);
        int u,v,f;
        for(int i = 0;i < m;++i)
        {
            scanf("%d%d%d",&u,&v,&f);
            add(u,v,f);
        }
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= n;++j)
                if(i != j && val[i] == val[j])
                {
                    add(i,j,0);
                    add(j,i,0);
                }
        SPFA();
    }
    return 0;
}