/************************************************
 * By: chenguolin                               * 
 * Date: 2013-08-25                             *
 * Address: http://blog.csdn.net/chenguolinblog *
 ***********************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef __int64 int64;
const int MOD = 2008;
const int MAXN = 10000;
const int N = 30;

int n , pos;
int64 num[2*MAXN];
struct Edge{
    int64 x;
    int64 y;
};
Edge e[MAXN];

struct Matrix{
    int mat[N][N];
    Matrix operator*(const Matrix& m)const{
        Matrix tmp;
        for(int i = 0 ; i < pos ; i++){
            for(int j = 0 ; j < pos ; j++){
                tmp.mat[i][j] = 0;
                for(int k = 0 ; k < pos ; k++){
                    tmp.mat[i][j] += mat[i][k]*m.mat[k][j]%MOD;
                    tmp.mat[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
};
Matrix ma[MAXN];

int search(int64 x){
    int left = 0;
    int right = pos-1;
    while(left <= right){
        int mid = (left+right)>>1;
        if(num[mid] == x)
            return mid;
        else if(num[mid] < x)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}

void init(Matrix &m){
    memset(m.mat , 0 , sizeof(m.mat));
    sort(num , num+pos);
    pos = unique(num , num+pos)-num;
    for(int i = 0 ; i < n ; i++){
        int x = search(e[i].x);
        int y = search(e[i].y);
        m.mat[x][y]++;
    }
}

void Pow(Matrix m){
    ma[0] = m;
    for(int i = 1 ; i < MAXN ; i++)
        ma[i] = ma[i-1]*m; 
}

void solve(){
    Matrix m;
    init(m);
    Pow(m);

    int64 v1 , v2;
    int k , t1 , t2;
    scanf("%d" , &k);
    while(k--){
        scanf("%I64d%I64d%d%d" , &v1 , &v2 , &t1 , &t2); 
        if(t1 > t2 || t2 == 0){
            puts("0");
            continue;
        }
        int x = search(v1); 
        int y = search(v2); 
        if(x == -1 || y == -1){
            puts("0");
            continue;
        }
        int sum = 0;
        for(int i = t1-1 ; i < t2 ; i++){
            sum += ma[i].mat[x][y]%MOD;
            sum %= MOD;
        }
        printf("%d\n" , sum);
    }
}

int main(){
    while(scanf("%d" , &n) != EOF){
        pos = 0; 
        for(int i = 0 ; i < n ; i++){
            scanf("%I64d%I64d" , &e[i].x , &e[i].y);
            num[pos++] = e[i].x;
            num[pos++] = e[i].y;
        }
        solve();
    }
    return 0;
}