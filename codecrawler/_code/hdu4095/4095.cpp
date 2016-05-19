#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXV = 101010;
const long long INF = 1010101010101LL;
struct pt{
    long long val;
    int order,l,r,pnt;
}p[MAXV];
bool cmp(pt x,pt y){return (x.val < y.val);}
int n,root;
void insert(int i){
    int j = i-1;
    while (p[j].order < p[i].order) j = p[j].pnt;
    p[i].l = p[j].r;
    p[p[i].l].pnt = i;
    p[j].r = i;
    p[i].pnt = j;
}

vector<pair<int,char> > c[200010];
int cnt;
struct stackifo{
    int x,deep;
    int state,tmp;
    stackifo(int a,int b,int c,int t)
    {
        x=a,deep=b,state=c,tmp=t;
    }
};
void dfs()
{
    stack<stackifo> S;
    stackifo s(0,0,0,0);
    S.push(stackifo(root,1,0,-1));
    int tmp;
    while (!S.empty())
    {
        s=S.top();
        S.pop();
        if (s.state==0)
        {
            if (p[s.x].l!=0)
            {
                s.state=1;
                S.push(s);
                S.push(stackifo(p[s.x].l,s.deep+2,0,-1));
                continue;
            }
            else s.state=2;
        }
        else if (s.state==1)
        {
            c[s.deep].push_back(make_pair(tmp,'L'));
            c[s.deep+1].push_back(make_pair(tmp,'|'));
            s.state=2;
        }
        if (s.state==2)
        {
            s.tmp=cnt++;
            c[s.deep].push_back(make_pair(s.tmp,'o'));
            s.state=3;
        }
        if (s.state==3)
        {
            if (p[s.x].r!=0)
            {
                s.state=4;
                S.push(s);
                S.push(stackifo(p[s.x].r,s.deep+2,0,-1));
                continue;
            }
            else s.state=5;
        }
        else if (s.state==4)
        {
            c[s.deep].push_back(make_pair(tmp,'R'));
            c[s.deep+1].push_back(make_pair(tmp,'|'));
            s.state=5;
        }
        if (s.state==5)
        {
            tmp=s.tmp;
        }
    }



  /*  if (p[x].l!=0)
    {
        int l=dfs(p[x].l,deep+2);
        c[deep].push_back(make_pair(l,'L'));
        c[deep+1].push_back(make_pair(l,'|'));
    }
    int ans=cnt++;
    c[deep].push_back(make_pair(ans,'o'));
    if (p[x].r!=0)
    {
        int r=dfs(p[x].r,deep+2);
        c[deep].push_back(make_pair(r,'R'));
        c[deep+1].push_back(make_pair(r,'|'));
    }
    return ans;*/
}

int find(int x,int v)
{
    int l=-1,r=c[x].size();
    while (l+1<r)
    {
        int m=(l+r)/2;
        if (c[x][m].first>v)
            r=m;
        else
            l=m;
    }
    return l;
}

int main(){
   // freopen("test.in","r",stdin);
    int T;scanf("%d",&T);
    for (int ca=1;ca<=T;ca++){
        scanf("%d",&n);
        printf("Case #%d:\n",ca);
        for (int i=1;i<=n;i++){
            scanf("%I64d",&p[i].val);
            p[i].l = p[i].r = p[i].pnt = 0;
            p[i].order = n-i;
        }
        p[0].order = n+1; p[0].val = -INF;
        p[0].l = p[0].r = p[0].pnt = 0;
        sort(p,p+1+n,cmp);
        for (int i=1;i<=n;i++)  insert(i);
        root = p[0].r;

        cnt=1;
        for (int i=1;i<200010;i++)
        {
            c[i].clear();
        }

        dfs();
    /*    for (int i=1;i<=n*2;i++)
        {
            for (int j=0;j<c[i].size();j++)
                printf("%d %c ",c[i][j].first,c[i][j].second);
            printf("\n");
        }*/
        int M;
        scanf("%d",&M);
        while (M-->0)
        {
            int x,y,a,b;
            scanf("%d%d%d%d",&x,&y,&a,&b);
            for (int i=x;i<x+a;i++)
            {
                int begin=find(i,y);
                char state=' ';
                if (begin>=0 && (c[i][begin].second=='L'|| (c[i][begin].second=='o'&& begin+1<c[i].size()&& c[i][begin+1].second=='R')))
                    state='-';
                if (begin<0 || c[i][begin].first<y) begin++;
                string ans="";
                for (int j=y;j<y+b;j++)
                {
                    if (begin<c[i].size() && c[i][begin].first==j)
                    {
                        if (c[i][begin].second=='L')
                        {
                            ans=ans+"+";
                            state='-';
                        }
                        else if (c[i][begin].second=='R')
                        {
                            ans=ans+"+";
                            state=' ';
                        }
                        else if (c[i][begin].second=='o')
                        {
                            ans=ans+"o";
                            if (begin+1<c[i].size() && c[i][begin+1].second=='R')
                                state='-';
                            else
                                state=' ';
                        }
                        else if (c[i][begin].second=='|')
                        {
                            ans=ans+'|';
                        }
                        begin++;
                    }
                    else
                    {
                        ans=ans+state;
                    }
                }
                bool flag=false;
                for (int k=0;k<ans.length();k++)
                {
                    if (ans[k]!=' ')
                    {
                        flag=true;
                        break;
                    }
                }
                if (flag)
                    puts(ans.c_str());
            }
            printf("\n");
        }

    }
    return 0;
}