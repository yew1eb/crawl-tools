/**
[树状数组]hdu 2155 Matrix
二维树状数组，更新区间，查询点
详解见09年国家集训队论文 
http://www.cppblog.com/klion/archive/2010/05/25/116325.html?opt=admin
*/
#include <stdio.h>
#include <string.h>

#define N 1001
#define lowbit(i) (i) & (-i)
int mat[N][N],n;
void update(int x,int y)
{
    int i,j;
    for(i = x; i <= n; i += lowbit(i))
        for(j = y; j <= n; j += lowbit(j))
            mat[i][j] ^= 1;
}
int sum(int x,int y)
{
    int ans = 0,i,j;
    for(i = x; i > 0; i -= lowbit(i))
        for(j = y; j > 0; j -= lowbit(j))
            ans += mat[i][j];
    return ans;
}
int main()
{
    int t,q,x1,y1,x2,y2,res;
    char ask[4];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        memset(mat,0,sizeof(mat));
        while(q--)
        {
            scanf("%s%d%d",ask,&x1,&y1);
            if(ask[0] == 'Q')
            {
                res = sum(x1,y1);
                printf("%d\n",res&1);
                continue;
            }
            scanf("%d%d",&x2,&y2);
            ++x2;
            ++y2;
            update(x1,y1);
            update(x2,y1);
            update(x1,y2);
            update(x2,y2);
        }
        printf("\n");
    }
    return 0;
}