#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int s[105];
struct pi
{
    int no;
    int to;
    int cost;
    int next;
}pp[10005];
int head[105];
int dis[105];
char c[3];
int tot;
int vis[105];
int flag;
queue<int >q;
void add(int a,int b,int cost)
{
    pp[tot].no=a;
    pp[tot].to=b;
    pp[tot].cost=cost;
    pp[tot].next=head[a];
    head[a]=tot++;
}
void spfa(int n)
{
    int i,k,s=0;
    while(!q.empty())
        q.pop();
    q.push(n+1);
    while(!q.empty())
    {
        k=q.front();
        vis[k]=0;
        q.pop();
        for(i=head[k];i!=-1;i=pp[i].next){
            if(dis[pp[i].to]<dis[k]+pp[i].cost){
                dis[pp[i].to]=dis[k]+pp[i].cost;
                if(!vis[pp[i].to]){
                    q.push(pp[i].to);
                    vis[pp[i].to]=1;
                    s++;
                }
            }
        }
        if(s>2*n*n){
            flag=1;
            return ;
        }
    }
    return ;
}
int main()
{
    int i,j,n,m,p,t,mm;
    while(cin>>n)
    {
        if(!n)
            break;
        cin>>m;
        memset(head,-1,sizeof(head));
        tot=0;mm=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%s%d",&p,&t,c,&j);
            if(c[0]=='g')
            {
                j++;
                add(p-1,t+p,j);
            }
            else
            {
                j--;
                add(p+t,p-1,-j);
            }
            if(mm<p+t)
                mm=p+t;
        }
        if(mm>n)
        {
            printf("successful conspiracy\n");
            continue;
        }
        for(i=0;i<=n;i++)
            dis[i]=-0x3f;
        memset(vis,0,sizeof(vis));
        for(i=0;i<=n;i++)
        {
            add(n+1,i,0);
        }
        dis[n+1]=0;
        flag=0;
        spfa(n);
        if(flag){
            printf("successful conspiracy\n");
        }
        else{
            printf("lamentable kingdom\n");
        }
    }
    return 0;
}