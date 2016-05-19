#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"stack"
#define N 1111
#define M 2222
using namespace std;

int n,m,cost[N];
//Tarjan
int s_index;
int instack[N],DFN[N],LOW[N];
int belong[N],indegree[N];
//éæé»æ¥è¡¨
struct Eage
{
    int from,to,next;
}eage[M];
int tot,head[N];

void add(int a,int b)
{
    eage[tot].from=a;
    eage[tot].to=b;
    eage[tot].next=head[a];
    head[a]=tot++;
}
void getmap()
{
    int a,b;
    tot=0;
    memset(head,-1,sizeof(head));
    while(m--)  {scanf("%d%d",&a,&b);add(a,b);}
}
stack<int>st;
void Tarjan(int k)
{
    int j,v;
    st.push(k);
    instack[k]=1;
    DFN[k]=LOW[k]=++s_index;
    for(j=head[k];j!=-1;j=eage[j].next)
    {
        v=eage[j].to;
        if(instack[v])  LOW[k]=LOW[k]>DFN[v]?DFN[v]:LOW[k];
        else if(DFN[v]==-1)
        {
            Tarjan(v);
            LOW[k]=LOW[k]>LOW[v]?LOW[v]:LOW[k];
        }
    }
    if(DFN[k]==LOW[k])
    {
        do
        {
            j=st.top();
            st.pop();
            instack[j]=0;
            belong[j]=k;
        }while(j!=k);
    }
}
int main()
{
    int i,l;
    int t;
    int ans_p,ans_c;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=1;i<=n;i++)   scanf("%d",&cost[i]);
        getmap();


        memset(DFN,-1,sizeof(DFN));
        memset(LOW,-1,sizeof(LOW));
        memset(belong,-1,sizeof(belong));
        memset(instack,0,sizeof(instack));
        s_index=0;
        for(i=1;i<=n;i++)   if(DFN[i]==-1) Tarjan(i);

        memset(indegree,0,sizeof(indegree));
        for(i=0;i<tot;i++)
        {
            if(belong[eage[i].from]==belong[eage[i].to])    continue;
            indegree[belong[eage[i].to]]++;
        }
        ans_p=ans_c=0;
        for(i=1;i<=n;i++)
        {
            if(belong[i]!=i)   continue;
            if(indegree[i]) continue;
            ans_p++;
            t=111111111;
            for(l=1;l<=n;l++)
            {
                if(belong[l]!=i)    continue;
                t=t>cost[l]?cost[l]:t;
            }
            ans_c+=t;
        }

        printf("%d %d\n",ans_p,ans_c);
    }
    return 0;
}