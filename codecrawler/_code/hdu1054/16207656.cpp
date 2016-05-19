#include"stdio.h"
#include"string.h"


struct Eage
{
    int from;
    int to;
    int next;
}eage[2222222];
int tot;
int head[1555];


int n;
int match[1555];
int visit[1555];


void add(int a,int b)
{
    eage[tot].from=a;
    eage[tot].to=b;
    eage[tot].next=head[a];
    head[a]=tot++;
}


int DFS(int k)
{
    int e;
    e=head[k];


    while(e!=-1)
    {
        if(visit[eage[e].to])    {e=eage[e].next;continue;}
        visit[eage[e].to]=1;
        if(match[eage[e].to]==-1 || DFS(match[eage[e].to]))
        {
            match[eage[e].to]=k;
            return 1;
        }
        e=eage[e].next;
    }
    return 0;
}


int main()
{
    int n;
    int i,l;
    int t;
    int a,b;
    int ans;
    char str[111];


    while(scanf("%d",&n)!=-1)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            a=0;
            for(l=0;str[l]&&str[l]!=':';l++)    {a*=10;a+=str[l]-'0';}
            t=0;
            for(l+=2;str[l]!=')';l++)    {t*=10;t+=str[l]-'0';}


            while(t--)
            {
                scanf("%d",&b);
                add(a,b);
                add(b,a);
            }
        }


        memset(match,-1,sizeof(match));
        ans=0;
        for(i=0;i<n;i++)
        {
            if(head[i]==-1)    continue;
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }


        printf("%d\n",ans/2);
    }
    return 0;
}