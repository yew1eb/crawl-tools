//  359 MS
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef int Type;
const int INF = 0x7fffffff;
const int VN  = 100;

struct Matrix{
    Type mat[VN][VN];
    int n, m;
    Matrix(){n=m=VN; memset(mat, 0, sizeof(mat));}
    Matrix(const Matrix&a){
        set_size(a.n, a.m);
        memcpy(mat, a.mat, sizeof(a.mat));
    }
    Matrix& operator = (const Matrix &a){
        set_size(a.n,a.m);
        memcpy(mat, a.mat, sizeof(a.mat));
        return *this;
    }
    void set_size(int row, int column){n=row; m=column;}
    friend Matrix operator *(const Matrix &a,const Matrix &b){
        Matrix ret;
        ret.set_size(a.n, b.m);
        for(int i=0; i<a.n; ++i){
            for(int k=0; k<a.m; ++k)if(a.mat[i][k]){
                for(int j=0; j<b.m; ++j)if(b.mat[k][j]){
                    ret.mat[i][j] = ret.mat[i][j]+a.mat[i][k]*b.mat[k][j];
                }
            }
        }
        return ret;
    }
    friend bool operator==(const Matrix &a,const Matrix &b){
        if(a.n!=b.n || a.m!=b.m)return false;
        for(int i=0; i<a.n; ++i)
            for(int j=0; j<a.m; ++j)
                if(a.mat[i][j]!=b.mat[i][j])return false;
        return true;
    }
};

Matrix arr[VN];
int n, m;
int d[VN][VN];

void init(){
    for(int i=0; i<n; ++i){
        d[i][i] = INF;
        for(int j=i+1; j<n; ++j)
            d[i][j] = d[j][i] = INF;
    }
}

void Floyd(){
    for(int k=0; k<n; ++k)
    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
        if(d[i][k]!=INF && d[k][j]!=INF)
            d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
    while(~scanf("%d%d",&n,&m)&&n+m){
        init();
        for(int i=0; i<n; ++i){
            arr[i].set_size(m,m);
            for(int j=0; j<m; ++j){
                for(int k=0; k<m; ++k)
                    scanf("%d",&arr[i].mat[j][k]);
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)if(i!=j){
                Matrix ret = arr[i]*arr[j];
                for(int k=0; k<n; ++k)if(k!=j&&k!=i){
                    if(ret==arr[k]){
                        d[i][k] = 1;
                    }
                }
            } 
        }
        Floyd();
        scanf("%d",&m);
        for(int i=0; i<m; ++i){
            int u,v;
            scanf("%d %d",&u,&v);
            --u, --v;
            if(d[u][v]!=INF) printf("%d\n",d[u][v]);
            else puts("Sorry");
        }
    }
    return 0;
}
