#include<iostream>
#include<cstdio>
using namespace std;

int a[1010];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,n,ans1=0,ans2=0,flag=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i&1)
                ans1+=a[i];
            else
                ans2+=a[i];
        }
        if(ans1!=ans2)
            printf("No\n");
        else
        {
            for(i=0;i<n;i++)
                if(a[i]!=a[n-1-i])
                {
                    flag=0;
                    break;
                }
            if(flag)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
