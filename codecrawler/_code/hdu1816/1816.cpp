#include<stdio.h>
#include<stack>
#include<string.h>
#define N 5000
using namespace std;
struct edge
{
    int ed,next;
}E[20000];
struct op
{
    int key1,key2;
}Key[N];
struct ep
{
    int  lock1, lock2;
}Door[N];
struct eg
{
    int ed;
    eg *next;
}*e[N];
int n,m,num,idx,ans,low[N],dfs[N],belong[N],ins[N],first[N];
void addedge(int x,int y)
{
    E[num].ed=y;
    E[num].next=first[x];
    first[x]=num++;
}
void addeg(int x,int y)
{
    eg *p=new eg;
    p->ed=y;
    p->next=e[x];
    e[x]=p;
}
void insit()
{
    memset(dfs,-1,sizeof(dfs));
    memset(low,0,sizeof(low));
    memset(ins,0,sizeof(ins));
    memset(belong,-1,sizeof(belong));
    memset(first,-1,sizeof(first));
    idx=ans=0;num=0;
}
stack<int>Q;
void Tarjan(int x)
{
    int v,p;
    low[x]=dfs[x]=idx++;
    ins[x]=1;
    Q.push(x);
    for(p=first[x];p!=-1;p=E[p].next)
    {
        v=E[p].ed;
        if(dfs[v]==-1)
        {
            Tarjan(v);
            low[x]=low[x]>low[v]?low[v]:low[x];
        }
        else if(ins[v]==1)
        {
            low[x]=low[x]>dfs[v]?dfs[v]:low[x];
        }
    }
    if(low[x]==dfs[x])
    {
        do
        {
            v=Q.top();
            Q.pop();
            ins[v]=0;
            belong[v]=ans;
        }while(v!=x);
        ans++;
    }
}
int judge(int d)
{
    int i,x,y;
    insit();
    for(i=0;i<d;i++)//+2*n表示不选，
    {
        x=Door[i].lock1;
        y=Door[i].lock2;
        addedge(x,y+2*n);
        addedge(y,x+2*n);
    }
    for(i=0;i<n;i++)
    {
        x=Key[i].key1;
        y=Key[i].key2;
		addedge(x+2*n,y);
        addedge(y+2*n,x);
       
    }
    for(i=0;i<n*4;i++)
    {
       if(dfs[i]==-1)
           Tarjan(i);
    }
    for(i=0;i<2*n;i++)
    {
        if(belong[i]==belong[i+2*n])
            return 0;
    }
    return 1;
}
int main()
{
    int min,max,mid,i,mmax;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
        {
          scanf("%d%d",&Key[i].key1,&Key[i].key2);
          addeg(Key[i].key1,Key[i].key2);
          addeg(Key[i].key2,Key[i].key2);
        }
        for(i=0;i<m;i++)
            scanf("%d%d",&Door[i]. lock1,&Door[i]. lock2);
           min=0;max=m;
           mmax=0;
           while(min<=max)
           {
               mid=(min+max)/2;
               if(judge(mid))
               {
                   mmax=mid;
                   min=mid+1;
               }
               else max=mid-1;
           }
           printf("%d\n",mmax);
    }
    return 0;
}