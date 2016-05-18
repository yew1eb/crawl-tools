#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point{
    double x,y;
}monster,athena;
struct circle{
    struct point a;
    double r;
}cy[1005],cm[1005];
int dpy[1005],dpm[1005];
int MAX(int x,int y){ return x>y?x:y; }
double dis(struct point p1,struct point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int cmp(const void *a,const void *b)
{
    struct circle c=*(struct circle *)a;
    struct circle d=*(struct circle *)b;
    return c.r<d.r?-1:1;
}
int check(struct circle c1,struct circle c2)
{
    double temp=dis(c1.a,c2.a);
    return temp<c1.r-c2.r||temp>c1.r+c2.r;
}
int main()
{
    int i,j,t,n,flag1,flag2;
    int ally,allm,cas=1,res;

    //freopen("t.txt","r",stdin);
    scanf("%d",&t);
    athena.x=athena.y=0;
    while(t--)
    {
        scanf("%d%lf%lf",&n,&monster.x,&monster.y);
        for(ally=allm=i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&cy[ally].a.x,&cy[ally].a.y,&cy[ally].r);
            flag1=dis(cy[ally].a,monster)<cy[ally].r;
            flag2=dis(cy[ally].a,athena)<cy[ally].r;
            if(!flag1&&flag2) ally++;
            else if(flag1&&!flag2) cm[allm++]=cy[ally];
        }
        qsort(cy,ally,sizeof(cy[0]),cmp);
        qsort(cm,allm,sizeof(cm[0]),cmp);
        for(res=i=0;i<ally;i++)
        {
            for(dpy[i]=1,j=0;j<i;j++)
            {
                if(check(cy[i],cy[j]))
                    dpy[i]=MAX(dpy[i],dpy[j]+1);
            }
            res=MAX(res,dpy[i]);
        }
        for(i=0;i<allm;i++)
        {
            for(dpm[i]=1,j=0;j<i;j++)
            {
                if(check(cm[i],cm[j]))
                    dpm[i]=MAX(dpm[i],dpm[j]+1);
            }
            res=MAX(res,dpm[i]);
        }
        for(i=0;i<ally;i++)
        {
            for(j=0;j<allm;j++)
            {
                if(check(cy[i],cm[j]))
                    res=MAX(res,dpy[i]+dpm[j]);
            }
        }
        printf("Case %d: %d\n",cas++,res);
    }

    return 0;
}
