#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dis[35][35];
int a[10],vis[10],stay;

int main()
{
    int t,i,j;
    while(~scanf("%d",&t),t)
    {
        for(i = 0; i<t; i++)
        {
            for(j = 0; j<t; j++)
            {
                scanf("%d",&dis[i][j]);
            }
        }
        int n;
        scanf("%d%*c",&n);
        char c[10];
        int k,l = 0,sum = 0,stay = 0,to;
        while(n--)
        {
            scanf("%s",c);
            if(c[0] == 'U')
            {
                scanf("%d",&k);
                if(k == stay || l>=7)
                    continue;
                vis[l] = 1;
                a[l++] = k;
            }
            else if(c[0] == 'G')
            {
                if(!l)
                    continue;
                to = a[0];
                int t = l;
                sum+=dis[stay][to];
                for(i = 0; i<t; i++)
                {
                    if(a[i] == to)
                    {
                        vis[i] = 0;
                        l--;
                    }
                }
                j = 0;
                for(i = 0; i<t; i++)
                {
                    if(vis[i])
                    {
                        vis[i] = 0;
                        vis[j] = 1;
                        a[j++] = a[i];
                    }
                }
                stay = to;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
