#include <stdio.h>
#include <string.h>
#define INF 100000000
double map[1010][1010];
int n;

void floyd()
{
    int i, j, k;
    for(k=1; k<=n; ++k)
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
                if(map[i][j]<map[i][k]*map[k][j])
                    map[i][j] = map[i][k]*map[k][j];
}

int main()
{
    int i, j, t;
    int a, b;
    while(~scanf("%d",&n))
    {
        memset(map, 0, sizeof map);
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                scanf("%lf",&map[i][j]);
            }
        }
        scanf("%d",&t);
        floyd();
        for(i=1; i<=t; ++i)
        {
            scanf("%d%d",&a,&b);
            if(!map[a][b])
                printf("What a pity!\n");
            else 
                printf("%.3f\n",map[a][b]);
        }
    }
 
    return 0; 
}
