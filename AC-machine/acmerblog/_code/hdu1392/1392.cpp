#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-6
#define PI 3.14159265
struct point
{
double x;
double y;
}po[1500],temp;
int n,l,pos;
bool zero(double a)
{
return fabs(a) < eps;
}
double dis(point &a,point &b)//返回两点之间距离的平方
{
return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double across(point &a,point &b,point &c)//求a b and a c 的X积
{
return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
int cmp(const void *a,const void *b)
{
return across(po[0],*(point*)a,*(point*)b) > 1e-8 ? -1 : 1;
}
int select()
{
int i,j,k=1;
for(i=2;i<n;i++)
{
if(zero(across(po[0],po[k],po[i])))
{
if(dis(po[0],po[k]) < dis(po[0],po[i]))
po[k]=po[i];
}
else
po[++k]=po[i];
}
return k+1;
}
int graham(int num)
{
double ans=0;
int i,j,k=2;
po[num]=po[0];//fangbian 
num++;
for(i=3;i<num;i++)
{
while(across(po[k-1],po[k],po[i]) < -eps)
{k--;}
po[++k]=po[i];//就这个循环结束，不需要了！
}
for(i=1;i<=k;i++)
{
ans+=dis(po[i-1],po[i]);
}
printf("%.2lf\n",ans);

return 0;
}
int main()
{
int i,j,k;
point my_temp;
while(scanf("%d",&n),n)
{
scanf("%lf%lf",&po[0].x,&po[0].y);
temp=po[0];
pos=0;
for(i=1;i<n;i++)
{
scanf("%lf%lf",&po[i].x,&po[i].y);
if(po[i].y < temp.y)
temp=po[i],pos=i;
}
if(n==2)
{
printf("%.2lf\n",dis(po[0],po[1]));
continue;
}
my_temp=po[0];
po[0]=po[pos];
po[pos]=my_temp;
qsort(po+1,n-1,sizeof(po[0]),cmp);
graham(select());
}
return 0;
}