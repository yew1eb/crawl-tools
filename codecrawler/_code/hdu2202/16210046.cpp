#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define N 50005
int n;
int ktoal;
struct p
{
    int x,y;
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
p ar[N];
p fundation;
int cmpy(p a,p b)
{
    if(a.y != b.y) return a.y<b.y;
    return a.x < b.x;
}
int squaredis(p a,p b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int mul(p a,p b,p c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int cmp(const void * a,const void * b)
{
    struct p* aa = (p*) a;
    struct p * bb = (p*) b;
    int k = mul(*aa,*bb,fundation);
    if(k<0) return 1;
    else if(k==0&&squaredis(*aa,fundation)>= squaredis(*bb,fundation))
        return 1;
     return -1;
    
}
double area(int a,int b,int c)
{
    return fabs(1.0*mul(ar[a],ar[b],ar[c]))/2.0;
}
void grah()
{
     ktoal = 2;
    //ar[n] = fundation;
    for(int i = 3;i<n;i++)
    {
        while((mul(ar[ktoal],ar[i],ar[ktoal-1])<=0)&&ktoal>=2) 
            ktoal--;
        ar[++ktoal]= ar[i];
    }
}
double maxarea()
{
    //double max = 0;
    double max = 0;
    /*int p,q;
    for(int i=0;i<n;i++)
    {
        p = (i+1)%n;q = (i+2)%n;
        while(area(i,q,(q+1)%n)>area(i,p,q)) p = q,q = (q+1)%n;
        if(area(i,p,q)>max) max = area(i,p,q);
    }
    return max;*/

    for(int i=0;i<ktoal-1;i++)
        for(int j=i+1;j<ktoal;j++)
            for(int k=j+1;k<=ktoal;k++)
                if(area(i,j,k)>max) max = area(i,j,k);
    return max;
}
void init()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            ar[i].in();
        }
        if(n<=2) { printf("0.00\n");continue;}
        if(n==3)
        {
            printf("%.2lf\n",area(0,1,2));
            continue;
        }
        sort(ar,ar+n,cmpy);
        fundation = ar[0];
        qsort(ar+1,n-1,sizeof(ar[0]),cmp);
        grah();
        printf("%.2lf\n",maxarea());

    }
    return ;
}
int main()
{
    init();
    return 0;
}
