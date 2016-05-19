#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100;
const double eps = 1e-11;
double mabs(double u){return u>0?u:-u;}
struct Matrix{
    double Ma[MAXN+10][MAXN+11];
    int n;
    void solve(){
        int m = n+1;
        for(int i=1;i<=n;i++){
            int Maxp = i;
            for(int j=i+1;j<=n;j++)
                if(mabs(Ma[j][i]) > mabs(Ma[Maxp][i]))
                    Maxp = j;
            if(Maxp != i)
                swap(Ma[Maxp], Ma[i]);
            for(int j=1;j<=n;j++){
                if(j != i && mabs(Ma[j][i]) >= eps){
                    double bl = Ma[j][i] / Ma[i][i];
                    for(int k=1;k<=m;k++)
                        Ma[j][k] -= bl * Ma[i][k];
                }
            }
        }
    }
}M, Ym;
int ma(int u){return u>0?u:-u;}
int Dis(int a, int b, int c, int d){
    return ma(a-c)+ma(b-d);
}
int main(){
    int W, H, D;
    bool fir = false;
    while(~scanf("%d%d%d", &W, &H, &D) && W && H){
        if(fir) printf("\n");
        else fir = true;
        memset(M.Ma, 0, sizeof M.Ma);
        M.n = W*H;
        for(int i=1;i<=H;i++)
            for(int j=1;j<=W;j++)
                scanf("%lf", &Ym.Ma[i][j]);
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                int cnt = 0;
                for(int ip=1;ip<=H;ip++){
                    for(int jp=1;jp<=W;jp++){
                        if(Dis(i, j, ip, jp) <= D)
                            M.Ma[(i-1)*W+j][(ip-1)*W+jp]++, cnt++;
                    }
                }
                M.Ma[(i-1)*W+j][W*H+1]=cnt*Ym.Ma[i][j];
            }
        }
        M.solve();
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                printf("%8.2lf", M.Ma[(i-1)*W+j][H*W+1]/M.Ma[(i-1)*W+j][(i-1)*W+j]);
            }
            printf("\n");
        }
    }

    return 0;
}
/*
9 4 10
2 5 8
3 4 6
*/
