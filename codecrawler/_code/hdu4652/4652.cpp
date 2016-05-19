#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

inline double solve(){
    int op,m,n;
    scanf("%d%d%d",&op,&m,&n);
    double ans=0;
    if(op==0){
        for(int i=0;i<=n-1;i++){
            ans+=pow(1.0*m,i);
        }
    }else{
        double tmp=1.0;
        for(int i=1;i<=n;i++){
            ans+=tmp;
            tmp*=m*1.0/(m-i);
        }
    }
    return ans;
}

int main(){
    int t;
    while(scanf("%d",&t)!=EOF){
        while(t-- >0){
            printf( "%.9lf\n",solve() );
        }
    }
    return 0;
}
