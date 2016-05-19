#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct coor
{
    int x;
    int y;
    coor()
    {
        x=0;
        y=0;
    }
}coor,* coorlink;
coor coors[200000+5];
int main()
{
    int n=0;
    while(scanf("%d",&n)!=EOF&&n>0)
    {
        for(int i=0;i<=n-1;i++)
        {
            scanf("%d%d",&coors[i].x,&coors[i].y);
        }
        int stan=0,ollie=0;
        coor mid=coors[(n-1)/2];
        for(int i=0;i<=n-1;i++)
        {
            if((coors[i].x<mid.x&&coors[i].y<mid.y)||(coors[i].x>mid.x&&coors[i].y>mid.y))
            {
                stan++;
            }
            if((coors[i].x<mid.x&&coors[i].y>mid.y)||(coors[i].x>mid.x&&coors[i].y<mid.y))
            {
                ollie++;
            }
        }
        printf("%d %d\n",stan,ollie);
    }
    return(0);
}
