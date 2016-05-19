#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 203
#define Min(a,b) (a<b?a:b)
#define INF 0x3f3f3f3f
int S,E,visit[MAX],flag[MAX][MAX],Map[MAX][MAX],pre[MAX],Index;
int path[MAX],listb[MAX<<1],In[MAX],To[MAX];
struct snode{
    int c,to,next;
}Edge[MAX*MAX];
int Fabs(int x)
{
    return (x<0)?-x:x;
}

void Add_edge(int a,int b,int c)
{
    Edge[Index].to=b,Edge[Index].c=c;
    Edge[Index].next=pre[a];
    pre[a]=Index++;
}

bool BFS()     //BFSå¯»æ¾å¢å¹¿è·¯
{
    int i,s,e,v,vv;
    s=e=0;
    memset(visit,0,sizeof(visit));
    memset(flag,0,sizeof(flag));
    listb[s++]=S;
    visit[S]=1;
    while(s!=e)
    {
        v=listb[e++];
        if(v==E)
            return true;
        for(i=pre[v];i!=-1;i=Edge[i].next)
        {
            vv=Edge[i].to;
            if(!visit[vv]&&Map[v][vv]>=1)
            {
                visit[vv]=1;
                listb[s++]=vv;
                flag[v][vv]=1;
            }
        }
    }
    return false;
}

int DFS(int v,int sum)
{
    int s=sum,i,t,vv;
    if(v==E||sum==0)
        return sum;
    for(i=pre[v];i!=-1;i=Edge[i].next)
    {
        vv=Edge[i].to;
        if(flag[v][vv])
        {
            t=DFS(vv,Min(sum,Map[v][vv]));
            Map[v][vv]-=t;
            Map[vv][v]+=t;
            sum-=t;
        }
    }
    return s-sum;
}

int Solve()      //Dinic
{
    int sum=0;
    while(BFS())
        sum+=DFS(S,INF);
    return sum;
}

int main()
{
    int n,m,i,j,a,b,c,sum1,t,temp3;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        Index=sum1=0,S=0,E=n+1;
        memset(In,0,sizeof(In));
        memset(To,0,sizeof(To));
        memset(pre,-1,sizeof(pre));
        memset(Map,0,sizeof(Map));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            To[a]++,In[b]++;
            if(c==0)     //ä¸­é´å»ºå¾
            {
                c=1;
                if(!Map[a][b])
                {
                    Add_edge(a,b,c);
                    Add_edge(b,a,-c);
                }
                Map[a][b]+=c;
            }
        }
        int pd=0,temp,temp1;
        for(i=1;i<=n;i++)
        {
            temp=In[i]-To[i];
            temp1=Fabs(temp);
            if(temp1!=0&&temp1%2==0)
            {
                if(temp<0)                //å·¦è¾¹
                {
                    a=S,b=i,c=temp1/2,sum1+=c;
                    if(!Map[a][b])
                    {
                        Add_edge(a,b,c);
                        Add_edge(b,a,-c);
                    }
                    Map[a][b]+=c;
                }
                else                      //å³è¾¹
                {
                    a=i,b=E,c=temp1/2;
                    if(!Map[a][b])
                    {
                        Add_edge(a,b,c);
                        Add_edge(b,a,-c);
                    }
                    Map[a][b]+=c;
                }
            }
            else if(temp1!=0)
            {
                pd=1;
                break;
            }
        }
        if(pd==1)
            printf("impossible\n");
        else
        {
            temp3=Solve();
            if(sum1==temp3)
                printf("possible\n");
            else
                printf("impossible\n");
        }
    }
}
