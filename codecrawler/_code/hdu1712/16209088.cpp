#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <ctime>  
#include <algorithm>  
#include <iostream>
#include <sstream>
#include <string>
#define oo 0x13131313   
using namespace std;
int n,m;
int A[101][101];
void input()
{
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
         scanf("%d",&A[i][j]);
}
void init()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
}
void ADD(int *ans,int *a,int *b)
{
    for(int i=0;i<=m;i++)
    {
        ans[i]=0;
        for(int j=0;j<=i;j++)
        {
            ans[i]=max(ans[i],a[j]+b[i-j]);
        }
    }
}
void solve()
{
    int ans=0;
    if(n>=2)
    {
        ADD(A[0],A[1],A[2]);
        for(int i=3;i<=n;i++)
        ADD(A[i-2],A[i-3],A[i]);
        for(int i=1;i<=m;i++)
        ans=max(ans,A[n-2][i]);
        printf("%d\n",ans);
    }
    else 
    {
        for(int i=1;i<=m;i++)
        ans=max(ans,A[1][i]);
        printf("%d\n",ans);
    }
}
int main()
{
//    init();
    while(cin>>n>>m&&(n||m))
    {
        input();
        solve();
    }
}
  