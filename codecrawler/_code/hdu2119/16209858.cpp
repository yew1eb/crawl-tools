#include"stdio.h"
#include"string.h"


struct A
{
    int total;
    int mem[111];
}E[111];
int match[111];
int visit[111];


int DFS(int k)
{
    int i;
    for(i=0;i<E[k].total;i++)
    {
        if(visit[E[k].mem[i]])    continue;
        visit[E[k].mem[i]]=1;
        if(match[E[k].mem[i]]==0 || DFS(match[E[k].mem[i]]))
        {
            match[E[k].mem[i]]=k;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int map[111][111];
    int n,m;
    int i,l;
    int ans;


    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(i=1;i<=n;i++)
        for(l=1;l<=m;l++)
            scanf("%d",&map[i][l]);


        for(i=1;i<=n;i++)
        {
            E[i].total=0;
            for(l=1;l<=m;l++)    if(map[i][l])    E[i].mem[E[i].total++]=l;
        }


        memset(match,0,sizeof(match));
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(E[i].total==0)    continue;
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }


        printf("%d\n",ans);
    }
    return 0;
}