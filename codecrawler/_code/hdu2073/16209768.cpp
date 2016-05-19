#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

struct point
{
    int x,y;
};

double ans(point P1,point P2)
{
    if((P1.x+P1.y)==(P2.y+P2.x))
        return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
    int i,t=P2.x+P2.y-P1.y-P1.x;//printf("t=%d\n",t);
    double ret=0;
    for(i=P1.x+P1.y;i<P2.y+P2.x;i++)
    {
        ret+=sqrt(i*i+(i+1)*(i+1));
    //    printf("i=%d ,%.03lf\n",i,sqrt(i*i+(i+1)*(i+1)));
    }
    point t1={P1.x+P1.y,0},t2={0,P2.y+P2.x};
    ret+=ans(P1,t1)+ans(t2,P2);
//    printf("%.03lf+%.03lf\n",ans(P1,t1),ans(t2,P2));
    for(i=P1.x+P1.y+1;i<P2.y+P2.x;i++)
    {
        point t1={i,0},t2={0,i};
        ret+=ans(t1,t2);
    }
    return ret;
}

int main()
{
    int i,j,T;
    point P1,P2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&P1.x,&P1.y,&P2.x,&P2.y);
        if(P1.x+P1.y>P2.x+P2.y)    swap(P1,P2);
        printf("%.03lf\n",ans(P1,P2));
    }
    return 0;
}
