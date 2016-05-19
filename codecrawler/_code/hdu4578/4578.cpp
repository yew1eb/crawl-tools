#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
inline int input()
{
    int r=0;
    char c;
    c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') r=r*10+c-'0',c=getchar();
    return r;
}


#define N 100010
#define M 10007
struct node
{
    int l,r;
    int lazy1,lazy2,lazy3,p1,p2,p3;
}root[N*6];

inline void change_eq(int t,int val)
{
    int l=root[t].r-root[t].l+1;
    root[t].lazy1=0;
    root[t].lazy2=1;
    root[t].lazy3=val%M;
    root[t].p1=val*l%M;
    root[t].p2=val%M*val%M*l%M;
    root[t].p3=val%M*val%M*val%M*l%M;
}
inline void change_add_mut(int t,int v1,int v2)
{
    int l=root[t].r-root[t].l+1;
    root[t].lazy2=root[t].lazy2*(v2%M)%M;
    root[t].lazy1=(root[t].lazy1*v2%M+v1%M)%M;
    root[t].p3=(root[t].p3%M*v2%M*v2%M*v2%M+v1%M*v1%M*v1%M*l%M+3*v2%M*v2%M*v1%M*root[t].p2%M+3*v2%M*v1%M*v1%M*root[t].p1%M)%M;
    root[t].p2=(root[t].p2%M*v2%M*v2%M+v1%M*v1%M*l%M+2*v2%M*v1%M*root[t].p1%M)%M;
    root[t].p1 =(v2 *root[t].p1%M +v1%M*l%M)%M;
}

inline void pushup(int t)
{
    root[t].p1=(root[t*2].p1%M+root[t*2+1].p1%M)%M;
    root[t].p2=(root[t*2].p2%M+root[t*2+1].p2%M)%M;
    root[t].p3=(root[t*2].p3%M+root[t*2+1].p3%M)%M;
}
inline void pushdown_eq(int t)
{
    if(root[t].l==root[t].r) return;
    if(root[t].lazy3!=0)
    {
        change_eq(t*2,root[t].lazy3);
        change_eq(t*2+1,root[t].lazy3);
        root[t].lazy3=0;
    }
}
inline void pushdown_add_mut(int t)
{
    if(root[t].l==root[t].r) return;
    if(root[t].lazy1!=0||root[t].lazy2!=1)
    {
        change_add_mut(t*2,root[t].lazy1,root[t].lazy2);
        change_add_mut(t*2+1,root[t].lazy1,root[t].lazy2);
        root[t].lazy1=0;
        root[t].lazy2=1;
    }
}


inline void build_tree(int t,int x,int y)
{
    root[t].l=x;
    root[t].r=y;
    root[t].p1=root[t].p2=root[t].p3=0;
    root[t].lazy1=root[t].lazy3=0;
    root[t].lazy2=1;
    if(x==y) return;
    int m=(x+y)>>1;
    build_tree(t*2,x,m);
    build_tree(t*2+1,m+1,y);
}
inline void Modefiy_eq(int t,int x,int y,int val)
{
    int l=root[t].l;
    int r=root[t].r;
    if(l==x&&r==y)
    {
        change_eq(t,val);
        return;
    }
    pushdown_eq(t);
    pushdown_add_mut(t);
    int m=(l+r)>>1;
    if(x<=m) Modefiy_eq(t*2,x,min(m,y),val);
    if(y>m)  Modefiy_eq(t*2+1,max(x,m+1),y,val);
    pushup(t);
}
inline void Modefiy_add_mut(int t,int x,int y,int val,int op)
{
    int l=root[t].l;
    int r=root[t].r;
    if(l==x&&r==y)
    {
        val%=M;
        if(op==1)
        {
            int l=root[t].r-root[t].l+1;
            root[t].lazy1=(root[t].lazy1+val)%M;
            root[t].p3=(root[t].p3%M+3*val%M*root[t].p2%M+3*val%M*val%M*root[t].p1%M+val%M*val%M*val%M*l%M)%M;
            root[t].p2=(root[t].p2%M+root[t].p1%M*2*val%M+val%M*val%M*l%M)%M;
            root[t].p1=(root[t].p1+val*l%M)%M;
        }
        else if(op==2)
        {
            root[t].lazy1 =(root[t].lazy1*val%M)%M;
            root[t].lazy2 =(root[t].lazy2*val%M)%M;
            root[t].p1=(root[t].p1%M*val%M)%M;
            root[t].p2=(root[t].p2%M*val%M*val%M)%M;
            root[t].p3=(root[t].p3%M*val%M*val%M*val%M)%M;
        }
        return;
    }
    pushdown_eq(t);
    pushdown_add_mut(t);
    int m=(l+r)>>1;
    if(x<=m) Modefiy_add_mut(t*2,x,min(m,y),val,op);
    if(y>m)  Modefiy_add_mut(t*2+1,max(m+1,x),y,val,op);
    pushup(t);
}

inline int query(int t,int x,int y,int op)
{
    int l=root[t].l;
    int r=root[t].r;
    if(l==x&&r==y)
    {
        if(op==1) return root[t].p1%M;
        else if(op==2) return root[t].p2%M;
        else if(op==3) return root[t].p3%M;
    }
    pushdown_eq(t);
    pushdown_add_mut(t);
    int m=(l+r)>>1;
    int ans=0;
    if(x<=m) ans+=query(t*2,x,min(m,y),op),ans%=M;
    if(y>m)  ans+=query(t*2+1,max(x,m+1),y,op),ans%=M;
    return ans%M;
}

int n,m,op,x,y,z;
int main()
{
    while(1)
    {
        n=input(),m=input();
        if(n==0&&m==0) break;
        build_tree(1,1,n);
        while(m--)
        {
            op=input(),x=input(),y=input(),z=input();
            if(op==1) Modefiy_add_mut(1,x,y,z,1);
            else if(op==2) Modefiy_add_mut(1,x,y,z,2);
            else if(op==3) Modefiy_eq(1,x,y,z);
            else if(op==4) printf("%d\n",query(1,x,y,z));
        }
    }
    return 0;
}
