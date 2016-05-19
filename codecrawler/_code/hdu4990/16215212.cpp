/*
ç©éµçä¸å¥½ç©ããã
æ³¨ï¼å¯å¾å°æ¨å¯¼å¬å¼f[n]=f[n-1]+2*f[n-2]+1;
|1  2  1|  |f[n-1]| |f[n]  |
|1  0  0|* |f[n-2]|=|f[n-1]|
|0  0  1|  |  1   | |  1   |
å æ²¹ï¼ï¼ï¼
Time:2015-04-09 18:10
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL mod;
struct Matrix{
    LL mat[3][3];
    LL n;
    void Init(int _n){
        n=_n;
        memset(mat,0,sizeof(mat));
    }
    Matrix operator*(const Matrix &b)const{
        Matrix ret;
        ret.Init(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    ret.mat[i][j]+=mat[i][k]*b.mat[k][j];
                    ret.mat[i][j]%=mod;
                }
            }
        }
        return ret;
    }
};
Matrix pow_mat(Matrix a,int k){
    Matrix ret;
    ret.Init(a.n);
    for(int i=0;i<ret.n;i++)ret.mat[i][i]=1;
    while(k>0){
        if(k&1) ret=ret*a;

        a=a*a;
        k>>=1;
    }
    return ret;
}
int main(){
    LL n,m;
    Matrix trans;
    trans.Init(3);
    trans.mat[0][1]=2;
    trans.mat[0][0]=trans.mat[0][2]=trans.mat[1][0]=trans.mat[2][2]=1;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        mod=m;
        Matrix ans,f;
        f.Init(3);ans.Init(3);
        f.mat[0][0]=1;f.mat[1][0]=0;f.mat[2][0]=1;//f[1][0]=
        ans=pow_mat(trans,n-1);
        /*for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("%d ",ans.mat[i][j]);
            }puts("");
        }*/
        ans=ans*f;
        printf("%lld\n",ans.mat[0][0]);
    }
return 0;
}
