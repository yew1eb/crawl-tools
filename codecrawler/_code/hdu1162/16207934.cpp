#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
#define inf 1000000.0

int c;
double dx[101],dy[101];
int set[101];
int find(int x)
{
    int r=x;
    while(set[r]!=r)
        r=set[r];
    int k;
    while(x!=set[x])
    {
        k=set[x];
        set[x]=r;
        x=k;
    }
    return r;
}
void join(int a,int b)
{
    int af=find(a);
    int bf=find(b);
    if(af!=bf)set[af]=bf;
}
struct heapmin
{
    double d;
    int x,y;
    heapmin(double td,int tx,int ty):d(td),x(tx),y(ty){}
    heapmin(){}
};
bool operator<(const heapmin &a,const heapmin &b)
{
    return a.d>b.d;
}
bool operator>(const heapmin &a,const heapmin &b)
{
    return a.d<b.d;
}
priority_queue<heapmin, vector<heapmin>,less<vector<heapmin>::value_type> >Q;//è¿æ ·ä¸æ¯æå¤§ä¼åï¼å¿äºè¯¥å¾å»ççstläºãã
void init()
{
    while(!Q.empty())Q.pop();
    for(int i=0;i<c;++i)
    {
        set[i]=i;
        for(int j=0;j<c;++j)
        {
            double d=sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
            if(i!=j){Q.push(heapmin(d,i,j));}
        }
    }
}
double kruskal()
{
    double ret=0.0;
    int n=0;
    while(!Q.empty())
    {
        if(n>=c-1)break;
        heapmin t=Q.top();
        Q.pop();
        //printf("-->%d %d %.2lf\n",t.x,t.y,t.d);
        if(find(t.x)!=find(t.y))
        {
            ret+=t.d;
            n++;
            join(t.x,t.y);
        }
    }
    return ret;
}

int main()
{
    while(scanf("%d",&c)!=EOF)
    {
        for(int i=0;i<c;++i)
        {
            scanf("%lf%lf",&dx[i],&dy[i]);
        }
        init();
        printf("%.2lf\n",kruskal());
    }
    return 0;
}
