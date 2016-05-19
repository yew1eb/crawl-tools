//高斯消元法解线性方程组
//每一个方程都是 进==出
//Ai1 * x1 + Ai2 *x2 + Ai3 * x3 +...+ An-1 * xn-1 = xi;
//所以别的点流进==本点流出xi
//移项发现每个A[i][i]=-1;
//A[i][j]=1/d[j];d[j]为j点出度。
//n个方程解n个未知数。要么是唯一解，要么是无穷解。
//若是唯一解，则枚举所有A->j(j为与A无连接的点)
//可以发现，我们连接A->j之后，矩阵中改变的只是出度的只有A，
//所以改变的只有A[i][n-1](i为A指向的点)
//我们在重新计算的时候，只不过每次替换掉原来的第n-1列，前面都是不变的。
//所以我们可以将所有要枚举的列增加到A的增广矩阵中一起做阶梯化。
//这与单独计算的时候是等价的（阶梯化的过程中只考虑前n-1列，后面只是附和运算的）
//所以一次高斯消元就足够了。
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int N = 300;
const int INF=0x7fffffff;
#define eps 1e-9
double A[N][N];
double x[N];
int g[N][N],d[N];
vector<int>edge[N];
int add[N];
bool Gauss(int equ,int var){
    int row,col;
    for(row=col=0;row<equ&&col<var;col++,row++){
        int max_r=row;
        for(int i=row+1;i<equ;i++){
            if(fabs(A[max_r][col])<fabs(A[i][col])){
                max_r=i;
            }
        }
        if(fabs(A[max_r][col])<eps)return 0;
        if(max_r!=row){
            for(int i=col;i<var;i++){
                swap(A[max_r][i], A[row][i]);
            }
        }
        for(int i=col+1;i<var;i++){//将col+1~var化简
            A[row][i]/=A[row][col];
        }
        A[row][col]=1;
        for(int i=row+1;i<equ;i++){
            if(fabs(A[i][col])<eps)continue;
            for(int j=col+1;j<var;j++){
                A[i][j]+=A[row][j]*(-A[i][col]);
            }
            A[i][col]=0;
        }
    }
    return 1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<n;i++)
            edge[i].clear();
        memset(d,0,sizeof(d));
        memset(g,0,sizeof(g));
        memset(A, 0, sizeof(A));
        
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            if(u!=v)g[u][v]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&g[i][j]==1){
                    d[i]++;
                    edge[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            A[i][i]=-1;
            for(int j=0;j<edge[i].size();j++){//j->i
                int v=edge[i][j];
                if(i==v)continue;
                A[i][v]=1.0/d[v];
            }
        }
        for(int i=0;i<=n;i++)
            A[n-1][i]=1;
        
        int cnt=1;
        for(int i=0;i<n-1;i++){//枚举点
            if(g[n-1][i]==0){//连边
                for(int j=0;j<n;j++){
                    if(g[n-1][j]){//修改n-1指向的所有点
                        A[j][n+cnt]=1.0/(d[n-1]+1);
                    }
                    else A[j][n+cnt]=0;
                }
                A[i][n+cnt]=1.0/(d[n-1]+1);
                A[n-1][n+cnt]=1;
                add[cnt]=i;
                cnt++;
            }
        }
        if(!Gauss(n,n+cnt)){
            printf("INF\n");
        }
        else{
            int max_cnt=-1;
            double mmax=A[n-1][n]/A[n-1][n-1];
            for(int i=1;i<cnt;i++){
                if(A[n-1][n]/A[n-1][n+i]>mmax){
                    max_cnt=add[i];
                    mmax=A[n-1][n]/A[n-1][n+i];
                }
            }
            printf("%d %d\n",1,max_cnt);
        }
    }
    return 0;
}