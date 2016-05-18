#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 1<<29
#define LL long long
#define N 1000000000
#define MOD 1000000007
#define pb(a) push_back(a)
using namespace std;
int tot;
LL A,c;
LL inverse_4,inverse_k;
int prime[40000],cnt=0;
LL fac[1000][2];
bool flag[40000]={0};
vector<int>v;
void Prime(){
    for(int i=2;i<=sqrt(N+1.0);i++){
        if(flag[i])  continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=sqrt(N+1.0);j++)
            flag[i*j]=true;
    }
}
//以上素数表
LL extend_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0){x=1;y=0;return a;}
    LL gcd=extend_gcd(b,a%b,x,y);
    LL t=x;x=y;
    y=t-a/b*y;
    return gcd;
}
LL Get_inverse(LL num){
    LL x,y;
    LL gcd=extend_gcd(num,MOD,x,y);
    return (x%MOD+MOD)%MOD;
}
//以上求逆元
LL Eular(LL n){
    LL ret=1;
   for(int i=0;i<tot&&fac[i][0]*fac[i][0]<=n;i++){
        if(n%fac[i][0]==0){
            n/=fac[i][0];ret*=fac[i][0]-1;
            while(n%fac[i][0]==0){n/=fac[i][0];ret*=fac[i][0];}
        }
    }
    if(n>1) ret*=n-1;
    return (ret%MOD);
}
//以上求欧拉函数，注意要直接用之前分解的因子，不然会TLE
LL PowMod(LL a,LL b){
    LL ret=1;
    a%=MOD;
    while(b){
        if(b&1) ret=((LL)ret*a)%MOD;
        a=((LL)a*a)%MOD;
        b>>=1;
    }
    return ret;
}
//快速幂
void get_fact(LL t){
    for(int i=0;i<cnt&&prime[i]*prime[i]<=t;i++){
        while(t%prime[i]==0){
            t/=prime[i];
            v.pb(prime[i]);
        }
    }
    if(t>1) v.pb(t);
}
//分解因子
void get_union(){
    sort(v.begin(),v.end());
    tot=0;
    fac[tot][0]=v[0];fac[tot++][1]=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==fac[tot-1][0])
            fac[tot-1][1]++;
        else{
            fac[tot][0]=v[i];
            fac[tot++][1]=1;
        }
    }
}
//将A-1和A+1的因子整合在一起
LL ret_A;
void dfs(int idx,LL num,LL cnt_B,LL K){
    if(idx>=tot){
        ret_A=(ret_A+PowMod(cnt_B,K/num)*Eular(num)%MOD)%MOD;
        return ;
    }
    for(int i=0;i<=fac[idx][1];i++){
        dfs(idx+1,num,cnt_B,K);
        num*=fac[idx][0];
    }
}
//搜索K的因子，欧拉函数优化，第二个Polya
LL get_A(LL K,LL cnt_B){
    ret_A=0;
    dfs(0,1,cnt_B,K);
    return (((ret_A*inverse_k)%MOD)*c)%MOD;
}
//用B*B的数量给K个环染色
LL get_B(LL B){
    LL ans=PowMod(c,(LL)B*B);
    ans=(ans+2*PowMod(c,((LL)B*B+3)/4))%MOD;
    ans=(ans+PowMod(c,((LL)B*B+1)/2))%MOD;
    return (ans*inverse_4)%MOD;
}
//B*B的正方形染色,4种旋转
LL ans;
void dfsB(int idx ,LL nowB){
    if(idx>=tot){
        LL cnt_B=get_B(nowB);
        LL K=(A*A-1)/nowB/nowB;
        inverse_k=Get_inverse(K);
        ans=(ans+get_A(K,cnt_B))%MOD;
        return ;
    }
    LL temp=fac[idx][1];
    //因子每次减少2，因为是B*B，而且剩余的用作搜索K的因子
    for(int i=0;i<=temp;i+=2,fac[idx][1]-=2){
        dfsB(idx+1,nowB);
        nowB*=fac[idx][0];
    }
    fac[idx][1]=temp;
}
//以上搜索B
LL slove(){
    v.clear();
    get_fact(A-1);
    get_fact(A+1);
    get_union();
    ans=0;
    dfsB(0,1);
    return ans;
}
int main(){
    int t,cas=0;
    Prime();
    inverse_4=Get_inverse(4);
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&A,&c);
        printf("Case %d: ",++cas);
        if(A==1)  printf("%I64d\n",c);
        else
            printf("%I64d\n",slove());
    }
    return 0;
}