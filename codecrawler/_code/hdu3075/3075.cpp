#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define inf 0x7777777
#define int long long

using namespace std;
int const nMax = 500010;

int a[nMax];
int dp[nMax];
int sum[nMax];
int n,M;

int q[nMax],he,ta;
int dy(int i,int j){
    return dp[i]+sum[i]*sum[i]-dp[j]-sum[j]*sum[j];
}
int dx(int i,int j){
    return 2*(sum[i]-sum[j]);
}
void query(int i){
    while(he<ta){
        if(dy(q[he+1],q[he])<=sum[i]*(dx(q[he+1],q[he])))he++;
        else break;
    }
    dp[i]=dp[q[he]]+(sum[i]-sum[q[he]])*(sum[i]-sum[q[he]])+M;
    return ;
}
void insert(int i){
    while(he<ta){
        int y2=q[ta],y1=q[ta-1];
        if(dy(y2,y1)*(dx(i,y2))>=dy(i,y2)*dx(y2,y1))ta--;
        else break;
    }
    q[++ta]=i;
    return ;
}

main()
{
    while(~scanf("%I64d%I64d",&n,&M)){
        sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        dp[0]=0;
        ta=he=0;
        q[0]=0;
        int ans=inf;
        for(int i=1;i<=n;i++){
            query(i);
            ans=min(ans,dp[i]);
            insert(i);
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}