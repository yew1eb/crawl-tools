#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
using namespace std;
#define N 211
int n,m;
int color[N];
int match[N],visit[N];

struct Eage{
    int from,to,next;
}eage[N*N];
int tot,head[N];
void add(int a,int b){
    eage[tot].from=a;eage[tot].to=b;eage[tot].next=head[a];head[a]=tot++;
}

void get_map()
{
    int i;
    int a,b;
    tot=0;
    memset(head,-1,sizeof(head));
    for(i=0;i<m;i++)    {scanf("%d%d",&a,&b);add(a,b);add(b,a);}
}
int Color()
{
    int j,v;
    queue<int>q;
    int now;
    int c_next;

    memset(color,-1,sizeof(color));
    color[1]=1;
    q.push(1);

    while(!q.empty())
    {
        now=q.front();
        q.pop();
        c_next=1-color[now];
        for(j=head[now];j!=-1;j=eage[j].next)
        {
            v=eage[j].to;
            if(color[v]==-1)    {color[v]=c_next;q.push(v);}
            else        if(color[v]==color[now])    return 1;
        }
    }
    return 0;
}

int DFS(int k)
{
    int j,v;
    for(j=head[k];j!=-1;j=eage[j].next)
    {
        v=eage[j].to;
        if(visit[v])    continue;
        visit[v]=1;
        if(match[v]==-1 || DFS(match[v]))
        {
            match[v]=k;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,l;
    int ans;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        get_map();
        if(Color())    {printf("No\n");continue;}


        ans=0;
        memset(match,-1,sizeof(match));
        for(i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }
        printf("%d\n",ans/2);
    }
    return 0;
}