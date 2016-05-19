#include <iostream>
#include <cstdio>

using namespace std;

int a[1000000],n;

int dfs()
{
    for(int i = 0;i<n-1;i++)
    {
        if(!a[i])
        {
            a[i+1] = 1-a[i+1];
        }
    }
    return a[n-1];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0;i<n;i++)
            scanf("%d",&a[i]);
        if(dfs())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
