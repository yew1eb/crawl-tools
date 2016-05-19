#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int as[23][maxn*4];
int n,m;
void build(int rt,int l,int r,int d)
{
    int md=(l+r)>>1;
    for(int i = l; i <= r; ++ i)//保存rt节点下所有的叶子节点
        as[d][i]=as[d-1][i];
    if(l==r)return;
    build(rt<<1,l,md,d+1);
    build(rt<<1|1,md+1,r,d+1);
    sort(as[d]+l,as[d]+r+1);//给rt节点下的叶子节点排序
}
int bitser(int a,int b,int d,int v)//二分查找v值在区间[a,b]的位置
{
    int l = a,r = b,md;
    while(l < r){
        md = (l + r) >> 1;
        if(as[d][md]>v)r = md;
        else l = md + 1;
    }
    if(as[d][l]>v)--l;
    return l;
}
int tot;
void query(int rt,int l,int r,int L,int R,int v,int d)
{
    int md = (l + r) >> 1;
    if(L<=l && r<=R){
        int k = bitser(l,r,d,v);//k为在区间[l,r]上<=v的个数
        tot += k - l + 1;
        return ;
    }
    if(l>=r)return;
    if(L<=md)query(rt<<1,l,md,L,R,v,d+1);
    if(R>md )query(rt<<1|1,md+1,r,L,R,v,d+1);
}
int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; ++ i)
            scanf("%d",&as[0][i]);
        build(1,0,n-1,1);
        printf("Case %d:\n",++cas);
        while(m--){
            int l,r,v;
            scanf("%d %d %d",&l,&r,&v);
            tot = 0;
            query(1,0,n-1,l,r,v,1);
            printf("%d\n",tot);
        }
    }
    return 0;
}