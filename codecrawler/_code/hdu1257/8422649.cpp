#include <stdio.h>
int f[1004];
int a[1004];
int main()
{
    int n, i, j, ans;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n; i++)
            scanf("%d",&a[i]);
        for(i=0;i<n; i++)
        {
            ans = 0;
            for(j=0;j<i;j++)
                if(a[i]>a[j]&&f[j]>ans)
                    ans = f[j];
            f[i] = ans + 1;
        }
        ans = 0;
        for(i=0;i<n; i++)
            if(ans<f[i])
                ans = f[i];
        printf("%d\n",ans);
    }
    return 0;
}

