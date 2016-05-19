#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#define LL long long
#define MOD 1000000007
#define mp(a,b) make_pair(a,b)
using namespace std;
//é¿åº¦ï¼æ¯å¦æ7ï¼æ°å­å%7ï¼æ°å­%7
LL s1[20][2][7][7],s2[20][2][7][7],cnt[20][2][7][7];
int bit[20],len;
LL fac[20]={1};
pair<pair<int,int>,int> dfs(int len,int a,int b,int c,int limit){
    if(cnt[len][a][b][c]!=-1&&!limit) return mp(mp(cnt[len][a][b][c],s1[len][a][b][c]),s2[len][a][b][c]);
    if(!len){
        if(!a&&b&&c) cnt[len][a][b][c]=0LL;
        else cnt[len][a][b][c]=1LL;
        s1[len][a][b][c]=s2[len][a][b][c]=0LL;
        return mp(mp(cnt[len][a][b][c],s1[len][a][b][c]),s2[len][a][b][c]);
    }
    int up=limit?bit[len]:9;
    LL tcnt=0LL,ts1=0LL,ts2=0LL;
    for(int i=0;i<=up;i++){
        int nl=len-1,na=(a||i==7),nb=(b+i)%7,nc=(c*10+i)%7;
        LL f=(fac[len-1]*i)%MOD;
        pair<pair<int,int>,int> pre=dfs(nl,na,nb,nc,limit&&(i==up));
        ts1=(ts1+pre.first.second+pre.first.first*f)%MOD;
        ts2=(ts2+pre.second+(f*f%MOD)*pre.first.first+2*f*pre.first.second)%MOD;
        tcnt=(tcnt+pre.first.first)%MOD;
    }  
    if(!limit){
        cnt[len][a][b][c]=tcnt;
        s1[len][a][b][c]=ts1;
        s2[len][a][b][c]=ts2;
    }
    return mp(mp(tcnt,ts1),ts2);
}
LL sum(LL n){
    LL a=n,b=n+1,c=2*n+1;
    int x=3,y=2;
    if(a%x==0) a/=x,x=1;if(a%y==0) a/=y,y=1;  
    if(b%x==0) b/=x,x=1;if(b%y==0) b/=y,y=1;
    if(c%x==0) c/=x,x=1;if(c%y==0) c/=y,y=1;
    a%=MOD;b%=MOD;c%=MOD;
    return (a*b%MOD)*c%MOD;
}
LL slove(LL n){
    len=0;
    LL m=n;
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    return (sum(m)-dfs(len,0,0,0,1).second)%MOD;
}
int main(){
    for(int i=1;i<20;i++)
        fac[i]=(fac[i-1]*10)%MOD;
    int t;
    LL l,r;
    memset(cnt,-1,sizeof(cnt));
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&l,&r);
        //cout<<slove(r)<<" "<<slove(l-1)<<endl;
        printf("%I64d\n",((slove(r)-slove(l-1))%MOD+MOD)%MOD);
    }
    return 0;
}