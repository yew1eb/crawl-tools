#include<iostream>
#include<cstdio>
using namespace std;
int T,sum,num,p,m,a[20],f[20],i;
int min(int a,int b)
{
    if (a<b) return a; else return b;
}
int doit(int i,int x)
{
    int p,h;
    if (i==0||x==0)
    {
        if (x==0) return 0; else return -1;
    }
    int y1=10000000,y2=10000000;
    h=min(x/f[i],a[i]);
    p=doit(i-1,x-h*f[i]);
    if (p!=-1) y1=p+h;
    if (h>0)
    {
        p=doit(i-1,x-(h-1)*f[i]);
        if (p!=-1) y2=p+h-1;
    }
    if (y1==10000000&&y2==10000000) return -1 ; else return (min(y1,y2));
}
int main()
{
    scanf("%d",&T);
    f[1]=1; f[2]=5; f[3]=10; f[4]=20; f[5]=50; f[6]=100; f[7]=200; f[8]=500; f[9]=1000; f[10]=2000;
    while (T--)
    {
        scanf("%d",&p);
        sum=0; num=0;
        for (i=1;i<=10;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i]*f[i];
            num+=a[i];
        }
        m=sum-p;
        if (m<0) printf("-1\n");
        else
        {
            int dd=doit(10,m);
            if (dd!=-1) printf("%d\n",num-dd); else printf("-1\n");
        }
    }
    return 0;
}
