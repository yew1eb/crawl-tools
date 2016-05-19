#include<iostream>
#include<cstdio>
#include<memory.h>
#include<iostream>
using namespace std;
const int MAX=1100005;
const int inf=1<<30;
struct node
{
	int v,c,next;
}g[MAX+10000];
int adj[MAX],cur[MAX],dis[MAX],num[MAX],pre[MAX],grade[MAX];
int s,t,vn,e,n,m,cnt;
void add(int u,int v,int c)
{
	g[e].v=v; g[e].c=c; g[e].next=adj[u]; adj[u]=e++;
	g[e].v=u; g[e].c=0; g[e].next=adj[v]; adj[v]=e++;
}
int sap()  
{  
    int i,u,v,flow=0,aug=inf,flag;  
    for(i=0;i<=vn;i++)  
    {  
        dis[i]=num[i]=0;  
        cur[i]=adj[i];  
    }  
    num[0]=vn;  
    pre[s]=u=s;  
    while(dis[s]<vn)  
    {  
        flag=0;  
        for(i=cur[u];i!=-1;i=g[i].next)  
        {  
            v=g[i].v;  
            if(g[i].c&&dis[u]==dis[v]+1)  
            {  
                flag=1;  
                pre[v]=u;  
                cur[u]=i;  
                aug=aug<g[i].c?aug:g[i].c;  
                u=v;  
                if(u==t)  
                {  
                    flow+=aug;  
                    while(u!=s)  
                    {  
                        u=pre[u];  
                        g[cur[u]].c-=aug;  
                        g[cur[u]^1].c+=aug;  
                    }  
                    aug=inf;  
                }  
                break;  
            }  
        }  
        if(flag)  
            continue;  
        if(--num[dis[u]]==0)  
            break;  
        for(dis[u]=vn,i=adj[u];i!=-1;i=g[i].next)  
        {  
            v=g[i].v;  
            if(g[i].c&&dis[v]<dis[u])  
            {  
                dis[u]=dis[v];  
                cur[u]=i;  
            }  
        }  
        dis[u]++;  
        num[dis[u]]++;  
        u=pre[u];  
    }  
    return flow;  
}  
int main()
{
	int i,j,maxx=-1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(adj,-1,sizeof(adj));
		memset(grade,0,sizeof(grade));
		e=cnt=0;
		t=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&j);
			add(i,t,j);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&j);
			if(j>maxx)
				maxx=j;
			if(!grade[j])
				cnt++;
			grade[j]++;
		}
		s=n+cnt+1;
		vn=s+1;
		for(i=1,cnt=0;i<=maxx;i++)
		{
			if(grade[i])
			{
				//cout<<grade[i]<<endl;
				cnt++;
				add(s,n+cnt,grade[i]);
				for(j=i;j>=1;j--)
					add(n+cnt,j,grade[i]);
			}
		}
		printf("%d/n",sap());
	}
	return 0;
}