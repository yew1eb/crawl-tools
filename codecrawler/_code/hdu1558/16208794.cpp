#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int pre[1010],sum[1010];
struct point{
    double x,y;
};
struct EDGE{
    point a,b;
} edge[1010];
int E;//è¾¹æ° 

int Find(int x){
    return x==pre[x]? x:pre[x]=Find(pre[x]);
}

void Merge(int a,int b){
    int x=Find(a),y=Find(b);
    if(x!=y){
        pre[y]=x;
        sum[x]+=sum[y];
    }
}

double xmult(point a,point b,point c){//å¤§äºé¶ä»£è¡¨a,b,cå·¦è½¬
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool OnSegment(point a,point b,point c){        //a,b,cå±çº¿æ¶ææ 
    return c.x>=min(a.x,b.x)&&c.x<=max(a.x,b.x)&&c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y);    
}

bool Cross(point a,point b,point c,point d){//å¤æ­ab ä¸cdæ¯å¦ç¸äº¤ 
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
    int i,j,k,T,n;
    char s[10];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);E=0;
        for(i=1;i<=n;i++)    pre[i]=i,sum[i]=1;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(s[0]=='P'){
                E++;
                scanf("%lf%lf%lf%lf",&edge[E].a.x,&edge[E].a.y,&edge[E].b.x,&edge[E].b.y);
                for(j=1;j<E;j++)
                    if(Find(E)!=Find(j)&&Cross(edge[E].a,edge[E].b,edge[j].a,edge[j].b))    Merge(E,j);
            }
            else    if(s[0]=='Q'){
                scanf("%d",&k);
                printf("%d\n",sum[Find(k)]);
            }
        }
        if(T)    printf("\n");
    }
    return 0;
}
