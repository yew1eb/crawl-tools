#include"stdio.h"
#include"string.h"


int n,m;
int Temp;
struct node
{
    int tot;
    int mem[444];
}E[444];
int match[444];
int visit[444];
int map[444][444];


int DFS(int k)
{
    int i;
    for(i=0;i<E[k].tot;i++)
    {
        if(visit[E[k].mem[i]])    continue;
        visit[E[k].mem[i]]=1;
        if(match[E[k].mem[i]]==-1 || DFS(match[E[k].mem[i]]))
        {
            match[E[k].mem[i]]=k;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int Case=1;
    int g;
    int i,l;
    int a,b;
    int ans;


    while(scanf("%d%d%d",&n,&m,&g),n||m||g)
    {
        Temp=n+m;


        memset(map,-1,sizeof(map));
        for(i=1;i<=Temp;i++)    map[i][i]=0;
        while(g--)
        {
            scanf("%d%d",&a,&b);
            b+=n;
            map[a][b]=map[b][a]=0;
        }


        for(i=1;i<=Temp;i++)    E[i].tot=0;
        for(i=1;i<=n;i++)
        for(l=n+1;l<=Temp;l++)
            if(map[i][l]==-1)    E[i].mem[E[i].tot++]=l;
        for(i=n+1;i<=Temp;i++)
        for(l=1;l<=n;l++)
            if(map[i][l]==-1)    E[i].mem[E[i].tot++]=l;


        ans=0;
        memset(match,-1,sizeof(match));
        for(i=1;i<=Temp;i++)
        {
            memset(visit,0,sizeof(visit));
            ans+=DFS(i);
        }
        printf("Case %d: %d\n",Case++,Temp-ans/2);
    }
    return 0;
}