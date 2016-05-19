#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
const int N=2000;

struct Line
{
    int flag;
    double x,y1,y2;
    Line(){}
    Line(double a,double b,double c,int d)
    { x=a;y1=b;y2=c;flag=d; }
    bool operator<(const Line &b)const
    { return x<b.x; }
};
struct node
{
    int lft,rht,flag;
    double len[3];
    int mid(){return MID(lft,rht);}
    void init(){memset(len,0,sizeof(len));}
};

int n;
vector<double> y;
vector<Line> line;
map<double,int> H;

struct Segtree
{
    node tree[N*4];
    void calu_len(int ind)
    {
        if(tree[ind].flag>=2)
        {
            tree[ind].len[2]=tree[ind].len[0];
            tree[ind].len[1]=0;
        }
        else if(tree[ind].flag==1)
        {
            if(tree[ind].lft+1==tree[ind].rht) tree[ind].len[2]=0;
            else tree[ind].len[2]=tree[LL(ind)].len[2]+tree[RR(ind)].len[2]
                +tree[LL(ind)].len[1]+tree[RR(ind)].len[1];
            tree[ind].len[1]=tree[ind].len[0];
            tree[ind].len[1]-=tree[ind].len[2];
        }
        else
        {
            if(tree[ind].lft+1==tree[ind].rht)
                tree[ind].len[1]=tree[ind].len[2]=0;
            else
            {
                tree[ind].len[2]=tree[LL(ind)].len[2]+tree[RR(ind)].len[2];
                tree[ind].len[1]=tree[LL(ind)].len[1]+tree[RR(ind)].len[1];
            }
        }
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].init();    tree[ind].flag=0;
        tree[ind].len[0]=y[rht]-y[lft];
        if(lft+1!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid,rht,RR(ind));
        }
    }
    void updata(int st,int ed,int ind,int valu)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) tree[ind].flag+=valu;
        else
        {
            int mid=tree[ind].mid();
            if(st<mid) updata(st,ed,LL(ind),valu);
            if(ed>mid) updata(st,ed,RR(ind),valu);
        }
        calu_len(ind);
    }
}seg;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        y.clear(); H.clear(); line.clear();

        scanf("%d",&n);

        double x1,y1,x2,y2;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            line.push_back(Line(x1,y1,y2,1));
            line.push_back(Line(x2,y1,y2,-1));
            y.push_back(y1);  y.push_back(y2);
        }

        sort(line.begin(),line.end());
        sort(y.begin(),y.end());
        y.erase(unique(y.begin(),y.end()),y.end());
        for(int i=0;i<(int)y.size();i++) H[y[i]]=i;
        seg.build(0,(int)y.size()-1,1);

        double res=0;
        for(int i=0;i<(int)line.size();i++)
        {
            if(i!=0) res+=(line[i].x-line[i-1].x)*seg.tree[1].len[2];
            seg.updata(H[line[i].y1],H[line[i].y2],1,line[i].flag);
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
