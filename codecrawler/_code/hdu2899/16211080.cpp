#include <cstdio>
#include <cmath>
#include <cstdlib>

const double eps = 1e-6;

double cal(double x){
    return 42*pow(x,6.0)+48*pow(x,5.0)+21*pow(x,2.0)+10*x;
}

double gao(double x,double y){
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-x*y;
}

int main(){
    int t;
    double low,high,y,x,res;

    scanf("%d",&t);
    while(t--){
        scanf("%lf",&y);
        low = 0.0;
        high = 100.0;
        while(high-low>eps){
            x = (low+high)/2;
            res = cal(x);
            if(res<y){
                low = x + 1e-8;
            }else{
                high = x - 1e-8;
            }
        }
        printf("%0.4lf\n",gao(x,y));
    }
    return 0;
}
