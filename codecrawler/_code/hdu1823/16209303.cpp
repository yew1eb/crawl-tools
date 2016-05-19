#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct Segtree
{
    int l,r,mid;
    double max;
}T[111][4*1011];

void build(int l,int r,int k,int K)
{
    T[K][k].l=l;
    T[K][k].r=r;
    T[K][k].mid=(l+r)>>1;
    T[K][k].max=0;
    if(l==r)    return ;
    build(l,T[K][k].mid,2*k,K);
    build(T[K][k].mid+1,r,2*k+1,K);
}
void update(int aim,int k,int K,double L)
{
    if(T[K][k].l==aim && T[K][k].r==aim)
    {
        T[K][k].max=T[K][k].max>L?T[K][k].max:L;
        return ;
    }
    if(aim<=T[K][k].mid)    update(aim,2*k,K,L);
    else                    update(aim,2*k+1,K,L);
    T[K][k].max=T[K][2*k].max>T[K][2*k+1].max?T[K][2*k].max:T[K][2*k+1].max;
}
double find(int l,int r,int k,int K)
{
    double temp;
    if(T[K][k].l==l && T[K][k].r==r)    return T[K][k].max;
    if(r<=T[K][k].mid)        temp=find(l,r,2*k,K);
    else if(l>T[K][k].mid)    temp=find(l,r,2*k+1,K);
    else
    {
        double a,b;
        a=find(l,T[K][k].mid,2*k,K);
        b=find(T[K][k].mid+1,r,2*k+1,K);
        temp=a>b?a:b;
    }
    return temp;
}
int main()
{
    int n;
    int i,l;
    char str[10];
    int a,b,c,d,t;
    double f1,f2,f3,f4,t2;
    double temp,ans;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<=100;i++)    build(0,1000,1,i);

        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            if(str[0]=='I')
            {
                scanf("%d%lf%lf",&a,&f2,&f3);
                a-=100;
                update((int)(f2*10),1,a,f3);
            }
            else
            {
                scanf("%d%d%lf%lf",&a,&b,&f3,&f4);
                if(a>b)        {t=a;a=b;b=t;}
                if(f3>f4)    {t2=f3;f3=f4;f4=t2;}
                a-=100;b-=100;
                ans=0;
                for(l=a;l<=b;l++)
                {
                    temp=find((int)(f3*10),(int)(f4*10),1,l);
                    if(temp>ans)    ans=temp;
                }
                if(ans==0)    printf("-1\n");
                else        printf("%.1lf\n",ans);
            }
        }
    }
    return 0;
}