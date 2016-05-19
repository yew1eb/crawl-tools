#include<cstdio>
#include<cmath>
int a[510];
int abs(int n)
{
    if(n<=0)
        return -n;
    else
        return n;
}
int main()
{
    int t,n,mid;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
            for(int j=0;j<n-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }

        int m=n/2,sum=0;
        mid=a[m];
        for(int i=0;i<n;i++)
        {
            int s=a[i]-mid;
            sum+=abs(s);
        }
        printf("%d\n",sum);
    }
    return 0;
}