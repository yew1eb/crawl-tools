#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1010;
const double pi=atan(1.0)*4;
struct node{
    int x,y;
}e[maxn],res[maxn];
int cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int cross(node a,node b,node c)//åéç§¯
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int convex(int n)//æ±å¸åä¸çç¹
{
    sort(e,e+n,cmp);
    int m=0,i,j,k;
    //æ±å¾ä¸å¸åï¼éæ¶é
    //å·²ç¥å¸åç¹mä¸ªï¼å¦ææ°å å¥ç¹ä¸ºiï¼ååé(m-2,i)å¿å®è¦å¨(m-2,m-1)çéæ¶éæ¹åæç¬¦åå¸åçæ§è´¨
    //è¥ä¸æç«ï¼åm-1ç¹ä¸å¨å¸åä¸ã
    for(i=0;i<n;i++)
    {
        while(m>1&&cross(res[m-1],e[i],res[m-2])<=0)m--;
        res[m++]=e[i];
    }
    k=m;
    //æ±å¾ä¸å¸å
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&cross(res[m-1],e[i],res[m-2])<=0)m--;
        res[m++]=e[i];
    }
    if(n>1)m--;//èµ·å§ç¹éå¤ã
    return m;
}
double lenght(node a,node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int T,n,l;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,m;
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            scanf("%d%d",&e[i].x,&e[i].y);
        m=convex(n);
        double ans=0;
        for(i=1;i<m;i++)
            ans+=lenght(res[i],res[i-1]);
        ans+=lenght(res[m-1],res[0]);
        ans+=2*pi*l;
        printf("%.0lf\n",ans);
        if(T!=0)
            printf("\n");
    }
    return 0;
}
/*
    é¢ææ¯ï¼æ±å¾nä¸ªç¹çå¸åï¼ç¶åæ±ä¸å¸åç¸è·lçå¤åçå¨é¿ã
    æ¹æ³ï¼
    ç»å¾å¯ç¥ï¼æåææ±å¨é¿ç­äºå¸åå¨é¿+åå¾ä¸ºlçåå¨é¿ã
*/