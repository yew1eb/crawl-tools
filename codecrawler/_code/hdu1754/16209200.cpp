#include<stdio.h>
#include<string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define max 200010
int N,M;
int sum[max<<2];
int Max(int a,int b)
{
    return a>b?a:b;
}
void PushUp(int rt)
{
    sum[rt]=Max(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{

    if(l>=L&&r<=R)
    {
         return sum[rt];
    }
    int maxn=0;
    int m=(l+r)>>1;
    if(L<=m)
       maxn=Max(maxn,query(L,R,lson));
    if(R>m)
       maxn=Max(maxn,query(L,R,rson));
    return maxn;
}
void update(int L,int num,int l,int r,int rt)
{
    if(r==l)
    {
      sum[rt]=num;
      return ;
    }
    int m=(l+r)>>1;
    if(L<=m)
    update(L,num,lson);
    else
    update(L,num,rson);
    PushUp(rt);
}
int main()
{
    char op[2];
    int A,B;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        build(1,N,1);
        for(int i=0;i<M;i++)
        {
            scanf("%s%d%d",op,&A,&B);
            if(op[0]=='Q')
            {
                printf("%d\n",query(A,B,1,N,1));
            }
            else
            {
                update(A,B,1,N,1);
            }
        }
    }
    return 0;
}
