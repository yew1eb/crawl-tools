#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 210;
struct line
{
    double l,r,h;
    int f;
    line(){}
    line(double a,double b,double c,int d):l(a),r(b),h(c),f(d){}
}a[MAX<<1];
double sum[MAX<<2],x0[MAX];
int cov[MAX<<2];
map<double,int>m;
int cmp(const line &a,const line &b)
{
    return a.h<b.h;
}
void push_up(int l,int r,int rt)
{
    if(cov[rt]) sum[rt] = x0[r+1] - x0[l];
    else if(l==r) sum[rt]=0;
    else sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void update(int c,int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        cov[rt]+=c;
        push_up(l,r,rt);
        return;
    }
    int mid = r+l>>1;
    if(L<=mid) update(c,L,R,l,mid,rt<<1);
    if(R>mid) update(c,L,R,mid+1,r,rt<<1|1);
    push_up(l,r,rt);
}
int main()
{
    int n;
    double x1,x2,y1,y2;
    int cas = 0;
    while(scanf("%d",&n)&&n)
    {
        int cnt = 0;
        int flag = 0;

        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            a[cnt++] = line(x1,x2,y1,1);
            a[cnt++] = line(x1,x2,y2,-1);
            if(m[x1]==0) m[x1] = ++flag;
            if(m[x2]==0) m[x2] = ++flag;
        }
        map<double,int>::iterator iter;
        int k = 0;
        for(iter=m.begin(); iter!=m.end(); iter++)
        {
            x0[++k] = iter->first;
            iter->second = k;
        }
        sort(a,a+cnt,cmp);
        double ans = 0;
        memset(sum,0,sizeof(sum));
        memset(cov,0,sizeof(cov));
        for(int i=0; i<cnt-1; i++)
        {
            int l = m[a[i].l];
            int r = m[a[i].r]-1;
            update(a[i].f,l,r,1,flag,1);
            ans+=(a[i+1].h-a[i].h)*sum[1];
        }
        printf("Test case #%d\n",++cas);
        printf("Total explored area: %.2lf\n\n",ans);
        m.clear();
    }
    return 0;
}