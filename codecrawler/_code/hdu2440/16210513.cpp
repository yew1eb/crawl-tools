#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
#define eps 1e-10

int Fabs(double d)
{
    if(fabs(d)<eps) return 0;
    else return d>0?1:-1;
}

struct point 
{
    double x,y;
}p[105],sta[105];
int oper[8][2]={0,1,0,-1,-1,0,1,0,1,1,1,-1,-1,1,-1,-1},top;

double x_multi(point p1,point p2,point p3)    
{  
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);  
} 

double Dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool cmp(point a,point b)
{
    if(Fabs(x_multi(p[0],a,b))>0) return 1;
    if(Fabs(x_multi(p[0],a,b))<0) return 0;
    if(Fabs(Dis(p[0],a)-Dis(p[0],b))<0)
        return 1;
    return 0;
}

void Graham(int n)
{
    int i,k=0,tot;
    for(i=1;i<n;i++)
        if((p[i].y<p[k].y)||((p[i].y==p[k].y)&&(p[i].x<p[k].x)))
            k=i;
    swap(p[0],p[k]);
    sort(p+1,p+n,cmp);
    
    tot=1;
    for(i=2;i<n;i++)
        if(Fabs(x_multi(p[i],p[i-1],p[0])))
            p[tot++]=p[i-1];
    p[tot++]=p[n-1];
    
    sta[0]=p[0],sta[1]=p[1];
    i=top=1;
    for(i=2;i<tot;i++)
    { 
        while(top>=1&&Fabs(x_multi(p[i],sta[top],sta[top-1]))>=0)
        { 
            if(top==0) break; 
            top--; 
        } 
        sta[++top]=p[i]; 
    }   
}

double allDis(int n,point f)
{
    double sum=0.0;
    int i;
    for(i=0;i<n;i++)
        sum+=Dis(sta[i],f);
    return sum;
}

point fermat(int n) //æ±è´¹é©¬ç¹
{
    double step=0;
    int i,j;
    for(i=0;i<n;i++)
        step+=fabs(sta[i].x)+fabs(sta[i].y);
    point f;
    f.x=0,f.y=0;
    for(i=0;i<n;i++)
        f.x+=sta[i].x,f.y+=sta[i].y;
    f.x/=n,f.y/=n;
    point t;
    while(step>eps)
    {
        for(i=0;i<8;i++)
        {
            t.x=f.x+oper[i][0]*step;
            t.y=f.y+oper[i][1]*step;
            if(allDis(n,t)<allDis(n,f))
                f=t;
        }
        step/=2;
    }
    return f;
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        Graham(n);
        point ans=fermat(top+1);
        printf("%.0lf\n",allDis(top+1,ans));
        if(t>0) puts("");
    }
    return 0;
}