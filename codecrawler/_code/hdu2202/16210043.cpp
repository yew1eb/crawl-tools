#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=50005;
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
int convex(int n)
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
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k,x,y,m;
        for(i=0;i<n;i++)
            scanf("%d%d",&e[i].x,&e[i].y);
        m=convex(n);
        int ans=0;
        for(i=0;i<m;i++)
            for(j=i+1;j<m;j++)
                for(k=j+1;k<m;k++)
                ans=max(ans,cross(res[j],res[k],res[i]));
        printf("%.2lf\n",0.5*ans);
    }
    return 0;
}
/*
    æ°´å¹³åºçAndrewç®æ³ï¼æ±å¸åãæ¶é´å¤æåº¦O(n)
    æå¤§ä¸è§å½¢çä¸ä¸ªé¡¶ç¹å¿å®å¨å¸åä¸ï¼æä¸¾å³å¯ã

    åéç§¯ï¼aÃb=x1*y2-x2*y1;å½aÃb>0æ¶bå¨açéæ¶éæ¹å,aÃb<0æ¶bå¨é¡ºæ¶éæ¹åï¼aÃb=0æ¶å±çº¿
    |aÃb|=|a|*|b|*sin<a,b>ï¼å¯ä»¥æ±ä¸è§å½¢é¢ç§¯ã

*/