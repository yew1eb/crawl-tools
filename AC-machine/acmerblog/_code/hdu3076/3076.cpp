#include<iostream>
using namespace std;
#define MAXN 2005
double dp[MAXN][MAXN];
double a[7],b[7];
double a_win,b_win;    
double ans;
int main()
{
    int n,m,i,j;
    double p,p1,p2;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
       for(i=1;i<=6;i++)
           scanf("%lf",&a[i]);
       for(i=1;i<=6;i++)
           scanf("%lf",&b[i]);
       a_win=0;
       for(i=2;i<=6;i++)
       {
           for(j=1;j<=i-1;j++)
               a_win+=a[i]*b[j];
       }
       b_win=0;
       for(i=2;i<=6;i++)
       {
           for(j=1;j<=i-1;j++)
               b_win+=b[i]*a[j];
       }
       p1=a_win;p2=b_win;p=1-a_win-b_win;
       if (p==1) {a_win=0;b_win=0;}
       else
       {
           a_win=p1/(1-p);
           b_win=p2/(1-p);
       }
       for(i=0;i<=n;i++)
           for(j=0;j<=m;j++)
               dp[i][j]=0;
     // cout<<a_win<<' '<<b_win<<endl;
     dp[0][0]=1;
      for(j=0;j<=m-1;j++)
         for(i=0;i<=n;i++)       
               if (i+j!=0)
           {
                   dp[i][j]=0;
                   if (j>0)
               dp[i][j]+=dp[i][j-1]*a_win;
                   if (i>0)
               dp[i][j]+=dp[i-1][j]*b_win;
           }
       ans=0;
       for(i=0;i<=n-1;i++)
           ans+=dp[i][m-1]*a_win;
     if (ans>1) ans=1;
       printf("%.6lf/n",ans);
    }
}