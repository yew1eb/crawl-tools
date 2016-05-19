#include "iostream"
#include "cstdio"
#include "string.h"
#include "math.h"
using namespace std;

int a[110000],n,x[110000],y[110000];
bool ins()
{
    x[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=a[i-1])
            x[i]=x[i-1]+1;
        else
            x[i]=1;
    }
    y[n]=1;
    for(int i=n-1;i>0;i--)
    {
        if(a[i]<=a[i+1])
            y[i]=y[i+1]+1;
        else
            y[i]=1;
    }
    for(int i=2;i<n;i++)
    {
        if(a[i-1]<=a[i+1]&&x[i-1]+y[i+1]>=n-1)
            return true;
    }
    if(x[n-1]==n-1||y[2]==n-1||x[n]==n)
        return true;
    return false;
}

bool de()
{
    x[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=a[i-1])
            x[i]=x[i-1]+1;
        else
            x[i]=1;
    }
    y[n]=1;
    for(int i=n-1;i>0;i--)
    {
        if(a[i]>=a[i+1])
            y[i]=y[i+1]+1;
        else
            y[i]=1;
    }
    for(int i=2;i<n;i++)
    {
        if(a[i-1]>=a[i+1]&&x[i-1]+y[i+1]>=n-1)
            return true;
    }
    if(x[n-1]==n-1||y[2]==n-1||x[n]==n)
        return true;
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <=n; i++)
            scanf("%d", &a[i]);
        if (ins() || de())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}