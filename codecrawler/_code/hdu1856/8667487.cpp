#include <stdio.h>
#include <string.h>
#define MAX 100005
int f[MAX];
int  rank[MAX];//¼¯ºÏÄÚÔªËØ¸öÊý

int find(int x){while(x!=f[x]) x=f[x]; return x;}
int main()
{
    int n, i, a, b, x, y;
    int max;
    while(~scanf("%d",&n))
    {
        for(i=0; i<=MAX; i++) {f[i]=i;rank[i] = 1;}
        max = 1;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            x = find(a); y = find(b);
//            printf("   %d %d\n",rank[x],rank[y]);
            if(x !=y)
            {
                if(rank[x]>rank[y])
                {
                    rank[x] += rank[y];
                    if(rank[x]>max) max = rank[x];
                    f[y] = x;
                }
                else
                {
                    rank[y] += rank[x];
                    if(rank[y]>max) max = rank[y];
                    f[x] = y;
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
