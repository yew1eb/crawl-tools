#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,n;
    int l,c,t;
    double vr,vt1,vt2;
    double p[101],dp[101];
    double tmp,min,len;
    while(cin>>l)
    {
       cin>>n>>c>>t;
       cin>>vr>>vt1>>vt2;
       p[0]=0;dp[0]=0;
       for(i=1;i<=n;i++)
           cin>>p[i];
       p[i]=l;
       if(n>=1) c>=p[1]?dp[1]=p[1]/vt1:dp[1]=c/vt1+(p[1]-c)/vt2;
       for(i=1;i<=n+1;i++)
       {
           min=1000000;
           for(j=0;j<i;j++)
           {
              len=p[i]-p[j];
              tmp=(c>=len)?dp[j]+len/vt1:dp[j]+c/vt1+(len-c)/vt2;
              if(j>0) tmp+=t;
              if(min>tmp) min=tmp;
           }
           dp[i]=min;
       }
       (dp[n+1]>l*1.0/vr)? printf("Good job,rabbit!\n"):printf("What a pity rabbit!\n");
    }
    
    return 0;
}