#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
LL C[13][13];
int K;
struct Matrix{
    LL m[13][13];
}E,D[8],O;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%mod;
        else b/=2,a=(a*a)%mod;
    }
    return ans;
}
void init(){
    for(int i=1;i<=12;i++){
        for(int j=1;j<=12;j++)
            E.m[i][j]=(i==j);
    }
    memset(C,0,sizeof(C));
    for(int i=1;i<=12;i++){
        C[i][0]=C[i][i]=1;
        C[i][1]=i;
        for(int j=2;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    C[0][0]=1;
    for(int i=1;i<=12;i++){
        for(int j=0;j<=i;j++)
            C[i][j]=(C[i][j]*Pow(7,j))%mod;
    }
    memset(O.m,0,sizeof(O.m));
    for(int i=1;i<=K;i++){
        for(int j=i;j<=K;j++){
            O.m[i][j]=C[K-i][j-i];
        }
    }
    for(int i=1;i<=7;i++){
        //memset(D[i].m,0,sizeof(D[i].m));
        D[i].m[K][1]=1;
        for(int j=K-1;j>=1;j--)
            D[i].m[j][1]=(D[i].m[j+1][1]*i)%mod;
    }
}
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=K;k++)
                ans.m[i][j]=(ans.m[i][j]+(A.m[i][k]*B.m[k][j])%mod)%mod;
        }
    }
    return ans;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=Multi(ans,A);
        else k/=2,A=Multi(A,A);
    }
    return ans;
}
Matrix Add(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++)
            ans.m[i][j]=(A.m[i][j]+B.m[i][j])%mod;
    }
    return ans;
}
Matrix Sum(Matrix A,LL k){
    if(k==0) return E;
    if(k==1) return Add(A,E);
    if(k&1) return Multi(Sum(A,k/2),Add(E,Pow(A,(k+1)/2)));
    else return Add(Multi(Sum(A,(k-1)/2),Add(E,Pow(A,k/2))),Pow(A,k));
}
LL get(LL x,LL n){
    LL ans=(Multi(Sum(O,n),D[x])).m[1][1]%mod;
    return ans;
}
void Print(Matrix A){
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++)
            cout<<A.m[i][j]<<" ";
        cout<<endl;
    }
}
char s[7][10]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main(){
    int T;
    scanf("%d",&T);
    char str[10];
    for(int cas=1;cas<=T;cas++){
        scanf("%s",&str);
        int st=1;
        for(;st<=7;st++){
            if(strcmp(s[st-1],str)==0)    break;
        }
        LL n,k,ans=0;
        scanf("%I64d%I64d",&n,&k);
        K=k+1;
        init();
        //Print(O);
        int i=st;
        int x=0;
        for(;i!=st+7;i++){
            x++;
            if(i==6 || i==7 || i==6+7 || i==7+7) continue;
            if( n-x<0) break;
            /*cout<<x<<":"<<(n-x)/7<<" "<<endl;
            cout<<get(x,(n-x)/7)<<endl;*/
            ans=(ans+get(x,(n-x)/7))%mod;
        }
        //cout<<"Case "<<cas<<": "<<ans<<endl;
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}