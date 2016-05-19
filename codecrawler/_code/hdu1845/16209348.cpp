#include"stdio.h"
int main()
{
    int T;
    int t;
    int a,b;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        t=3*n/2;
        while(t--)    scanf("%d%d",&a,&b);
        printf("%d\n",n/2);
    }
    return 0;
}




/*
#include"stdio.h"
#include"string.h"


struct Eage
{
    int from;
    int to;
    int next;
}eage[15111];
int tot;
int head[5111];


int match[5111];
int visit[5111];


void add(int a,int b)
{
    eage[tot].from=a;
    eage[tot].to=b;
    eage[tot].next=head[a];
    head[a]=tot++;
}


int DFS(int k)
{
    int t;
    int temp;
    t=head[k];
    while(t!=-1)
    {
        temp=eage[t].to;
        if(visit[temp])    {t=eage[t].next;continue;}
        visit[temp]=1;
        if(match[temp]==-1 || DFS(match[temp]))
        {
            match[temp]=k;
            return 1;
        }
        t=eage[t].next;
    }
    return 0;
}


int main()
{
    int T;
    int n;
    int i;
    int t;
    int a,b;
    int ans;


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        tot=0;
        memset(head,-1,sizeof(head));
        t=3*n/2;
        for(i=0;i<t;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }


        ans=0;
        memset(match,-1,sizeof(match));
        for(i=1;i<=n;i++)
        {
            if(head[i]==-1)    continue;
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }


        printf("%d\n",ans/2);
    }
    return 0;
}*/