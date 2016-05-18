#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 100005
#define lson l,m,ls[s]
#define rson m+1,r,rs[s]
typedef long long LL;
int ls[20*MAXN],rs[20*MAXN];
int cnt[20*MAXN],T[MAXN];
int a[MAXN],num[MAXN];
char op[2*MAXN][15];
int L[2*MAXN],R[2*MAXN],K[2*MAXN];
int tot;
vector<int>ivec;
void build(int l,int r,int &s)
{
    s=++tot;
    cnt[s]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int last,int p,int l,int r,int &s)
{
    s=++tot;
    ls[s]=ls[last],rs[s]=rs[last];
    cnt[s]=cnt[last]+1;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) update(ls[last],p,lson);
    else     update(rs[last],p,rson);
}
int query(int ss,int tt,int l,int r,int k)
{
    if(l==r) return r;
    int sum=cnt[ls[tt]]-cnt[ls[ss]];
    int m=(l+r)>>1;
    if(sum>=k) return query(ls[ss],ls[tt],l,m,k);
    else       return query(rs[ss],rs[tt],m+1,r,k-sum);
}
int main()
{
    int m,kase=0;
    while(scanf("%d",&m)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        int len=0,n;
        LL qy1=0,qy2=0,qy3=0;
        ivec.clear();
        for(int i=0; i<m; i++)
        {
            scanf("%s%d",op[i],&L[i]);
            if(!strcmp(op[i],"Insert"))
            {
                ++len;
                num[len]=a[len]=L[i];
            }
            else if(!strcmp(op[i],"Query_1"))
                scanf("%d%d",&R[i],&K[i]);
        }
        sort(a+1,a+len+1);
        n=len;
        len=unique(a+1,a+len+1)-a-1;
        for(int i=1; i<=n; i++) num[i]=lower_bound(a+1,a+len+1,num[i])-a;
        tot=0;
        build(1,len,T[0]);
        for(int i=1; i<=n; i++) update(T[i-1],num[i],1,len,T[i]);
        for(int i=0; i<m; i++)
        {
            if(!strcmp(op[i],"Insert"))
                ivec.insert(lower_bound(ivec.begin(),ivec.end(),L[i]),L[i]);
            else if(!strcmp(op[i],"Query_1"))
                qy1+=a[query(T[L[i]-1],T[R[i]],1,len,K[i])];
            else if(!strcmp(op[i],"Query_2"))
                qy2+=lower_bound(ivec.begin(),ivec.end(),L[i])-ivec.begin()+1;
            else
                qy3+=ivec[L[i]-1];
        }
        printf("Case %d:\n",++kase);
        printf("%I64d\n%I64d\n%I64d\n",qy1,qy2,qy3);
    }
    return 0;
}