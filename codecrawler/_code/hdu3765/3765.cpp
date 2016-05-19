
#include <stdio.h>
#include <math.h>
int a[200];
int n;
int ans;
int sum[200];
void Divide(int p,int differ,int hav)//p为现在要拿的房子，differ为目前两个人房子价值的差距，hav为两个人共拿走的价值
{
    int i,j,n;
    if (differ==0)
    {
        if (hav>ans) ans=hav;
    }
    if (p<0) return;
    if (abs(differ)>sum[p]) return;//剪枝1：如果两个人拿到的差距比剩下的所有房子之和大，返回。
    if (sum[p]+hav<ans) return;//剪枝2：如果剩下的都加上还不能加到目前最大的答案ans，返回。
    Divide(p-1,differ+a[p],hav+a[p]);//给其中一个人
    Divide(p-1,differ-a[p],hav+a[p]);//给另一个人
    Divide(p-1,differ,hav);//拿去拍卖
}
int Solve()
{
    ans=0;
    Divide(n-1,0,0);
    return sum[n-1]-ans;
}
int main()
{
    int i,j;
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (i==0) sum[i]=a[i];
            else sum[i]=sum[i-1]+a[i];
        }
        printf("%d/n",Solve());
    }
    return 0;
}

 


其实递归是很好用的……






