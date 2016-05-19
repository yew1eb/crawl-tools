#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define MOD 8191

bool pell( int D, int& x, int& y ) {
    int sqrtD = sqrt(D + 0.0);
    if( sqrtD * sqrtD == D ) return false;
    int c = sqrtD, q = D - c * c, a = (c + sqrtD) / q;
    int step = 0;
    int X[] = { 1, sqrtD };
    int Y[] = { 0, 1 };
    while( true ) {
        X[step] = a * X[step^1] + X[step];
        Y[step] = a * Y[step^1] + Y[step];
        c = a * q - c;
        q = (D - c * c) / q;
        a = (c + sqrtD) / q;
        step ^= 1;
        if( c == sqrtD && q == 1 && step ) {
            x = X[0], y = Y[0];
            return true;
        }
    }
}
int a[40][2][2];
int b[2][2];
int c[2][2];
int solve(int E){
    for (int i=1;i<=35;i++)
        for (int j=0;j<=1;j++)
            for (int k=0;k<=1;k++)
                for (int t=0;t<=1;t++)
                    a[i][j][k]=(a[i][j][k]+a[i-1][j][t]*a[i-1][t][k])%MOD;
    int l=0;
    b[0][0]=b[1][1]=1;
    b[0][1]=b[1][0]=0;
    while (E>0){
        if (E%2){
            memset(c,0,sizeof(c));
            for (int i=0;i<=1;i++)
                for (int j=0;j<=1;j++)
                    for (int t=0;t<=1;t++)
                        c[i][j]=(c[i][j]+b[i][t]*a[l][t][j])%MOD;
            memcpy(b,c,sizeof(c));
        }
        l++;
        E/=2;
    }
    return (b[0][0]*a[0][0][0]+b[0][1]*a[0][1][0])%MOD;
}

int main(){
    int N,K;
    while (scanf("%d%d",&N,&K)==2){
        int x,y;
        if (!pell(N,x,y)){
            printf("No answers can meet such conditions\n");
            continue;
        }
        memset(a,0,sizeof(a));
        a[0][0][0]=x%MOD;
        a[0][0][1]=N*y%MOD;
        a[0][1][0]=y%MOD;
        a[0][1][1]=x%MOD;
        printf("%d\n",solve(K-1));

    }
    return 0;
}