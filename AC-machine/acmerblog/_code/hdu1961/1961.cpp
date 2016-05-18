#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=510;
const int Max=20000;
int n;
double a[N],d[N][N];
bool f[N];

struct point
{
    int x,y;
}p[N];
bool cmp(double x,double y)
{
    return (x>y);
}
double dist(point p1,point p2)
{
    return(sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}
void path()
{
    int k;
    f[1]=1;
    k=1;
    for(int i=2;i<=n;i++)
    {
        int mcost=Max;
        for(int j=2;j<=n;j++)
        {
            if(!f[j]&&(a[j]<mcost))
            {
                mcost=a[j];
                k=j;
            }
        }
        f[k]=1;
        for(int t=2;t<=n;t++)
        {
            if(!f[t]&&(d[k][t]<a[t]))
            a[t]=d[k][t];
        }
    }
    return;
}
int main()
{
   int test;
   cin>>test;
   while(test--)
   {
       int s;
       cin>>s>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>p[i].x>>p[i].y;
           f[i]=0;
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=i+1;j<=n;j++)
           {
               d[i][j]=dist(p[i],p[j]);
               d[j][i]=d[i][j];
           }
       }
       for(int k=2;k<=n;k++)
       {
           a[k]=d[1][k];
       }
       a[1]=0;
       path();
       sort(a+1,a+n+1,cmp);
       //cout<<a[s+1]<<endl;
       printf("%.2lf\n",a[s]);
   }
    return 0;
}