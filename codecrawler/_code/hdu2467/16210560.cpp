#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M,S,T;

int h[]={0,3,2,1,2,3,2,3,4,3,4,5,4,5,6,5,6,7,6,7,8};
int p[1<<21];
int v[1<<21];

int count(int x){
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
    x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
    return x;
}

bool dfs(int state,int id,int d, int maxd)
{
    if(d == maxd && state == T)
        return true;
    if(h[p[state ^ T]] + d > maxd || M - id + d < maxd)
        return false;
    for(int i = id; i < M; ++i)
        if(dfs(state ^ v[i],i+1,d+1,maxd)) return true;
    return false;
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    int cas = 1;
    for(int i = 0; i <1100000; ++i)
        p[i] = count(i);
    while(scanf("%d%d",&N,&M),N||M){
        scanf("%d%d",&S,&T);
        for(int i = 0; i < M; ++i)
            scanf("%d",&v[i]);
        int dep = 0;
        bool sig = false;
        for(;dep <= M;++dep){
            if(dfs(S,0,0,dep)){
                sig = true;
                break;
            }
        }
        printf("Case #%d: ",cas++);
        if(sig)
            printf("%d\n",dep);
        else
            puts("Impossible");
    }
    return 0;
}