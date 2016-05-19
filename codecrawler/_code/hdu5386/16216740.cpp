#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int xx;
    int yy;
    int zz;
} L[501],H[501];

int map1[110][110];
int map2[110][110];
int v[510];
int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(v,0,sizeof(v));
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&map1[i][j]);
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&map2[i][j]);
            }
        }
        int xx,yy;
        char str[5];
        int h = 1;
        int l = 1;
        for(int i=1; i<=m; i++)
        {
            scanf("%s%d%d",str,&xx,&yy);
            if(strcmp(str,"H") == 0)
            {
                H[h].xx = xx;
                H[h].yy = yy;
                H[h].zz = i;
                h++;
            }
            else
            {
                L[l].xx = xx;
                L[l].yy = yy;
                L[l].zz = i;
                l++;
            }
        }
        int a[502];
        int tt = 1;
        for(int ii=1; ii<=n; ii++)
        {
            for(int i=1; i<=n; i++)
            {
                int flag = 0;
                int ans = 0;
                int pp;
                for(int j=1; j<=n; j++)
                {
                    if(ans == 0 && map2[i][j]!=0)
                    {
                        ans = map2[i][j];
                        pp = i;
                    }
                    else if(ans != map2[i][j] && map2[i][j] != 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    int pf = 0;
                    for(int j=1; j<h; j++)
                    {
                        if(H[j].xx == pp && H[j].yy == ans)
                        {
                            a[tt] = H[j].zz;
                            v[H[j].zz] = 1;
                            tt++;
                            pf = 1;
                            break;
                        }
                    }
                    if(pf == 1)
                    {
                        for(int j=1; j<=n; j++)
                        {
                            map2[pp][j] = 0;
                        }
                    }
                }
                flag = 0;
                ans = 0;
                for(int j=1; j<=n; j++)
                {
                    if(ans == 0 && map2[j][i]!=0)
                    {
                        ans = map2[j][i];
                        pp = i;
                    }
                    else if(ans != map2[j][i] &&map2[j][i] != 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    int pf = 0;
                    for(int j=1; j<l; j++)
                    {
                        if(L[j].xx == pp && L[j].yy == ans)
                        {
                            a[tt] = L[j].zz;
                            v[L[j].zz] = 1;
                            tt++;
                            pf = 1;
                            break;
                        }
                    }
                    if(pf == 1)
                    {
                        for(int j=1; j<=n; j++)
                        {
                            map2[j][pp] = 0;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(v[i] == 0)
            {
                printf("%d ",i);
            }
        }
        for(int i=tt-1;i>=1;i--)
        {
            if(i == 1)
            {
                printf("%d\n",a[i]);
            }
            else
            {
                printf("%d ",a[i]);
            }
       }

    }
    return 0;
}