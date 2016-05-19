#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 3000005
int arr[10005],a[maxn];
int lowbit(int x)  //判断最右边1的位置
{
    return x&(-x);
}
void update(int x,int val) //更新c[i]的值
{
    while(x<10001)
    {
        arr[x]+=val;
        x+=lowbit(x);
    }
}
int getsum(int x)  //求和c[1]+...+c[x]
{
    int ans=0;
    while(x>0)
    {
        ans+=arr[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    __int64 ans;
    int i,j,n,m,x,y;
    char c;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        memset(arr,0,sizeof(arr));
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            update(a[i],1);
            ans+=getsum(a[i]-1);
        }
        scanf("%d",&m);
        while(m--)
        {
            getchar();
            scanf("%c",&c);
            if(c=='Q') printf("%I64d\n",ans);
            if(c=='R')
            {
                scanf("%d%d",&x,&y);
                x++;y++;  //下标从1开始
                int temp=a[x];
                for(i=x;i<y;i++)
                {
                    a[i]=a[i+1];
                    if(a[i]>temp) ans--;  //注意
                    if(a[i]<temp) ans++;
                }
                a[y]=temp;
            }
        }
    }
    return 0;
}