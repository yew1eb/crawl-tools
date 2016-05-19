#include <cstdio>
#include <queue>
#include <map>
#define INF 999999999
using namespace std;

struct S{
int pos;
long long dis;

bool operator<(const S & p) const
{
    return dis>p.dis;
}
}t;

char mp[1005];
int head[1005],nxt[20000],val[20000],des[20000],vis[1005][1000];

int main()
{
    int T,n,m,s,k,i,j,u,v,w,casenum=1,disans,desans;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&k);

        scanf("%s",mp);

        for(i=0;i<=n;i++) head[i]=-1;

        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);

            nxt[i]=head[u];
            head[u]=i;
            val[i]=w;
            des[i]=v;
        }

        printf("Case %d: ",casenum++);

        priority_queue<S>que;
        for(i=1;i<=n;i++) for(j=0;j<k;j++) vis[i][j]=0;

        vis[s][0]=1;

        disans=desans=INF;

        t.dis=0;
        t.pos=s;

        que.push(t);

        while(!que.empty())
        {
            t=que.top();
            que.pop();

            if(t.dis && mp[t.pos-1]=='P' && t.dis%k==0 && t.dis<=disans)
            {
                disans=t.dis;

                if(t.pos<desans) desans=t.pos;
            }

            for(i=head[t.pos];i!=-1;i=nxt[i])
            {
                t.dis+=val[i];
                t.pos=des[i];

                if(!vis[t.pos][t.dis%k] || t.dis<vis[t.pos][t.dis%k])
                {
                    vis[t.pos][t.dis%k]=t.dis;

                    que.push(t);
                }

                t.dis-=val[i];
            }
        }

        if(disans==INF) printf("-1 -1\n");
        else printf("%d %d\n",disans,desans);
    }

}
