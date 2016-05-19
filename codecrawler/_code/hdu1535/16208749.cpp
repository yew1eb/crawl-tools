#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;


int n;
struct A
{
    int dis;
    int flag;
}E[1000111];
struct node
{
    int num;
    int dis;
    friend bool operator<(node n1,node n2)
    {
        return n2.dis<n1.dis;
    }
};


struct Eage
{
    int from;
    int to;
    int len;
    int next;
}eage[2][1000111];
int tot[2];
int head[2][1000111];
void add(int a,int b,int c,int k)
{
    eage[k][tot[k]].from=a;
    eage[k][tot[k]].to=b;
    eage[k][tot[k]].len=c;
    eage[k][tot[k]].next=head[k][a];
    head[k][a]=tot[k]++;
}


priority_queue<node>q;
void Dij(int z)
{
    node cur,next;
    int temp;
    int flag;


    cur.num=1;
    cur.dis=0;
    q.push(cur);
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(!E[cur.num].flag)    continue;
        E[cur.num].flag=0;


        temp=head[z][cur.num];
        flag=0;
        do
        {
            if(flag)    temp=eage[z][temp].next;
            flag=1;
            if(E[cur.num].dis+eage[z][temp].len<E[eage[z][temp].to].dis)
            {
                E[eage[z][temp].to].dis=E[cur.num].dis+eage[z][temp].len;
                next.num=eage[z][temp].to;
                next.dis=E[eage[z][temp].to].dis;
                q.push(next);
            }
        }
        while(eage[z][temp].next!=-1);
    }
}


int main()
{
    int T;
    int q;
    int i;
    int a,b,c;
    int ans;


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        tot[0]=tot[1]=0;
        memset(head,-1,sizeof(head));
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c,0);
            add(b,a,c,1);
        }


        ans=0;


        for(i=1;i<=n;i++)    {E[i].dis=1111111111;E[i].flag=1;}
        E[1].dis=0;
        Dij(0);
        for(i=1;i<=n;i++)    ans+=E[i].dis;


        for(i=1;i<=n;i++)    {E[i].dis=1111111111;E[i].flag=1;}
        E[1].dis=0;
        Dij(1);
        for(i=1;i<=n;i++)    ans+=E[i].dis;


        printf("%d\n",ans);
    }
    return 0;
}