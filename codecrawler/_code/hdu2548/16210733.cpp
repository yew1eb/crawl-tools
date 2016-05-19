#include<iostream>
using namespace std;
int main()
{
    int n;
    double u,v,w,l;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
             scanf("%lf%lf%lf%lf",&u,&v,&w,&l);
             printf("%.3lf\n",l/(v+u)*w);
        }
    }
    return 0;
}