#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
typedef long long LL;
const int N=100005;
struct Line
{
    int x,y1,y2,valu;
    Line(){}
    Line(int a,int b,int c,int d){x=a;y1=b;y2=c;valu=d;}
    bool operator<(const Line &b)const
    {
        return x<b.x;
    }
};
struct node
{
    int lft,rht,sum,valu;
    int mid(){return lft+(rht-lft)/2;}
};

map<int,int> imap;
vector<int> y;
vector<Line> line;
int data[N][4];

struct Segtree
{
    node tree[N*4];
    void relax(int ind)
    {
        if(tree[ind].valu>0) 
            tree[ind].sum=y[tree[ind].rht]-y[tree[ind].lft];
        else 
        {
            if(tree[ind].lft+1==tree[ind].rht) tree[ind].sum=0;
            else tree[ind].sum=tree[LL(ind)].sum+tree[RR(ind)].sum;
        }
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].sum=0;    tree[ind].valu=0;
        if(lft+1!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid,rht,RR(ind));
        }
    }
    void updata(int be,int end,int ind,int valu)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(be<=lft&&rht<=end) 
        {
            tree[ind].valu+=valu;
            relax(ind);
        }
        else 
        {
            int mid=tree[ind].mid();
            if(be<mid) updata(be,end,LL(ind),valu);
            if(end>mid) updata(be,end,RR(ind),valu);
            relax(ind);
        }
    }
}seg;

LL solve(int n,int w,int h,int m)
{
    y.clear();    line.clear(); imap.clear();
    y.push_back(1);    y.push_back(h);
    line.push_back(Line(max(1,w-m),1,h,1));    
    line.push_back(Line(w,1,h,-1));
    for(int i=0;i<n;i++) 
    {
        int x1=max(1,data[i][0]-m),y1=data[i][1];
        int x2=data[i][2],y2=data[i][3];
        line.push_back(Line(x1,y1,y2,1));
        line.push_back(Line(x2,y1,y2,-1));
        y.push_back(y1);y.push_back(y2);
    }
    sort(y.begin(),y.end());
    y.erase(unique(y.begin(),y.end()),y.end());
    for(int i=0;i<(int)y.size();i++) 
        imap.insert(make_pair(y[i],i));
    sort(line.begin(),line.end());

    LL res=0;
    seg.build(0,(int)y.size(),1);
    for(int i=0;i<(int)line.size();i++)
    {
        if(i!=0) res+=(LL)seg.tree[1].sum*(line[i].x-line[i-1].x);
        seg.updata(imap[line[i].y1],imap[line[i].y2],1,line[i].valu);
    }
    return res;
}
int main()
{
    int w,h,n,m;
    while(scanf("%d%d%d%d",&w,&h,&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<4;j++)
            {
                scanf("%d",&data[i][j]);
                if(j==2||j==3) data[i][j]++;
            }
        LL res1=(LL)w*h-solve(n,w+1,h+1,m-1);
        for(int i=0;i<n;i++) 
        {
            swap(data[i][0],data[i][1]);
            swap(data[i][2],data[i][3]);
        }
        LL res2=(LL)w*h-solve(n,h+1,w+1,m-1);
        if(m!=1) printf("%I64d\n",res1+res2);
        else printf("%I64d\n",res1);
    }
    return 0;
}
