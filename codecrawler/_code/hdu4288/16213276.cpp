#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 100003

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

typedef __int64 LL;

int num[N],x[N];             //numè®°å½å¯¹åºæä½çæ°ï¼xè®°å½å¯¹åºçåºé´å­çæ°

int add;

struct Tnode
{
    int l,r,cnt;
    LL sum[5];
}T[N<<2];

void Build(int u,int l,int r)
{
    T[u].l = l , T[u].r = r;
    if(l == r-1)
    {
        memset(T[u].sum,0,sizeof(T[u].sum));
        T[u].cnt = 0;
        return ;
    }
    int mid = MID(l,r);
    Build(L(u),l,mid);
    Build(R(u),mid,r);
    memset(T[u].sum,0,sizeof(T[u].sum));
    T[u].cnt = 0;
}

void Updata(int u,int l,int r)
{
    add ? ++T[u].cnt : --T[u].cnt;
    if(T[u].l == T[u].r - 1)
    {
        T[u].sum[1] = add * x[l-1];
        return ;
    }
    int mid = MID(T[u].l,T[u].r);
    if(l >= mid)
        Updata(R(u),l,r);
    else
        Updata(L(u),l,r);
    for(int i=0;i<5;i++)
    {
        int j = (i + T[L(u)].cnt) % 5;
        T[u].sum[j] = T[L(u)].sum[j] + T[R(u)].sum[i];
    }
}

int main()
{
    int Q;
    char cmd[N],ccmd[4];
    while(~scanf("%d",&Q))
    {
        int top = 0;
        for(int i=0;i<Q;i++)
        {
            scanf("%s",ccmd);
            cmd[i] = ccmd[0];
            if(cmd[i] != 's')
                scanf("%d",&num[top++]);
        }
        memcpy(x,num,sizeof(int)*top);
        sort(x,x+top);
        int n = unique(x,x+top) - x;
        Build(1,1,n+1);
        for(int i=0,j=0;i<Q;i++)
        {
            if(cmd[i] == 's')
            {
                printf("%I64d\n",T[1].sum[3]);
                continue;
            }
            int k = lower_bound(x,x+n,num[j++]) - x + 1;
            add = cmd[i] == 'a' ? 1 : 0;
            Updata(1,k,k+1);
        }
    }
    return 0;
}