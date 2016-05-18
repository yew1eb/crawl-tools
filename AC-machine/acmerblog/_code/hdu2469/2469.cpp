#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
#define N 100100
#define PI (2*asin(1.0))

struct node
{
    int x,y;
    double r;//表示半径
    double du;//用来表示角度
}g[N];

int n,k;
double g1[N];

int cmp(node t,node t1)
{
    return t.du<t1.du;
}

double que[2*N];

double mabs(double x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    //freopen("//home//ismdeep//xianchang1//in","r",stdin);
    int tt=1;
    double pi=PI;
    while(scanf("%d%d",&n,&k)&&(n+k))
    {

        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&g[i].x,&g[i].y);
            g[i].r=sqrt((double)g[i].x*g[i].x+g[i].y*g[i].y);
            g1[i]=g[i].r;

            double tmp;

            if(mabs(g[i].x-0)<1e-8)
            {
                if(g[i].y>0) tmp=90.0;
                else tmp=270.0;
            }
            else
            {
                tmp=((double)g[i].y/(double)g[i].x); //将这个点的斜率求出来
                if(mabs(g[i].y-0)<1e-8)
                {
                    if(g[i].x>0) tmp=0.0;
                    else tmp=180.0;
                }
                else
                {
                    tmp=atan(tmp);//求出角度
                    tmp=(180.0/PI)*tmp;
                    if(g[i].y*g[i].x > 0&&g[i].y<0)
                        tmp+=180.0;
                    if(g[i].y*g[i].x<0)
                    {
                        tmp*=-1;
                        if(g[i].x<0)
                            tmp=180.0-tmp;
                        else
                        {
                            tmp=360-tmp;
                        }
                    }

                }
            }
            g[i].du=tmp;
        }
        // 角度求好了
        if(k==0)
        {
            printf("Case #%d: 0.00\n",tt++);
            continue;
        }
        //sort(g1+1,g1+n+1); //半径从小到大来搞一搞啊
        sort(g+1,g+1+n,cmp);

        double mi=1999999999;

        for(int ii=1;ii<=n;ii++)
        {
            double key=g1[ii]; //表示固定的半径
            int flag=0;

            for(int i=1;i<=n;i++)//提前
            {
                if(g[i].r <= key+1e-6)
                {
                    que[flag++]=g[i].du;
                }
            }

            for(int i=0;i<flag;i++)
            {
                que[flag+i] = que[i]+360.0;
            }

            if(flag<k) continue;

            for(int i=0;i<flag;i++)
            {
                double tmp=que[i];
                int tt=i+k-1;
                double tmp1=que[tt];
                tmp=tmp1-tmp;

                tmp=(tmp/(360.0))*PI*key*key;

                mi=min(tmp,mi);
            }
        }

        printf("Case #%d: ",tt++);

        printf("%.2lf\n",mi);
    }
    return 0;
}