#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int c[1010],vis[1010];
int f[maxn];
struct node{
    int w,m;
    int name;
    bool operator <(const node a)const{
        if(w==a.w)return m>a.m;
        return w>a.w;
    }
}e,g;
char s[11];
int main()
{
    int t,n,tt=0;
    while(scanf("%d",&t)!=EOF)
    {
        if(t==0)break;
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        int i,j,k,a,num=0;
        for(i=1;i<=t;i++)
        {
            scanf("%d",&n);
            for(j=0;j<n;j++)
            {
                scanf("%d",&a);
                f[a]=i;
            }
        }
        priority_queue<node>q;
        printf("Scenario #%d\n",++tt);
        int d=0;
        while(cin>>s)
        {
            if(strcmp(s,"STOP")==0)break;
            if(strcmp(s,"ENQUEUE")==0)
            {
                scanf("%d",&a);
                if(c[f[a]])
                {
                    c[f[a]]++;
                    g.w=vis[f[a]];
                    g.name=a;
                    g.m=d++;
                    q.push(g);
                }
                else
                {
                    c[f[a]]++;
                    vis[f[a]]=num;
                    g.w=num++;
                    g.name=a;
                    g.m=d++;
                    q.push(g);
                }
            }
            else
            {
                g=q.top();
                q.pop();
                printf("%d\n",g.name);
                c[f[g.name]]--;
            }
        }
        printf("\n");
    }
    return 0;
}
