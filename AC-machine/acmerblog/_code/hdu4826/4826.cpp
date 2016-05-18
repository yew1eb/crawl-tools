/****************************************
*****************************************
*        Author:Tree                    *
*From :http://blog.csdn.net/lttree      *
* Title : Labyrinth                     *
*Source: hdu 4826                       *
* Hint  : DP                            *
*****************************************
****************************************/
#include <stdio.h>
int Map[101][101],dp1[101],dp2[101];
int MAX(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t,T,m,n,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d%d",&m,&n);

        for(i=1;i<=m;++i)
            for(j=1;j<=n;++j)
                scanf("%d",&Map[i][j]);

        // step1 算出第一列的dp数组
        for( i=2;i<=m;++i )
            Map[i][1]+=Map[i-1][1];

        // 第二列开始向后算
        for( j=2;j<=n;++j )
        {
            // 相应初始化
            dp1[0]=dp2[0]=dp1[m+1]=dp2[m+1]=-999999;
            // 先从下向上算，存到dp1数组中
            for( i=m;i>=1;--i )
                dp1[i]=MAX( dp1[i+1],Map[i][j-1])+Map[i][j];
            // 再从上向下算，存到dp2数组中
            for( i=1;i<=m;++i )
                dp2[i]=MAX( dp2[i-1],Map[i][j-1])+Map[i][j];
            // 比较 两者，存最大的金钱数量
            for( i=1;i<=m;++i )
                Map[i][j]=MAX( dp1[i],dp2[i] );
        }
        printf("Case #%d:\n%d\n",t,Map[1][n]);
    }
    return 0;
}
