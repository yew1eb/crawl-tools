#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 60;
int n, p, q, x[N], y[N];
double dist[N][N];
double cal(double dx,double dy){
    return sqrt(dx*dx + dy*dy);
}
bool done[N];
double d[N];
double solve(){
    memset(done,0,sizeof(done));
    double res = dist[p][q];
    done[p]=done[q]=1;
    for(int i=1; i<=n; i++){
        d[i] = min(dist[p][i], dist[q][i]);
    }
    for(int i=3; i<=n; i++){
        int j=-1;
        for(int k=1; k<=n; k++){
            if(done[k]) continue;
            if(j==-1 || d[k]<d[j])  j=k;
        }
        done[j]=1;
        res += d[j];
        for(int k=1; k<=n; k++){
            if(!done[k])    d[k] = min(d[k], dist[j][k]);
        }
    }
    return res;
}
int main(){
    while(~scanf("%d", &n) && n){
        scanf("%d %d", &p, &q);
        for(int i=1; i<=n; i++){
            scanf("%d %d", x+i, y+i);
            for(int j=1; j<i; j++){
                dist[i][j] = dist[j][i] = cal(x[i]-x[j], y[i]-y[j]);
            }
            dist[i][i]=0.0;
        }
        printf("%.2lf\n", solve());
    }
    return 0;
}
