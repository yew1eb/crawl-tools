#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
const int maxn=100100;
struct node
{
    double x1,y1;
    double x2,y2;
};
struct dot
{
    int x,y;
};
node a[maxn];
int cross(node a,node b)
{
   if((((b.x2-b.x1)*(a.y1-b.y1)-(b.y2-b.y1)*(a.x1-b.x1))*((b.x2-b.x1)*(a.y2-b.y1)-(b.y2-b.y1)*(a.x2-b.x1))<=0)&&(((a.x2-a.x1)*(b.y1-a.y1)-(a.y2-a.y1)*(b.x1-a.x1))*((a.x2-a.x1)*(b.y2-a.y1)-(a.y2-a.y1)*(b.x2-a.x1)))<=0)
        {
            if((b.x2-b.x1)*(a.y2-a.y1)-(b.y2-b.y1)*(a.x2-a.x1)==0&&(b.x1!=a.x1||b.y1!=a.y1)&&(b.x1!=a.x2||b.y1!=a.y2))//aä¸bå¹³è¡ä¸a bä¸å¬çº¿
                return 0;
            else
             return 1;
        }
        return 0;
}
int main()
{
    int vis[100100];
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(vis,1,sizeof(vis));
         for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(cross(a[i],a[j]))
                {
                    vis[i]=0;
                    break;
                }

            }
        }
        printf("Top sticks: ");
        for(int i=0;i<n-1;i++)
            if(vis[i])
                printf("%d, ",i+1);
            printf("%d.\n",n);
    }
    return 0;
}
