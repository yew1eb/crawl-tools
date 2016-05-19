#include"stdio.h"
int f[2011][2011];
int main()
{
    int T;
    int x;
    int ans[2011];
    int i,l;


    f[1][1]=1;
    ans[1]=1;
    for(i=2;i<=2000;i++)
    {
        f[i][1]=1;
        f[i][i]=1;
        ans[i]=2;
        for(l=2;l<i;l++)                           //æéæ³¨æ:lä»2å°i-1éåã
        {
            f[i][l]=f[i-1][l-1]+f[i-1][l]*l;
            f[i][l]%=1000;
            ans[i]+=f[i][l];
        }
        ans[i]%=1000;
    }


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}