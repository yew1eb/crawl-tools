#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define inf  99999999

int n,m;
int map[85][85];
int a[85][85][85],tem[85][85];

void Floyd()
{
    int i,j,k;
    for(i = 1; i<=n; i++)
        for(j = 1; j<=n; j++)
            for(k = 1; k<=n; k++)
                if(map[j][i]+map[i][k]<map[j][k])
                    map[j][k] = map[j][i]+map[i][k];
}

void getmap()
{
    int i,j,k,x,y,z;
    for(i = 1; i<=n; i++)
            for(j = 1; j<=m; j++)
                for(k = 1; k<=m; k++)
                    scanf("%d",&a[i][j][k]);
        for(i = 0; i<=n; i++)
        {
            for(j = 0; j<=n; j++)
            {
                if(i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = inf;
            }
        }
        for(i = 1; i<=n; i++)
        {
            for(j = 1; j<=n; j++)
            {
                if(i==j)
                    continue;
                memset(tem,0,sizeof(tem));
                for(x = 1; x<=m; x++)//ç©éµç¸ä¹
                {
                    for(y = 1; y<=m; y++)
                    {
                        tem[x][y] = 0;
                        for(z = 1; z<=m; z++)
                        {
                            tem[x][y]+=a[i][x][z]*a[j][z][y];
                        }
                    }
                }
                for(x = 1; x<=n; x++)
                {
                    if(x == i || x == j)
                        continue;
                    int flag = 1;
                    for(y = 1; y<=m; y++)
                    {
                        for(z=1; z<=m; z++)
                        {
                            if(tem[y][z]!=a[x][y][z])
                            {
                                flag = 0;
                                break;
                            }
                        }
                        if(!flag)
                            break;
                    }
                    if(flag)
                        map[i][x] = 1;
                }
            }
        }
        Floyd();
}

int main()
{
    int i,k,j,x,y,z;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m == 0)
            break;
        getmap();
        scanf("%d",&z);
        while(z--)
        {
            scanf("%d%d",&x,&y);
            if(map[x][y] == inf)
                printf("Sorry\n");
            else
                printf("%d\n",map[x][y]);
        }
    }

    return 0;
}
