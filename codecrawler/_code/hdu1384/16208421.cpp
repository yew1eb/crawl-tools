#include"iostream"
#include"cstdio"
#include"queue"
#include"cstring"
using namespace std;
const int N=50055;
const int inf=10000000;

int n,mmin,mmax,dis[N];
struct Edge{
    int v,len,next;
}edge[4*N];
int tot,head[N];
void add(int a,int b,int c){
    edge[tot].v=b;edge[tot].len=c;edge[tot].next=head[a]++;head[a]=tot++;
}

void build_map(int m)
{
    int i,a,b,c;
    tot=0;
    memset(head,-1,sizeof(head));
    mmin=1<<20;mmax=-1;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        a--;
        if(mmin>a)    mmin=a;
        if(mmax<b)    mmax=b;
        add(a,b,c);
    }
    for(i=mmin;i<mmax;i++)
    {
        add(i+1,i,-1);
        add(i,i+1,0);
    }
}
void SPFA()
{
    int i,j,v,now;
    int hash[N];
    queue<int>q;

    memset(hash,0,sizeof(hash));
    for(i=mmin;i<=mmax;i++)    dis[i]=-inf;
    dis[mmin]=0;
    hash[mmin]=1;
    q.push(mmin);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(j=head[now];j!=-1;j=edge[j].next)
        {
            v=edge[j].v;
            if(dis[v]>=dis[now]+edge[j].len)    continue;
            dis[v]=dis[now]+edge[j].len;
            if(hash[v])    continue;
            hash[v]=1;
            q.push(v);
        }
        hash[now]=0;
    }
}
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        build_map(n);
        SPFA();
        printf("%d\n",dis[mmax]);
    }
    return 0;
}