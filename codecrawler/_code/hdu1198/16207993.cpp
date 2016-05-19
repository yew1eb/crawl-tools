#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int R[11][11]={{0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,0,1,1,1,1,0,1},{0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,0,1,1,1,1,0,1},{0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,0,1,1,1,1,0,1},{1,0,1,0,0,1,1,1,1,0,1},
{0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,1,1,1,1,0,1},
{1,0,1,0,0,1,1,1,1,0,1},{1,0,1,0,0,1,1,1,1,0,1}};
int U[11][11]={{0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,1,0,1,1,0,1,1},
{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1},
{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1}};
int p[3000];
void make_set(int n)
{
    int i;
    for(i=0;i<=n;i++)
        p[i]=i;
}
int find_set(int i)
{
    int j=i;
    while(j!=p[j])
    {
        j=p[j];
    }
    return p[i]=j;
}
int Union(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x==y)
        return 0;
    else
    {
        p[x]=y;
        return 1;
    }
}
char map[55][55];
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n))
    {
        if(m==-1&&n==-1)
            break;
        int i,j;
        make_set(n*m);
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++)
            scanf("%s",map[i]);
        for(i=0;i<m;i++)
            for(j=1;j<n;j++)
                if(R[map[i][j-1]-'A'][map[i][j]-'A'])
                    Union(i*n+j-1,i*n+j);
        for(i=0;i<n;i++)
            for(j=1;j<m;j++)
                if(U[map[j-1][i]-'A'][map[j][i]-'A'])

                    Union((j-1)*n+i,j*n+i);
        int count=0;
        for(i=0;i<n*m;i++)
        {
            if(p[i]==i)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
