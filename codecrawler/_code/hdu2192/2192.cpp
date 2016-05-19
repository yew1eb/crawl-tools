#include"stdio.h"
#include"string.h"
struct node
{
    int t;
    int n;
}A[10001];
int main()
{
    int T;
    int n;
    int cnt;
    int i,a;
    int j,k;
    scanf("%d",&T);
    while(T--)
    {
        memset(A,0,sizeof(A));
        k=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            for(j=0;j<k;j++)
            {
                if(A[j].n==a)
                {
                    A[j].t++;break;
                }
            }
            if(j==k)
            {
                A[k].n=a;
                A[k].t++;
                k++;
            }
        }
        int ans;
        ans=0;
        for(i=0;i<k;i++)
        {
            if(ans<A[i].t)
                ans=A[i].t;
        }
        printf("%d\n",ans);
    }
    return 0;
}