#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;
int f[N][12];

int main()
{
    int n, m, i,j, tmp, x, t;
    while(scanf("%d",&n),n)
    {
         memset(f,0,sizeof(f));
         m = 0;
         for(i=0; i<n; i++)
         {
             scanf("%d%d",&x,&t);
             f[t][x]++;
             if(t>m) m = t;
         }
//        for(i=1; i<=m; i++)
//        {
//            for(j=0; j<=10; j++)
//                printf("%d ",f[i][j]);
//            printf("\n");
//        }
        for(i=m-1; i>=0; i--)
        {
            f[i][0] +=max(f[i+1][0], f[i+1][1]);
            for(j=1; j<=10; j++)
                f[i][j] += max( max(f[i+1][j-1],f[i+1][j]), f[i+1][j+1]);
        }
//        for(i=1; i<=m; i++)
//        {
//            for(j=0; j<=10; j++)
//                printf("%d ",f[i][j]);
//            printf("\n");
//        }
        printf("%d\n",f[0][5]);
    }
    return 0;
}
