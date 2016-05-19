#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-10;
const double inf=1e15;
struct Point
{
    double x,y;
    int k;
    Point(){}
    Point(double a,double b,int c)
    {
        x=a;
        y=b;
        k=c;
    }
    Point(double a,double b)
    {
        x=a; y=b; k=-1;
    }
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    void print()
    {
        printf("%.6lf %.6lf\n",x,y);
    }

};
typedef Point Vector;
Vector operator + (Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator / (Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
bool operator < (const Point &a,const Point &b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

int dcmp(double x)
{
    if (fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool operator == (const Point& a,const Point b)
{
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}
//atan2(x,y) :åé(x,y)çæè§ï¼å³ä»xè½´æ­£åè½´æè½¬å°è¯¥åéæ¹åæéè¦çè§åº¦ã
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
double Length(Vector A)
{
    return sqrt(Dot(A,A));
}
bool PointInPolygon(Point p,Point a,Point b,Point c)
{
    double c1=Cross(b-a,p-a);
    double c2=Cross(c-b,p-b);
    double c3=Cross(a-c,p-c);
    if (c1<0 && c2<0 && c3<0) return true;
    if (c1>0 && c2>0 && c3>0) return true;
    return false;

}
bool line(Point a,Point b,Point c)
{
    if (dcmp(Cross(b-a,c-a))==0) return true;
    return false;
}
double TriLength(Point a,Point b,Point c)
{
    return (Length(b-a)+Length(c-b)+Length(a-c));
}
const int maxm=42;
const int maxn=23000;
struct node
{
    int v,next;
    double w;
}edge[505000];
int sta[maxn];
int g[maxn];
Point tree[330];
Point s[44];
int n,m,k;
int N,en;
int num[maxm][maxm][maxm];
double Tlen[maxn];
void addedge(int x,int y,double w)
{
    edge[en].v=y;
    edge[en].w=w;
    edge[en].next=g[x];
    g[x]=en++;
}
double dis[66][maxn];
bool inq[66][maxn];
struct Node
{
    int s,u;
    Node(){}
    Node(int x,int y)
    {
        s=x; u=y;
    }
};
double spfa(int st)
{
    queue<Node> q;
    memset(inq,false,sizeof inq);
    for (int j=0; j<N; j++)
    if (dcmp(dis[st][j])<inf)
    {
        q.push(Node(st,j));
        inq[st][j]=true;
    }
    while(!q.empty())
    {
        Node tp=q.front(); q.pop();
        inq[tp.s][tp.u]=false;
        int u=tp.u;
        int v;
        int ts=0;
        for (int j=g[u]; j!=-1; j=edge[j].next)
        {
            v=edge[j].v;
            ts=(tp.s|sta[v]);
            if (dis[ts][v]>dis[tp.s][tp.u]+edge[j].w)
            {
                dis[ts][v]=dis[tp.s][tp.u]+edge[j].w;
                if (!inq[ts][v])
                {
                    inq[ts][v]=true;
                    q.push(Node(ts,v));
                }
            }
        }
    }
    double res=inf;
    for (int i=0; i<N; i++)
    res=min(res,dis[(1<<k)-1][i]);
    return res;
}
double slove()
{
    double res=inf;
    for (int i=0; i<(1<<k); i++)
    {
        for (int ii=0; ii<(1<<k); ii++)
         for (int j=0; j<N; j++)
         dis[ii][j]=inf;

        for (int j=0; j<N; j++)
        if (sta[j]==i) dis[i][j]=Tlen[j];

        res=min(res,spfa(i));
    }
    return res;
}

int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        memset(num,-1,sizeof num);
        for (int i=0; i<n; i++)
        tree[i].read();
        for (int i=0; i<n; i++)
        {
            scanf("%d",&tree[i].k);
            tree[i].k--;
        }
        for (int i=0; i<m; i++)
        {
            s[i].read();
        }
        N=0;
        for (int i1=0; i1+2<m; i1++)
            for (int i2=i1+1; i2+1<m; i2++)
                for (int i3=i2+1; i3<m; i3++)
                if (!line(s[i1],s[i2],s[i3]))
                {
                    Tlen[N]=TriLength(s[i1],s[i2],s[i3]);
                    num[i1][i2][i3]=N;
                    int ss=0;
                    for (int j=0; j<n; j++)
                    if (PointInPolygon(tree[j],s[i1],s[i2],s[i3]))
                    {
                        ss|=(1<<tree[j].k);
                    }
                    sta[N]=ss;
                    N++;
                }
        for (int i1=0; i1<m; i1++)
         for (int i2=0; i2<m; i2++)
         if (i1!=i2)
          for (int i3=0; i3<m; i3++)
          if (i1!=i3 && i2!=i3)
          {
              if (i1<i2 && i2<i3) continue;

              int xx[4];
              xx[0]=i1; xx[1]=i2; xx[2]=i3;
              sort(xx,xx+3);
              num[i1][i2][i3]=num[xx[0]][xx[1]][xx[2]];
          }

         
        memset(g,-1,sizeof g);
        en=0;
        for (int i1=0; i1+1<m; i1++)
         for (int i2=i1+1; i2<m; i2++)
         {
             for (int i3=0; i3<m; i3++)
             if (i1!=i3 && i2!=i3)
             for (int i4=0; i4<m; i4++)
             if (i1!=i4 && i2!=i4 && i3!=i4)
             {
                 if (num[i1][i2][i3]!=-1 && num[i1][i2][i4]!=-1)
                 {
                     if (dcmp(Cross(s[i2]-s[i1],s[i3]-s[i1])*Cross(s[i2]-s[i1],s[i4]-s[i1]))==-1)
                     {
                         double len=Length(s[i4]-s[i1])+Length(s[i4]-s[i2])-Length(s[i2]-s[i1]);
                         addedge(num[i1][i2][i3],num[i1][i2][i4],len);
                     }
                 }
             }
         }
        double ans=slove();
        if (dcmp(fabs(inf-ans))==1) printf("%.10lf\n",ans);
        else puts("Impossible");
    }
    return 0;
}
