#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=30000;
const int MAXM=50000;
struct node
{
    int u,v;
};
node edge[MAXM];
int first[MAXN],next[MAXM];
int cc;
int num[MAXN];
int child_num[MAXN];
int in[MAXN];
inline void add_edge(int u,int v)
{
    edge[cc].u=u;
    edge[cc].v=v;
    next[cc]=first[u];
    first[u]=cc;
    cc++;
}
void dfs(int u)
{
    if(num[u]!=-1)
        return ;
    int i;
    int k=0;
    int *temp=new int[MAXN];
    for(i=first[u];i!=-1;i=next[i])
    {
        int v=edge[i].v;
        dfs(v);
        temp[k++]=num[v];
    }
    sort(temp,temp+k);
    num[u]=temp[(child_num[u]+1)/2-1];
    delete temp;
    return ;
}
void Scan(int &num)    //对G++使用
{
    char in;
    bool neg=false;
    while(((in=getchar()) > '9' || in<'0') && in!='-') ;
    if(in=='-')
    {
        neg=true;
        while((in=getchar()) >'9' || in<'0');
    }
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(neg)
        num=0-num;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        memset(first,-1,sizeof(first));
        memset(next,-1,sizeof(next));
        cc=0;
        memset(num,-1,sizeof(num));
        memset(in,0,sizeof(in));
        memset(child_num,0,sizeof(child_num));
        for(i=1;i<=n;i++)
        {
            int p;
            Scan(p);
            child_num[i]=p;
            if(p==0)
                num[i]=i;
            int j;
            for(j=0;j<p;j++)
            {
                int x;
                Scan(x);
                in[x]++;
                add_edge(i,x);
            }
        }
        for(i=1;i<=n;i++)
            if(in[i]==0)
            {
                dfs(i);
                break;
            }
        printf("%d\n",num[i]);
    }
    return 0;
}