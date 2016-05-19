#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip>

using namespace std;

#define LL long long
#define pi acos(-1)
#define FRE freopen("a.txt","r",stdin)
#define INF 9999999999
#define eps 1e-6
#define N 55

struct point
{
    int x,y;
};
point p[N],cHull[N],p0,stck[N];

int m;//凸包顶点数
int n;//所有点数
//(b,a)x(c,a)
int cnt;
int cross(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}//<0则ac在ab的顺时针,需要顺时针拐

int dis(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
//极角从小到大排序
bool cmp(point a,point b)
{
    int t=cross(p0,a,b);
    return t>0||(t==0 && dis(p0,a)<dis(p0,b));
    //t>0即p0b在p0a的逆时针
}
void convexHull()
{
    int i,j,k;
    m=0;
    cnt=0;
    for(k=0,i=0;i<n;i++)
        if(p[i].y<p[k].y||(p[i].y==p[k].y && p[i].x<p[k].x) )
            k=i;
    p0=p[k];//基点
    p[k]=p[0];
    p[0]=p0;
    sort(p+1,p+n,cmp);
    stck[0]=p[0];
    stck[1]=p[1];/*
    int flag=0;
    if(cross(stck[0],stck[1],p[2])==0)
    {
        flag=1;
        stck[1]=p[2];
    }
    if(flag)i=3;
    else
    i=2;*/
    int top=1;
    for(i=2;i<n;i++)
    {
        while(top && cross(stck[top-1],stck[top],p[i])<=0)//就是这里！！！<=0啊
            {
                    top--;
            }
        stck[++top]=p[i];
    }
    m=top+1;
}
bool ccmp(point a,point b){
    if(a.y==b.y)return a.x<b.x;
    return a.y>b.y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int ca;
        int i,j;
        scanf("%d%d",&ca,&n);
        for(i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
        convexHull();
        int xx=stck[0].x,yy=stck[0].y;
        int tag=0;
        for(i=1;i<m;i++)
             if(stck[i].y>stck[tag].y || (stck[i].y==stck[tag].y && stck[i].x<stck[tag].x))
               tag=i;
        printf("%d %d\n",ca,m);
        for(i=tag;i>=0;i--)
        printf("%d %d\n",stck[i].x,stck[i].y);
        for(i=m-1;i>tag;i--)
        printf("%d %d\n",stck[i].x,stck[i].y);
    }
    return 0;
}