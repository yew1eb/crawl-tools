/*
 *=====================
 *File Name:hdu4507.cpp
 *Author: qqspeed
 *Date: 2014å¹´ 07æ 21æ¥ ææä¸ 12:38:21 CST
 *=====================
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define red(i,s,t) for(int i=s-1;i>=t;i--)
#define ree(i,now) for(int i=head[now];i!=-1;i=edge[i].next)
#define clr(a,v) memset(a,v,sizeof a)
#define L t<<1
#define R t<<1|1
#define MID int mid=(l+r)>>1
#define lowbit(x) (x&(-x))
#define SQR(a) ((a)*(a))

inline int input(){
    int ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return isN?-ret:ret;
}

inline void output(int x){    
    if(x<0){    
        putchar('-');x=-x;    
    }    
    int len=0,data[11];    
    while(x){    
        data[len++]=x%10;x/=10;    
    }    
    if(!len)    data[len++]=0;    
    while(len--)   
        putchar(data[len]+48);    
    putchar('\n');  
}  

const ll mod=1000000007;
const ll ivr=166666668;

pair<ll,pair<ll,ll> > dp[20][7][7][2];
ll l,r;
int t,bit[20],len;
ll ten[20];

inline ll Pow(ll a,ll b){
    ll d=1,t=a;
    while(b){
        if(b&1) d=d*t%mod;
        b>>=1;
        t=t*t%mod;
    }
    return d;
}

inline ll Sum(ll n){
    n%=mod;
    return (n)*((n+1)%mod)%mod*((2*n+1)%mod)%mod*ivr%mod;
}

inline pair<ll,pair<ll,ll> >dfs(int i,bool e,int st1,int st2,int st3){
    if(i<0) return make_pair(st1==0 || st2==0 || st3==1,make_pair(0,0));
    if(!e && dp[i][st1][st2][st3].first!=-1) return dp[i][st1][st2][st3];
    int v=(e?bit[i]:9);
    pair<ll,pair<ll,ll> > ans,tmp;
    ans=make_pair(0,make_pair(0,0));
    rep(j,0,v+1){
        tmp=dfs(i-1,e&&(j==v),(st1+j)%7,(st2*10+j)%7,st3|(j==7));
        ans.first = (ans.first+tmp.first)%mod;
        ans.second.first = (ans.second.first+tmp.second.first+ten[i]*j%mod*tmp.first)%mod;
        ans.second.second = (ans.second.second + tmp.second.second + ten[i]*j%mod*ten[i]%mod*j%mod*tmp.first%mod + 2*ten[i]*j%mod*tmp.second.first%mod)%mod;
    }
    if(!e) dp[i][st1][st2][st3]=ans;
    return ans;
}

inline ll solve(ll n){
    ll sum=Sum(n);
    if(n<=0) return 0;
    len=0;
    while(n){
        bit[len++]=n%10;
        n/=10;
    }
    return (sum-dfs(len-1,1,0,0,0).second.second+mod)%mod;
}

int main(){
    rep(i,0,20) rep(j,0,7) rep(k,0,7) rep(r,0,2) dp[i][j][k][r]=make_pair(-1,make_pair(0,0));
    ten[0]=1;
    rep(i,1,20) ten[i]=ten[i-1]*10%mod;
    t=input();
    while(t--){
        cin>>l>>r;
        cout<<(solve(r)-solve(l-1)+mod)%mod<<endl;
    }
    return 0;
}
