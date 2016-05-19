/************************************************
 * By: chenguolin                               * 
 * Date: 2013-08-23                             *
 * Address: http://blog.csdn.net/chenguolinblog *
 ***********************************************/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1024;
const int N = 2;

struct Matrix{
    int mat[N][N];
    Matrix operator*(const Matrix& m)const{
        Matrix tmp;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                tmp.mat[i][j] = 0;
                for(int k = 0 ; k < N ; k++){
                    tmp.mat[i][j] += mat[i][k]*m.mat[k][j]%MOD;
                    tmp.mat[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
};

int Pow(Matrix &m , int k){
    if(k == 1)
        return 9;
    k--;
    Matrix ans;
    memset(ans.mat , 0 , sizeof(ans.mat));
    for(int i = 0 ; i < N ; i++)
        ans.mat[i][i] = 1;
    while(k){
        if(k&1)
            ans = ans*m;
        k >>= 1;
        m = m*m;
    }
    int x = (ans.mat[0][0]*5+ans.mat[0][1]*2)%MOD;
    return (2*x-1)%MOD;
}

int main(){
    int cas , n;
    Matrix m;
    scanf("%d" , &cas);
    while(cas--){
        scanf("%d" , &n); 
        m.mat[0][0] = 5 ; m.mat[1][1] = 5;
        m.mat[1][0] = 2 ; m.mat[0][1] = 12;
        printf("%d\n" , Pow(m , n));
    }
}