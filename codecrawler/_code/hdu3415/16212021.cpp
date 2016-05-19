#include <stdio.h>

#define INF 999999999

typedef struct
{
    int val,num,now;
}Queue;

int a[200005];
int sum[200005];
Queue q[200005];

int main()
{
    int front,tail,k,i,j,n,T;
    Queue ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=n+1;i<=2*n;i++)
        {
            a[i]=a[i-n];
        }
        n=2*n;
        sum[0]=0;
        for (i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        front=tail=1;
        ans.val=-INF;
        for (i=1;i<=n;i++)
        {
            while(tail>front && sum[i-1]<q[tail-1].val) tail--;
            q[tail].val=sum[i-1];
            q[tail].num=i-1;
            tail++;
            if (i-q[front].num>k) front++;
            if (sum[i]-q[front].val>ans.val)
            {
                ans.val=sum[i]-q[front].val;
                ans.num=q[front].num+1;
                ans.now=i;
            }
        }
        printf("%d %d %d\n",ans.val,ans.num,ans.now-n/2>0?ans.now-n/2:ans.now);
    }
    return 0;
}
