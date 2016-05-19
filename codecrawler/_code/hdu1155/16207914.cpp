#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
const double G=9.81;
int main()
{
    double k,l,s,w;
    while(scanf("%lf %lf %lf %lf",&k,&l,&s,&w))
    {
        if(k==0&&l==0&&s==0&&w==0)break;
        double e=w*G*s;
        if(s>l)e-=k*(s-l)*(s-l)/2;
        if(e<0)
        {
            printf("Stuck in the air.\n");
            continue;
        }
        double v=sqrt(e*2/w);
        if(v>10) printf("Killed by the impact.\n");
        else printf("James Bond survives.\n");
    }
    return 0;
}
