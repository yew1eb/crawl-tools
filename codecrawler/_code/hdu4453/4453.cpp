#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 1100000
#define mem(a,b) memset(a,b,sizeof(a))
#define root10 ch[ch[root][1]][0]
#define root1 ch[root][1]
#define root11 ch[ch[root][1]][1]
#define lson ch[x][0]
#define rson ch[x][1]
int ch[maxn][2];
int pre[maxn];
int root,tot;
int val[maxn];
int rev[maxn];
int sum[maxn];
int size[maxn];
//----------------------
int num[maxn],n;
void Treaval(int x) {
    if(x) {
        Treaval(ch[x][0]);
        printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,key = %2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x]);
        Treaval(ch[x][1]);
    }
}
void debug() {printf("root:%d\n",root);Treaval(root);}
//以上Debug
void init()
{
    root=tot=0;
}
void newnode(int &x,int k,int father)
{
    x=++tot;
    pre[x]=father;
    size[x]=1;
    ch[x][0]=ch[x][1]=0;
    val[x]=k;
    rev[x]=0;
    sum[x]=0;
}
void push_down(int x)
{
    if(sum[x])
    {
        val[lson]+=sum[x];
        val[rson]+=sum[x];
        sum[lson]+=sum[x];
        sum[rson]+=sum[x];
        sum[x]=0;
    }
    if(rev[x])
    {
        rev[x]=0;
        rev[ch[x][0]]^=1;
        rev[ch[x][1]]^=1;
        swap(ch[x][0],ch[x][1]);
    }
}
void push_up(int x)
{
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void rot(int x,int kind)
{
    int y=pre[x];
    push_down(y);
    push_down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    push_up(y);
    push_up(x);
}
void splay(int x,int goal)
{
    push_down(x);
    while(pre[x]!=goal)
    {
        if(pre[pre[x]]==goal)
        {
            push_down(pre[x]);
            push_down(x);
            rot(x,ch[pre[x]][0]==x);
        }
        else
        {
            int y=pre[x];
            push_down(pre[y]);
            push_down(y);
            push_down(x);
            int kind=ch[pre[y]][0]==y;
            if(ch[y][kind]==x)
            {
                rot(x,!kind);
                rot(x,kind);
            }
            else
            {
                rot(y,kind);
                rot(x,kind);
            }
        }
    }
    push_up(x);
    if(goal==0)root=x;
}

void buildtree(int &x,int l,int r,int father)
{
    if(l>r)return;
    int mid=(l+r)/2;
    newnode(x,num[mid],father);
    buildtree(ch[x][0],l,mid-1,x);
    buildtree(ch[x][1],mid+1,r,x);
    push_up(x);
}

int get_kth(int x,int k)
{
    push_down(x);
    int p=size[ch[x][0]];
    if(p+1==k)return x;
    else if(k<=p)return get_kth(ch[x][0],k);
    else get_kth(ch[x][1],k-p-1);
}

int get_max(int r){
    push_down(r);
    while(ch[r][1]){
        r=ch[r][1];
        push_down(r);
    }
    return r;
}
int get_min(int r){
    push_down(r);
    while(ch[r][0]){
        r=ch[r][0];
        push_down(r);
    }
    return r;
}
void jie(int k)
{
    int x=get_kth(root,k+2);
    splay(x,root);
    push_up(root1);push_up(root);
}
void do_first(int k)
{
    int x=get_kth(root,k+1);
    splay(x,root);
    int z=root10;
    pre[z]=0;ch[x][0]=0;
    push_up(root1);push_up(root);

    int y=get_max(root);
    if(ch[y][0])
    {
        y=get_max(ch[y][0]);
        ch[y][1]=z;pre[z]=y;
    }
    else
    {
        ch[y][0]=z;pre[z]=y;
    }
    while(z)
    {
        push_up(z);
        z=pre[z];
    }
}

void insert(int k,int v)
{
    int x=get_kth(root,k);
   // cout<<k<<"--"<<x<<endl;
    if(ch[x][1]==0)
    {
        newnode(ch[x][1],v,x);
    }
    else
    {
        x=get_min(ch[x][1]);
        newnode(ch[x][0],v,x);
    }
    while(x)
    {
        push_up(x);
        x=pre[x];
    }
    n++;
}
int del(int k)
{
    int x=get_kth(root,k-1);
    int y=get_kth(root,k+1);
    splay(x,0);
    splay(y,root);

    x=root10;
    pre[x]=0;root10=0;
    push_up(root1);push_up(root);
    splay(1,0);
    n--;
    return val[x];
}
void move1()
{
    int x=del(n+1);
    insert(1,x);
}
int move2()
{
    int x=del(2);
    insert(n+1,x);
}
int main()
{
    int m,k1,k2;
    char str[10];
    int x;
    int cas=0;
    while(~scanf("%d%d%d%d",&n,&m,&k1,&k2)&&(n||m||k1||k2))
    {
        cas++;
        init();
        for(int i=1;i<=n;i++)scanf("%d",&num[i]);
        newnode(root,0,0);
        newnode(root1,0,root);
        buildtree(root10,1,n,root1);
        push_up(root1);
        push_up(root);
       printf("Case #%d:\n",cas);
       int pp=0;
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='a')
            {
                scanf("%d",&x);
                jie(k2);
                sum[root10]+=x;
                val[root10]+=x;
            }
            if(str[0]=='r')
            {
                jie(k1);
                rev[root10]^=1;
            }
            if(str[0]=='i')
            {
                scanf("%d",&x);
                insert(2,x);
            }
            if(str[0]=='d')
            {
                del(2);
            }
            if(str[0]=='m')
            {
                scanf("%d",&x);
                if(x==1)move1();
                if(x==2)move2();
            }
            if(str[0]=='q')
            {
                printf("%d\n",val[get_min(root1)]);
            }
        }
    }
    return 0;
}








