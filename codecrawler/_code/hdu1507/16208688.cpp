#include"stdio.h"
#include"string.h"


int n,m,k;
struct A
{
    int x,y;
};
struct node
{
    int flag;
    int num;
    int tot;
    struct A mem[5];
}E[111][111];
struct B
{
    int flag;
    int x,y;
}match[111][111];
int visit[111][111];
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};


int DFS(int x,int y)
{
    int i;
    int t1,t2;
    for(i=0;i<E[x][y].tot;i++)
    {
        t1=E[x][y].mem[i].x;
        t2=E[x][y].mem[i].y;
        if(visit[t1][t2])    continue;
        visit[t1][t2]=1;
        if(match[t1][t2].flag==-1 || DFS(match[t1][t2].x,match[t1][t2].y))
        {
            match[t1][t2].flag=1;
            match[t1][t2].x=x;
            match[t1][t2].y=y;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int i,l,j;
    int a,b;
    int n_x,n_y;
    int ans;
    while(scanf("%d%d",&n,&m),n||m)
    {
        scanf("%d",&k);


        for(i=1;i<=n;i++)
        for(l=1;l<=m;l++)
        {E[i][l].flag=1;E[i][l].tot=0;}


        for(i=0;i<k;i++)
        {
            scanf("%d%d",&a,&b);
            E[a][b].flag=0;
        }


        for(i=1;i<=n;i++)
        {
            if(i%2)
            {
                for(l=1;l<=m;l+=2)
                {
                    for(j=0;j<4;j++)
                    {
                        n_x=i+dir[j][0];
                        n_y=l+dir[j][1];
                        if(n_x<1 || n_x>n || n_y<1 || n_y>m)    continue;
                        if(E[n_x][n_y].flag)
                        {
                            E[i][l].mem[E[i][l].tot].x=n_x;
                            E[i][l].mem[E[i][l].tot++].y=n_y;
                        }
                    }
                }
            }
            else
            {
                for(l=2;l<=m;l+=2)
                {
                    for(j=0;j<4;j++)
                    {
                        n_x=i+dir[j][0];
                        n_y=l+dir[j][1];
                        if(n_x<1 || n_x>n || n_y<1 || n_y>m)    continue;
                        if(E[n_x][n_y].flag)
                        {
                            E[i][l].mem[E[i][l].tot].x=n_x;
                            E[i][l].mem[E[i][l].tot++].y=n_y;
                        }
                    }
                }
            }
        }


        ans=0;
        for(i=1;i<=n;i++)
        for(l=1;l<=m;l++)
            match[i][l].flag=-1;
        for(i=1;i<=n;i++)
        {
            if(i%2)
            {
                for(l=1;l<=m;l+=2)
                {
                    if(!E[i][l].flag)    continue;
                    if(!E[i][l].tot)    continue;
                    memset(visit,0,sizeof(visit));
                    ans+=DFS(i,l);
                }
            }
            else
            {
                for(l=2;l<=m;l+=2)
                {
                    if(!E[i][l].flag)    continue;
                    if(!E[i][l].tot)    continue;
                    memset(visit,0,sizeof(visit));
                    ans+=DFS(i,l);
                }
            }
        }


        printf("%d\n",ans);
        for(i=1;i<=n;i++)
        {
            if(i%2)
            {
                for(l=2;l<=m;l+=2)
                {
                    if(match[i][l].flag==-1)    continue;
                    printf("(%d,%d)--(%d,%d)\n",match[i][l].x,match[i][l].y,i,l);
                }
            }
            else
            {
                for(l=1;l<=m;l+=2)
                {
                    if(match[i][l].flag==-1)    continue;
                    printf("(%d,%d)--(%d,%d)\n",match[i][l].x,match[i][l].y,i,l);
                }
            }
        }
        printf("\n");
    }
    return 0;
}