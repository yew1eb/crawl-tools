#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,m;
    double p,q;
    double t,ans;
    while(scanf("%d%d%lf%lf",&n,&m,&p,&q)!=EOF){
        if(n==0)     {printf("0.00\n"); continue;}
        if(m==0)     {printf("1.00\n");continue;}
        if(p==0 || q==1) {printf("0.00\n");continue;}
        if(q==0 || p==1) {printf("1.00\n");continue;}
        if(p==q)         ans= 1.0*n/(m+n);
        else{
            t=q*(1-p) / (p*(1-q));
            ans= (1.0-pow(t,n)) / (1.0 -pow(t,n+m));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
