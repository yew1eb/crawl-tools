#include<cstdio>
#include<cstring>
int n,m,cnt,s,t;
int mp[51][51],head[3000],dis[3000],gap[3000];
const int inf=1<<30;
struct EDGE
{
    int to,f,nxt;
}edge[15000];
int min(int a,int b)
{
    return a<b?a:b;
}
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(gap,0,sizeof(gap));
    memset(dis,0,sizeof(gap));
    gap[0]=t;
}
void add(int x,int y,int c)
{
    edge[cnt].to=y;
    edge[cnt].f=c;
    edge[cnt].nxt=head[x];
    head[x]=cnt++;
}
void gao(int x,int y,int c)
{
    add(x,y,c);
    add(y,x,0);
}
int dfs(int x,int flow)
{
    if(x==t)
    return flow;
    int temp=flow;
    int pos=t-1;
    int j;
    for(j=head[x];j!=-1;j=edge[j].nxt)
    {
        int y=edge[j].to;
        int c=edge[j].f;
        if(c>0&&dis[x]==dis[y]+1)
        {
            int  temp_flow=dfs(y,min(temp,c));
            temp-=temp_flow;
            edge[j].f-=temp_flow;
            edge[j^1].f+=temp_flow;
            if(temp==0||dis[s]==t)
            return flow-temp;
        }
        if(c>0&&pos>dis[y])
        pos=dis[y];
    }
    if(temp==flow)
    {
        if(!(--gap[dis[x]]))
            dis[s]=t;
        else
            gap[dis[x]=pos+1]++;
    }
    return flow-temp;
}
int sap()
{
    int maxflow=0;
    while(dis[s]<t)
    {
        maxflow+=dfs(s,inf);
    }
    return maxflow;
}
int main()
{
    while(2==scanf("%d%d",&n,&m))
    {
        s=n*m+1,t=s+1;
        init();
        int sum=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&mp[i][j]);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            sum+=mp[i][j];
            int num=(i-1)*m+j;
            if((i+j)%2)
            {
                gao(s,num,mp[i][j]);
                if(i>1)
                gao(num,num-m,inf);
                if(j>1)
                gao(num,num-1,inf);
                if(i<n)
                gao(num,num+m,inf);
                if(j<m)
                gao(num,num+1,inf);
                
            }
            else
                gao(num,t,mp[i][j]);
        }
        printf("%d\n",sum-sap());
    }
}