#include<stdio.h>
int main()
{
    int t;
    float time,u,v,w,l;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%f %f %f %f",&u,&v,&w,&l);
    time=l/(u+v);
    printf("%.3f\n",time*w);
    }
    return 0;
}