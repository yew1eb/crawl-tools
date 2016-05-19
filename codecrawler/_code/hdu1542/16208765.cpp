#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int l;
    int r;
    int cover;
    double len;
};
node tree[2000];
struct Line
{
    double down;
    double up;
    double x;
    int cover;
};
Line line[250];
double yy[250];
int n,len;
int cmp(Line a,Line b)
{
    return a.x<b.x;
}
int find(double x)
{
    int low=0,high=len,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(yy[mid]==x)
        return mid;
        if(yy[mid]<x)
        low=mid+1;
        else
        high=mid-1;
    }
    return low;
}
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].cover=0;
    tree[k].len=0;
    if(l+1==r)
    return;
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid,r);
}
void fun(int k)
{
    if(tree[k].cover)
    tree[k].len=yy[tree[k].r]-yy[tree[k].l];
    else if(tree[k].l+1==tree[k].r)
    tree[k].len=0;
    else 
    tree[k].len=tree[k<<1].len+tree[k<<1|1].len;
}
void update(int k,int l,int r,int cover)
{
    if(tree[k].l>r||tree[k].r<l)
    return;
    if(tree[k].l>=l&&tree[k].r<=r)
    {
        tree[k].cover+=cover;
        fun(k);
        return;
    }
    update(k<<1,l,r,cover);
    update(k<<1|1,l,r,cover);
    fun(k);
}
int main()
{
    double x1,y1,x2,y2,ans;
    int i,m,cas=1;
    int a,b;
    while(scanf("%d",&n)!=EOF,n)
    {
        m=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            yy[m]=y1;
            line[m].cover=1;
            line[m].x=x1;
            line[m].down=y1;
            line[m].up=y2;
            m++;
            yy[m]=y2;
            line[m].cover=-1;
            line[m].x=x2;
            line[m].down=y1;
            line[m].up=y2;
            m++;
        }
        sort(yy,yy+m);
        len=unique(yy,yy+m)-yy;
        len--;
        build(1,0,len);
        sort(line,line+m,cmp);
        ans=0;
        printf("Test case #%d\n",cas++);
        for(i=0;i<m-1;i++)
        {
            a=find(line[i].down);
            b=find(line[i].up);
            update(1,a,b,line[i].cover);
            ans+=tree[1].len*(line[i+1].x-line[i].x);
        }
        printf("Total explored area: %0.2lf\n\n",ans);
    }
    return 0;
}
