#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct point{
    double x,y;
}p[1000];

double xmult(point a,point b,point c){//å¤§äºé¶ä»£è¡¨a,b,cå·¦è½¬ 
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

void RP(int i){
    scanf("%lf%lf",&p[i].x,&p[i].y);
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)    RP(i);
        p[n+1]=p[1];p[n+2]=p[2];
        for(i=3;i<=n+2;i++)
            if(xmult(p[i-2],p[i-1],p[i])<0)    break;
        
        if(i==n+3)    printf("convex\n");
        else        printf("concave\n");
    }
    return 0;
}
