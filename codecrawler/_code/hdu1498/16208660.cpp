#include"stdio.h"
#include"string.h"


struct A
{
    int tot;
    int mem[111];
}E[55][111];
int num[55];


int match[111];
int visit[111];
int map[111][111];
int yes[55];


int DFS(int z,int k)
{
    int i;
    int temp;
    for(i=0;i<E[z][k].tot;i++)
    {
        temp=E[z][k].mem[i];
        if(visit[temp])    continue;
        visit[temp]=1;
        if(match[temp]==-1 || DFS(z,match[temp]))
        {
            match[temp]=k;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int n,m;
    int z,i,l;
    int ans;
    int count;


    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)
        for(l=1;l<=n;l++)
        {
            scanf("%d",&map[i][l]);
            num[map[i][l]]++;
        }


        for(i=1;i<=50;i++)
        for(l=1;l<=n;l++)
            E[i][l].tot=0;


        for(i=1;i<=n;i++)
        for(l=1;l<=n;l++)
            E[map[i][l]][i].mem[E[map[i][l]][i].tot++]=l;


        memset(yes,0,sizeof(yes));
        for(z=1;z<=50;z++)
        {
            if(num[z]==0)    continue;
            ans=0;
            memset(match,-1,sizeof(match));
            for(i=1;i<=n;i++)
            {
                if(E[z][i].tot==0)    continue;
                memset(visit,0,sizeof(visit));
                ans+=DFS(z,i);
            }
            if(ans>m)    yes[z]=1;
        }


        count=0;
        for(i=1;i<=50;i++)    if(yes[i])    count++;
        if(!count)    printf("-1\n");
        else
        {
            for(i=1;i<=50;i++)    if(yes[i])    {printf("%d",i);break;}
            for(i++;i<=50;i++)        if(yes[i])    printf(" %d",i);
            printf("\n");
        }
    }
    return 0;
}
