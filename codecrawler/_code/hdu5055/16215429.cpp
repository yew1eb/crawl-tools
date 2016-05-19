#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=105;
const int inf=101;
int a[maxm];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        int MIN=inf,w,i,temp,ok=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==1)
            {
                ok=1;
                MIN=min(MIN,a[i]);
            }
        }
        if(!ok)
        {
            printf("-1\n");
            continue;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(MIN==a[i])
            {
                w=i;
                break;
            }
        }
        int OK=1;
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i!=w)
            {
                cnt++;
                if(cnt==1&&a[i]==0)
                {
                    OK=0;
                    break;
                }
                else
                {
                    printf("%d",a[i]);
                }
            }
        }
        if(OK)
        {
            printf("%d\n",a[w]);
        }
        else
        {
            printf("-1\n");
        }

    }
    return 0;
}
