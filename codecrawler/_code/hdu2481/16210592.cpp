#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#define N 1000000000
#define inf 1<<29
#define LL long long
#define eps 1e-7
#define pb(a) push_back(a)
#define ub(v,a) upper_bound(v.begin(),v.end(),a)
using namespace std;
struct Matrix{
    LL m[2][2];
}init;
LL MOD;
int n;
bool flag[40000]={0};
int prime[40000],cnt=0;
//ç±äºa,bçèå´é½æ¯10^18ï¼äºåæ¨¡æè®¡ç®a*b
LL MultMod(LL a,LL b){
    a%=MOD;
    b%=MOD;
    if(b<0) b+=MOD;
    if(a<0) a+=MOD;
    LL ret=0;
    while(b){
        if(b&1){
            ret+=a;
            if(ret>=MOD) ret-=MOD;
        }
        a=a<<1;
        if(a>=MOD) a-=MOD;
        b=b>>1;
    }
    return ret;
}
Matrix operator*(Matrix m1,Matrix m2){
    Matrix ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            ans.m[i][j]=0;
            for(int k=0;k<2;k++)
                ans.m[i][j]=(ans.m[i][j]+MultMod(m1.m[i][k],m2.m[k][j]))%MOD;
        }
    return ans;
}
Matrix operator^(Matrix m1,int b){
    Matrix ans;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            ans.m[i][j]=(i==j);
    while(b){
        if(b&1)
            ans=ans*m1;
        m1=m1*m1;
        b>>=1;
    }
    return ans;
}
//ä»¥ä¸ä¸ºç©éµå¿«éå¹ä¹
void Prime(){
    for(int i=2;i<=sqrt(N+1.0);i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=sqrt(N+1.0);j++)
            flag[i*j]=true;
    }
}
int Eular(int n){
    int ret=1;
    for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            n/=prime[i];ret*=prime[i]-1;
            while(n%prime[i]==0){n/=prime[i];ret=(ret*prime[i])%MOD;}
        }
    }
    if(n>1) ret*=n-1;
    return ret%MOD;
}
//ä»¥ä¸ä¸ºæç´ æ°è¡¨ï¼æ±æ¬§æå½æ°
LL Get_T(int k){
    if(k==1)  return 1;
    else if(k==2) return 5;
    Matrix temp=init^(k-2);
    LL f=3*temp.m[0][0]+temp.m[1][0];
    LL g=2*(f-(3*temp.m[0][1]+temp.m[1][1])-1);
    return (g+f)%MOD;
}
//è®¡ç®Tå¼
LL Polya(){
    LL sum=0;
    int i;
    //Burnsideå®çï¼æä¸¾å¾ªç¯ä¸ªæ°
    for(i=1;i*i<n;i++)
        if(n%i==0){
            sum=(sum+MultMod(Eular(i),Get_T(n/i)))%MOD;
            sum=(sum+MultMod(Eular(n/i),Get_T(i)))%MOD;
        }
    if(i*i==n) sum=(sum+MultMod(Get_T(i),Eular(i)))%MOD;
    return sum/n;
}
int main(){
    Prime();
    //æé ç©éµ
    init.m[0][0]=3;init.m[0][1]=1;init.m[1][0]=-1;init.m[1][1]=0;
    while(scanf("%d%I64d",&n,&MOD)!=EOF){
        MOD=(LL)n*MOD;
        printf("%I64d\n",Polya()%(MOD/n));
    }
    return 0;
}