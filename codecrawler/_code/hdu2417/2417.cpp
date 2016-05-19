#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
int m[129];
int v[3009];
int h[3009];
int re[109];
void solve(int n)
{
    memset(m,0,sizeof(m));
    memset(v,-1,sizeof(v));
    memset(h,0,sizeof(h));
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=0;j<=re[i];j++)
        {
            t=max(t,j+m[j]);
        }
        for(int j=0;j<=re[i];j++)
        {
            m[j] = max(m[j],t+j);
            m[re[i]*2-j] = max(m[re[i]*2-j],t+j);
        }
        for(int j=t-re[i];j<=t+re[i];j++)
        {
            int hh = 2*re[i]-(t>j?t-j:j-t);
            if(hh>=h[j])
            {
                h[j] = hh;
                v[j] = i;
            }
        }
    }
    bool vv[59];
    memset(vv,0,sizeof(vv));
    for(int i=0;v[i]!=-1;i++)
    {
         vv[v[i]] = true;
    }
    bool ou = false;
    for(int i=0;i<n;i++)
    {
        if(vv[i])
        {
            if(ou) printf(" ");
            printf("%d",i+1);
            ou= true;
        }
    }
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        scanf("%d",&re[i]),re[i]=re[i]*2;
        solve(n);
    }
    return 0;
}