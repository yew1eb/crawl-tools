#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;

#define lson 2*i
#define rson 2*i+1
#define LS l,mid,lson
#define RS mid+1,r,rson
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 20005
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
const int mod = 1e9+7;

int n,m,tot;
int father[N],r[N],num[N],u,v,w,vis[N];
char str[100];

int find(int x)
{
    if(x!=father[x])
    {
        int fx = father[x];
        father[x] = find(father[x]);
        r[x]^=r[fx];
    }
    return father[x];
}

bool Union(int a,int b,int c)
{
    int fa = find(a),fb=find(b);
    if(fa==fb)
    {
        if((r[a]^r[b])!=c) return false;
        return true;
    }
    if(fa==n) swap(fa,fb);
    father[fa] = fb;
    r[fa] = r[a]^r[b]^c;
    return true;
}

int query()
{
    int i,j,cnt,ans = 0;
    MEM(vis,0);
    for(i = 0; i<tot; i++)
    {
        if(vis[i]) continue;
        cnt = 0;
        int root = find(num[i]);
        for(j = i; j<tot; j++)
        {
            if(!vis[j] && root == find(num[j]))
            {
                vis[j] = 1;
                cnt++;
                ans^=r[num[j]];
            }
        }
        if(root!=n&&(cnt&1))
        {
            return -1;
        }
    }
    return ans;
}

int main()
{
    int i,j,k,cas = 1;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        printf("Case %d:\n",cas++);
        for(i = 0; i<=n; i++)
        {
            father[i] = i;
            r[i] = 0;
        }
        bool flag = false;
        int fac = 0;
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='I')
            {
                getchar();
                gets(str);
                fac++;
                int cnt = 0;
                for(i = 0; str[i]!='\0'; i++)
                {
                    if(str[i]==' ')
                        cnt++;
                }
                if(cnt == 1)
                {
                    sscanf(str,"%d%d",&u,&w);
                    v = n;
                }
                else
                {
                    sscanf(str,"%d%d%d",&u,&v,&w);
                }
                if(flag)
                    continue;
                if(!Union(u,v,w))
                {
                    printf("The first %d facts are conflicting.\n",fac);
                    flag = true;
                }
            }
            else
            {
                scanf("%d",&tot);
                for(i = 0; i<tot; i++)
                    scanf("%d",&num[i]);
                if(flag) continue;
                int ans = query();
                if(ans == -1)
                    printf("I don't know.\n");
                else
                    printf("%d\n",ans);

            }
        }
        printf("\n");
    }

    return 0;
}
