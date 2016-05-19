/*hdu4014Discount
给出N的数字 求不能由这个N个数字组合出的最小的数
思路:
首先思考：怎样给出N个数字 使可以组合出最多的连续的数字
1 2 4 8 16...2^n
联想 二进制 上面的数可以组合出1~2^(n+1)内的任何数
上面的情况已经是最稀疏的数字给出了，a1,a2..aM若密一些，则一定表示出sum[M]内的数字
归纳法：a[M+1]=m,则可以表示的数字 增加了[sum[M]+(m-sum[M)] , sum[M]+m],所以 m<=sum[M]+1;
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1001
int a[MAXN],sum[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        int i;
        for(i=1;i<=n;i++)
            if(a[i]>sum[i-1]+1)break;
        printf("%d\n",sum[i-1]+1);

    }
}