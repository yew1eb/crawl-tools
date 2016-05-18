#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const double eps=1e-10;

double y;

double f(double x){
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6-y;
}

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&y);
        double l=0,r=100,mid;
        if(f(l)>eps || f(r)<eps){
            puts("No solution!");
            continue;
        }
        while(l+eps<=r){
            mid=(l+r)/2;
            if(f(mid)<eps)
                l=mid+eps;
            else
                r=mid-eps;
        }
        printf("%.4lf\n",l);
    }
    return 0;
}