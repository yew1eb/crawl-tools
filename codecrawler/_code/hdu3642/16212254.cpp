#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
typedef long long LL;
const int N=2005;

struct CUBE
{
    int x1,y1,z1;
    int x2,y2,z2;
    void get()
    {
        scanf("%d%d%d",&x1,&y1,&z1);
        scanf("%d%d%d",&x2,&y2,&z2);
    }
}cube[N];
struct Line
{
    int x,y1,y2,flag;
    Line(){}
    Line(int a,int b,int c,int d)
    { x=a;y1=b;y2=c;flag=d; }
    bool operator<(const Line &b)const
    { return x<b.x; }
};
struct node
{
    int lft,rht,flag,len[4];
    int mid(){return MID(lft,rht);}
    void init(){memset(len,0,sizeof(len));}
};

vector<int> y,z;
vector<Line> line;
map<int,int> H;

struct Segtree
{
    node tree[N*4];
    void calu(int ind)
    {
        if(tree[ind].flag>=3)
        {
            tree[ind].len[3]=tree[ind].len[0];
            tree[ind].len[2]=tree[ind].len[1]=0;
        }
        else if(tree[ind].flag==2)
        {
            tree[ind].len[2]=tree[ind].len[0];
            if(tree[ind].lft+1==tree[ind].rht)
            {
                tree[ind].len[1]=tree[ind].len[3]=0;
            }
            else
            {
                tree[ind].len[3]=tree[LL(ind)].len[3]+tree[RR(ind)].len[3]
                    +tree[LL(ind)].len[2]+tree[RR(ind)].len[2]
                    +tree[LL(ind)].len[1]+tree[RR(ind)].len[1];
                tree[ind].len[1]=0;
                tree[ind].len[2]-=tree[ind].len[3];
            }
        }
        else if(tree[ind].flag==1)
        {
            tree[ind].len[1]=tree[ind].len[0];
            if(tree[ind].lft+1==tree[ind].rht)
            {
                tree[ind].len[2]=tree[ind].len[3]=0;
            }
            else
            {
                tree[ind].len[3]=tree[LL(ind)].len[3]+tree[RR(ind)].len[3]
                    +tree[LL(ind)].len[2]+tree[RR(ind)].len[2];
                tree[ind].len[2]=tree[LL(ind)].len[1]+tree[RR(ind)].len[1];
                tree[ind].len[1]-=(tree[ind].len[2]+tree[ind].len[3]);
            }
        }
        else
        {
            if(tree[ind].lft+1==tree[ind].rht)
            {
                tree[ind].len[1]=tree[ind].len[2]=tree[ind].len[3]=0;
            }
            else
            {
                tree[ind].len[3]=tree[LL(ind)].len[3]+tree[RR(ind)].len[3];
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
        calu(ind);
    }
}seg;
int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        y.clear(); z.clear(); line.clear(); H.clear();

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cube[i].get();
            y.push_back(cube[i].y1); y.push_back(cube[i].y2);
            z.push_back(cube[i].z1); z.push_back(cube[i].z2);
        }
        printf("Case %d: ",++t_cnt);
        if(n<3) {puts("0");continue;}
        else
        {
            sort(y.begin(),y.end());
            sort(z.begin(),z.end());
            y.erase(unique(y.begin(),y.end()),y.end());
            z.erase(unique(z.begin(),z.end()),z.end());
            for(int i=0;i<(int)y.size();i++) H[y[i]]=i;

            LL res=0;
            seg.build(0,(int)y.size()-1,1);
            for(int i=0;i<(int)z.size()-1;i++)
            {
                line.clear();
                for(int j=0;j<n;j++)
                {
                    if(cube[j].z1<=z[i]&&cube[j].z2>=z[i+1])
                    {
                        line.push_back(Line(cube[j].x1,cube[j].y1,cube[j].y2,1));
                        line.push_back(Line(cube[j].x2,cube[j].y1,cube[j].y2,-1));
                    }
                }
                sort(line.begin(),line.end());
                for(int j=0;j<(int)line.size();j++)
                {
                    if(j!=0) res+=(z[i+1]-z[i])*(line[j].x-line[j-1].x)*(LL)seg.tree[1].len[3];
                    seg.updata(H[line[j].y1],H[line[j].y2],1,line[j].flag);
                }
            }
            printf("%I64d\n",res);
        }
    }
    return 0;
}