#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int a[111][111],n,m;
int ans;
 int mmin[22][11];
int main()
{
    int i,j,k;
    while(cin>>n>>m)
    {
        ans=99999999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) cin>>a[i][j];
        }
        for(k=0;k<n;k++)
            for(i=0;i<m;i++) 
                mmin[k][i]=99999999;
        for(k=0;k<m;k++) mmin[0][k]=0;
        for(k=1;k<n;k++)
        {
          for(i=0;i<m;i++)
          {
            for(j=0;j<m;j++)
            {
                if(mmin[k][i]>mmin[k-1][j]+abs(a[k][i]-a[k-1][j]))
                    mmin[k][i]=mmin[k-1][j]+abs(a[k][i]-a[k-1][j]);
            }
          }
        }
        for(i=0;i<m;i++)
            if(ans>mmin[n-1][i]) ans=mmin[n-1][i];
        printf("%d\n",ans);
    }
    return 0;
}