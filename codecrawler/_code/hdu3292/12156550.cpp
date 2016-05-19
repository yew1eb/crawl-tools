/*
 * Author: yew1eb
 * Created Time:  2014/11/11 21:23:26
 * File Name: d:\code\t.cpp
 */
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int X, Y, N;
const int mod = 8191;
void find(){
    Y = 1;
    while(1){
        X = (int)sqrt(N*Y*Y+1 + 0.5);
        if(X*X-N*Y*Y==1) return ;
        Y++;
    }
}

struct Mat{
    int x[2][2];
    void init(){ memset(x, 0, sizeof x ); }
};
Mat Mat_mult(Mat a, Mat b){
    Mat c;
    c.init();
    for(int i=0; i<2; ++i)
        for(int j=0; j<2; ++j)
            for(int k=0; k<2; ++k)
                c.x[i][j] = (c.x[i][j] + a.x[i][k]*b.x[k][j]) % mod;
    return c;
}

Mat Mat_pow(Mat a, int k){
    Mat ret;
    ret.init(); ret.x[0][0] = ret.x[1][1] = 1;
    while(k){
        if(k&1) ret = Mat_mult(ret, a);
        a = Mat_mult(a, a);
        k>>=1;
    }
    return ret;
}

void gao(int k){
    Mat A;
    A.x[0][0] = X; A.x[0][1] = N*Y; A.x[1][0] = Y; A.x[1][1] = X;
    A = Mat_pow(A, k-1);
    int ans = (A.x[0][0]*X%mod + A.x[0][1]*Y%mod)%mod;
    printf("%d\n", ans);
}
int main(){
    int n, k;
    while(~scanf("%d%d", &N, &k)){
        int tmp = sqrt(N+0.5);
        if(tmp*tmp==N) {
            puts("No answers can meet such conditions");
            continue;
        }
        find();
        gao(k);
    }
    return 0;
}
