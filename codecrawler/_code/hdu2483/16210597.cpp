#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=303;
int e[maxn][maxn];
int r[maxn][maxn],c[maxn][maxn];//r[i][j]è¡¨ç¤º(i,j)å³è¾¹æå ä¸ªè¿ç»­ç1ï¼c[i][j]è¡¨ç¤º(i,j)ç¹ä¸é¢æå ä¸ªè¿ç»­1
int f[maxn][maxn];//f[i][j]è¡¨ç¤º(i,j)ä¸å³ä¸è§ææç©å½¢çå
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,i,j,k,d,sum,t;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&e[i][j]);
        }

        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        //è®¡ç®r[i][j]
        for(i=0;i<n;i++)
        {
            d=0;
            for(j=m-1;j>=0;j--)
            {
                if(e[i][j]==1)d++;
                else d=0;
                r[i][j]=d;
            }
        }
        //è®¡ç®c[i][j];
        for(j=0;j<m;j++)
        {
            d=0;
            for(i=n-1;i>=0;i--)
            {
                if(e[i][j]==1)d++;
                else d=0;
                c[i][j]=d;
            }
        }
        //è®¡ç®f[i][j];
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                f[i][j]=f[i][j+1]+f[i+1][j]-f[i+1][j+1]+e[i][j];
            }
        }
        /*printf("***********\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("%d ",f[i][j]);
            printf("\n");
        }
        printf("*************\n");*/
        //è®¡ç®ç¬¦åæ¡ä»¶çæ¹æ ¼æ°
        int ans=0;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<m-1;j++)
            {
                if(e[i][j]==0)continue;
                t=min(r[i][j],c[i][j]);
                //if(i==0&&j==0)printf("*%d\n",t);
                for(k=2;k<=t;k++)
                {
                    //if(k==4)printf("**%d %d\n",r[i+k-1][j],c[i][j+k-1]);
                    if(r[i+k-1][j]<k||c[i][j+k-1]<k)continue;
                    sum=f[i+1][j+1]-f[i+k-1][j+1]-f[i+1][j+k-1]+f[i+k-1][j+k-1];
                    //if(k==4)
                    //printf("***%d %d %d %d\n",f[i+1][j+1],f[i+k-1][j+1],f[i+1][j+k-1],f[i+k-1][j+k-1]);
                    if(abs(2*sum-(k-2)*(k-2))<=1)ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
