#include<stdio.h>
#include<iostream>
using namespace std;
int set[1010];
int num[1010];
struct point
{
    double x,y;
};
struct edge
{
    point a;
    point b;
}e[1010];
int find(int x)
{
    int r=x;
    while(r!=set[r])
    r=set[r];
    int i=x;
    while(i!=r)
    {
       int j=set[i];
        set[i]=r;
        i=j;
    }
    return r;
}

void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        set[fx]=fy;
        num[fy]+=num[fx];
    }
}
double xmult(point a,point b,point c) //å¤§äºé¶ä»£è¡¨a,b,cå·¦è½¬
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool OnSegment(point a,point b,point c)         //a,b,cå±çº¿æ¶ææ
{
    return c.x>=min(a.x,b.x)&&c.x<=max(a.x,b.x)&&c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y);
}

bool Cross(point a,point b,point c,point d) //å¤æ­ab ä¸cdæ¯å¦ç¸äº¤
{
    double d1,d2,d3,d4;
    d1=xmult(c,d,a);
    d2=xmult(c,d,b);
    d3=xmult(a,b,c);
    d4=xmult(a,b,d);
    if(d1*d2<0&&d3*d4<0)    return 1;
    else    if(d1==0&&OnSegment(c,d,a))    return 1;
    else    if(d2==0&&OnSegment(c,d,b))    return 1;
    else    if(d3==0&&OnSegment(a,b,c))    return 1;
    else    if(d4==0&&OnSegment(a,b,d))    return 1;
    return 0;
}
int main()
{
    int t,n,k,tmp,i,j;
    char s[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        k=0;
        for(int i=1;i<=n;i++)
        {
            set[i]=i;
            num[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(s[0]=='P')
            {
                k++;
                scanf("%lf%lf%lf%lf",&e[k].a.x,&e[k].a.y,&e[k].b.x,&e[k].b.y);
                for(int j=1;j<k;j++)
                {
                    if(find(k)!=find(j)&&Cross(e[k].a,e[k].b,e[j].a,e[j].b))
                    merge(k,j);
                }
            }
            else if(s[0]=='Q')
            {
                scanf("%d",&tmp);
                printf("%d\n",num[find(tmp)]);
            }
        }
        if(t)//There is a blank line between test cases.æ³¨ææåä¸ä¸ªæ ·ä¾ä¸ç¨è¾åºç©ºè¡
        printf("\n");
    }
    return 0;
}
/*
2
10
P 1.00 1.00 4.00 2.00
P 1.00 -2.00 8.00 4.00
Q 1
P 2.00 3.00 3.00 1.00
Q 1
Q 3
P 1.00 4.00 8.00 2.00
Q 2
P 3.00 3.00 6.00 -2.00
Q 5
3
P 1.00 1.00 4.00 2.00
P 1.00 -2.00 8.00 4.00
Q 1
*/
