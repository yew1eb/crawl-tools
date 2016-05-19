#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        double A,B,k,j_x,j_y,ans;
        double p_x,p_y;
        cin>>A>>B>>p_x>>p_y;
        p_y = p_y>0?p_y:-p_y;
        k=p_y/p_x;
        double tt=(A*A*B*B)/(B*B+A*A*k*k);
        j_x=sqrt(tt);
        j_y=k*j_x;
        double t1=asin(1.0);
        double t2=asin(j_x/A);
        ans=A*B*(  ( t1+sin(2*t1)/2.0) -(t2+sin(2*t2)/2.0) )/2+j_x*j_y/2;
        printf("%.2lf\n",ans);
    }
    return 0;
}