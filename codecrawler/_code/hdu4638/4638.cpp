#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
#include <queue>
#define INF (1<<30)
#define clearAll(a)  memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=100005;

struct node
{
    int cnt[N*4];
    void PushDown(int ind)
    {
        if(cnt[ind])
        {
            cnt[LL(ind)]+=cnt[ind];
            cnt[RR(ind)]+=cnt[ind];
            cnt[ind]=0;
        }
    }
    void build(int lft,int rht,int ind)
    {
        cnt[ind]=0;
        if(lft!=rht)
        {
            int mid=MID(lft,rht);
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int st,int ed,int lft,int rht,int ind)
    {
        if(st<=lft&&rht<=ed) cnt[ind]++;
        else
        {
            PushDown(ind);
            int mid=MID(lft,rht);
            if(st<=mid) updata(st,ed,lft,mid,LL(ind));
            if(ed> mid) updata(st,ed,mid+1,rht,RR(ind));

        }
    }
    int query(int pos,int lft,int rht,int ind)
    {
        if(lft==rht) return cnt[ind];
        else
        {
            PushDown(ind);
            int mid=MID(lft,rht);
            if(pos<=mid) return query(pos,lft,mid,LL(ind));
            else return query(pos,mid+1,rht,RR(ind));
        }
    }
}seg;

struct OP
{
    int st,ed,id;
    OP(){}
    OP(int st,int ed,int id) : st(st),ed(ed),id(id) {}
    bool operator<(const OP &B)const
    {
        return ed<B.ed;
    }
}op[N];

int pos[N],res[N],a[N];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(pos,-1,sizeof(pos));

        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=0;i<m;i++)
        {
            int st,ed; scanf("%d%d",&st,&ed);
            op[i]=OP(st,ed,i);
        }

        seg.build(1,n,1);

        sort(op,op+m);

        int ind=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=a[i];
            if(pos[tmp-1]>=1&&pos[tmp-1]<=i)
            {
                //cout<<"updata="<<1<<" "<<pos[tmp-1]<<endl;
                seg.updata(1,pos[tmp-1],1,n,1);
            }
            if(pos[tmp+1]>=1&&pos[tmp+1]<=i)
            {
                //cout<<"updata="<<1<<" "<<pos[tmp+1]<<endl;
                seg.updata(1,pos[tmp+1],1,n,1);
            }

            while(ind<m&&op[ind].ed==i)
            {
                int tmp=op[ind].ed-op[ind].st+1;
                //cout<<"query="<<op[ind].st<<" "<<op[ind].ed<<" "<<seg.query(op[ind].st,1,n,1)<<endl;
                res[op[ind].id]=tmp-seg.query(op[ind].st,1,n,1);
                ind++;
            }
        }
        for(int i=0;i<m;i++) printf("%d\n",res[i]);
    }
    return 0;
}