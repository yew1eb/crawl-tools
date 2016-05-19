#include <iostream>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define delf int m=(l+r)>>1
int sum[444444];
int len[2][3][444444];
int op[2][444444];

int max(int a,int b)
{
    return a>b?a:b;
}

void pushup(int l,int r,int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    for (int i=0;i<2;i++)
    {
        if (len[i][0][rt<<1]==(r-l+2)/2)
            len[i][0][rt]=len[i][0][rt<<1]+len[i][0][rt<<1|1];
        else
            len[i][0][rt]=len[i][0][rt<<1];
        if (len[i][2][rt<<1|1]==(r-l+1)/2)
            len[i][2][rt]=len[i][2][rt<<1]+len[i][2][rt<<1|1];
        else
            len[i][2][rt]=len[i][2][rt<<1|1];
        len[i][1][rt]=max(len[i][2][rt<<1]+len[i][0][rt<<1|1],max(len[i][1][rt<<1],len[i][1][rt<<1|1]));
    }
}

void build(int l,int r,int rt)
{
    op[0][rt]=-1;
    op[1][rt]=0;
    if (l==r)
    {
        scanf("%d",&sum[rt]);
        len[1][0][rt]=len[1][1][rt]=len[1][2][rt]=sum[rt];
        len[0][0][rt]=len[0][1][rt]=len[0][2][rt]=1-sum[rt];
        return ;
    }
    delf;
    build(lson);
    build(rson);
    pushup(l,r,rt);
}

void opea(int l,int r,int rt)
{
    if (op[0][rt]!=-1)
        op[0][rt]=1-op[0][rt];
    else
    {
        if (op[1][rt]==1)
            op[1][rt]=0;
        else       
            op[1][rt]=1;  
    } 
    sum[rt]=r-l+1-sum[rt];
    for (int i=0;i<3;i++)
    {
        int t=len[0][i][rt];
        len[0][i][rt]=len[1][i][rt];
        len[1][i][rt]=t;
    }
}

void setupdate(int v,int l,int r,int rt)
{
    sum[rt]=(r-l+1)*v;
    op[1][rt]=0;
    op[0][rt]=v;
    for (int i=0;i<3;i++)
    {
        len[0][i][rt]=(r-l+1)*(1-op[0][rt]);
        len[1][i][rt]=(r-l+1)*op[0][rt];
    }
}

void pushdown(int l,int r,int rt)
{
    if (op[0][rt]>=0)
    {
        delf;
        setupdate(op[0][rt],lson);
        setupdate(op[0][rt],rson);
        op[0][rt]=-1;
    }
    if(op[1][rt])
    {
        delf;
        opea(lson);
        opea(rson);
        op[1][rt]=0;
    } 
}

void update(int L,int R,int k,int l,int r,int rt)
{
    if (L<=l&&r<=R)
    {
        if (k==0||k==1)
            setupdate(k,l,r,rt);
        else
            opea(l,r,rt);
        return ;
    }
    pushdown(l,r,rt);
    delf;
    if (m>=L)
        update(L,R,k,lson);
    if (R>m)
        update(L,R,k,rson);
    pushup(l,r,rt);
}

int query(int L,int R,int l,int r,int rt)
{      
    if (L==l&&r==R)
        return len[1][1][rt];
    pushdown(l,r,rt);   
    delf;
    if (L>m)
        return query(L,R,rson);
    if (R<=m)
        return query(L,R,lson);
    if (L<=m&&R>m)
    {
        int lr = query(L,m,lson);//左子树  
        int rr = query(m+1,R,rson);//右子树  
            //中间  
        int a = len[1][2][rt<<1];//左子树右边最长连续1，注意它的个数不应该大于区间[l,tree[rt<<1].r]的个数   
        if (a>m-L+1)
            a=m-L+1; 
        int b = len[1][0][rt<<1|1];//右子树左边最长连续1，注意它的个数不应该大于区间[tree[rt<<1|1].l,r]的个数  
        if (b>R-m)
            b=R-m;              
        return max(max(lr,rr),a+b);//最后取左子树、右子树和中间三者的最大值       
    }
}

int Query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R)
        return sum[rt];
    pushdown(l,r,rt);
    delf;
    int s=0;
    if (L<=m)
        s=s+Query(L,R,lson);
    if (R>m)
        s=s+Query(L,R,rson);
    pushup(l,r,rt);
    return s;
}

int main()
{
    int m,n;
    int r;
    scanf("%d",&r);
    while (r--)
    {
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while (m--)
        {
            int k,a,b;
            scanf("%d%d%d",&k,&a,&b);
            if (k<=2)
                update(a+1,b+1,k,1,n,1);
            if (k==3)
                printf("%d\n",Query(a+1,b+1,1,n,1));
            if (k==4)   
                printf("%d\n",query(a+1,b+1,1,n,1));
        }
    } 
}