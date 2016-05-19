#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#define MAX 101
#define L(x) (x<<1)
#define R(x) (x<<1|1)
using namespace std;
class subnode
{
    public:
        int l,r;
        double val;
        subnode(){};
        subnode(int a,int b):l(a),r(b)
        {}
        void set(int a,int b)
        {
            l=a;
            r=b;
        }
        bool leaf()
        {
            return l==r;
        }
        int mid()
        {
            return (l+r)>>1;
        }
        bool cover(int a,int b)
        {
            if(a<=l&&r<=b)
              return true;
            return false;
        }
};
class node
{
    public:
        int l,r;
        subnode sub[MAX*10*3];
        node(){};
        node(int a,int b):l(a),r(b)
        {}
        void set(int a,int b)
        {
            l=a;
            r=b;
        }
        bool leaf()
        {
            return l==r;
        }
        int mid()
        {
            return (l+r)>>1;
        }
        bool cover(int a,int b)
        {
            if(l>=a&&r<=b)
              return true;
            return false;
        }
}a[MAX*3];
void subbuild(int t,int f,int l,int r)
{
    a[t].sub[f].set(l,r);
    a[t].sub[f].val=-1;
    if(l==r)
      return;
    int mid=(l+r)>>1;
    subbuild(t,L(f),l,mid);
    subbuild(t,R(f),mid+1,r);
}
void build(int t,int x1,int x2,int y1,int y2)
{
    a[t].set(x1,x2);
    subbuild(t,1,y1,y2);
    if(x1==x2)
      return;
    int mid=(x1+x2)>>1;
    build(L(t),x1,mid,y1,y2);
    build(R(t),mid+1,x2,y1,y2);

}
void subupdate(int t,int f,int l,int r,double val)
{
    a[t].sub[f].val=max(a[t].sub[f].val,val);
    if(a[t].sub[f].leaf())
      return;
    int mid=a[t].sub[f].mid();
    if(l<=mid)
      subupdate(t,L(f),l,r,val);
    if(r>mid)
      subupdate(t,R(f),l,r,val);
}
void update(int t,int x1,int x2,int y1,int y2,double val)
{
    subupdate(t,1,y1,y2,val);
    if(a[t].leaf())
      return ;
    int mid=a[t].mid();
    if(x1<=mid)
      update(L(t),x1,x2,y1,y2,val);
    if(x2>mid)
      update(R(t),x1,x2,y1,y2,val);
}
double subquery(int t,int f,int l,int r)
{
    if(a[t].sub[f].cover(l,r))
      return a[t].sub[f].val;
    if(a[t].sub[f].leaf())return -1;
    int mid=a[t].sub[f].mid();
    double ans=-1;
    if(l<=mid)
      ans=max(ans,subquery(t,L(f),l,r));
    if(r>mid)
      ans=max(ans,subquery(t,R(f),l,r));
    return ans;
}
double query(int t,int x1,int x2,int y1,int y2)
{
    if(a[t].cover(x1,x2))
      return subquery(t,1,y1,y2);
    if(a[t].leaf())return -1;
    int mid=a[t].mid();
    double ans=-1;
    if(x1<=mid)
      ans=max(ans,query(L(t),x1,x2,y1,y2));
    if(x2>mid)
      ans=max(ans,query(R(t),x1,x2,y1,y2));
    return ans;
}
int main()
{
    int n;
    double x1,x2,y1,y2;
    char s[2];
    int eps=1e-6;
    while(scanf("%d",&n))
    {
        if(n==0)break;
        build(1,100,200,0,1000);
        while(n--)
        {
            scanf("%s",s);
            if(s[0]=='I')
            {
                scanf("%lf%lf%lf",&x1,&x2,&y1);
                update(1,int(x1),int(x1),int(x2*10),int((x2)*10),y1);
            }
            else
            {
                scanf("%lf%lf%lf%lf",&x1,&x2,&y1,&y2);
                if(x1>x2)
                    swap(x1,x2);//ä¸å ä¼é
                if(y1>y2)
                    swap(y1,y2);
                double ans=query(1,int(x1),int(x2),int((y1)*10),int((y2)*10));
                if(ans==-1)
                printf("-1\n");//è¾åº-1ï¼ä¸æ¯-1.0
                else
                printf("%.1lf\n",ans);
            }
        }
    }
}