#include <cstdio> 
 using namespace std; 
 
 #define lch (rt<<1) 
 #define rch (rt<<1|1) 
 const int N=50010; 
 int u[N],v[N],se; 
 struct node 
 { 
 int l,r; 
 int len() {return r-l+1;} 
 int s,ls,rs,cnt,c; 
 }st[N*4]; 
 int max(int x,int y,int z) 
 { 
 int t=x>y?x:y; 
 return t>z?t:z; 
 } 
 void build(int l,int r,int rt) 
 { 
 st[rt].l=l; st[rt].r=r; 
 st[rt].s=st[rt].ls=st[rt].rs=r-l+1; 
 st[rt].cnt=0; st[rt].c=-1; 
 if(l==r) return; 
 int m=(l+r)/2; 
 build(l,m,lch); 
 build(m+1,r,rch); 
 } 
 void pushdown(int rt) 
 { 
 if(st[rt].c==-1) return; 
 st[lch].c=st[rch].c=st[rt].c; 
 if(st[rt].c==0) 
 { 
 st[lch].s=st[lch].ls=st[lch].rs=st[lch].len(); 
 st[rch].s=st[rch].ls=st[rch].rs=st[rch].len(); 
 } 
 else st[lch].s=st[lch].ls=st[lch].rs=st[rch].s=st[rch].ls=st[rch].rs=0; 
 st[rt].c=-1; 
 } 
 void pushup(int rt) 
 { 
 st[rt].s=max(st[lch].s,st[rch].s,st[lch].rs+st[rch].ls); 
 st[rt].ls=st[lch].ls; 
 if(st[lch].ls==st[lch].len()) st[rt].ls+=st[rch].ls; 
 st[rt].rs=st[rch].rs; 
 if(st[rch].rs==st[rch].len()) st[rt].rs+=st[lch].rs; 
 } 
 void update(int a,int b,int x,int rt) 
 { 
 int l=st[rt].l, r=st[rt].r; 
 if(a<=l && r<=b) 
 { 
 st[rt].c=x; 
 if(x==0) st[rt].s=st[rt].ls=st[rt].rs=st[rt].len(); 
 else st[rt].s=st[rt].ls=st[rt].rs=0; 
 return; 
 } 
 pushdown(rt); 
 int m=(l+r)/2; 
 if(a<=m) update(a,b,x,lch); 
 if(b>m) update(a,b,x,rch); 
 pushup(rt); 
 } 
 void update2(int a,int x,int rt) 
 { 
 int l=st[rt].l, r=st[rt].r; 
 if(l==r) 
 { 
 st[rt].cnt=x; 
 return; 
 } 
 int m=(l+r)/2; 
 if(a<=m) update2(a,x,lch); 
 else update2(a,x,rch); 
 st[rt].cnt=st[lch].cnt+st[rch].cnt; 
 } 
 int query1(int x,int rt) 
 { 
 int l=st[rt].l, r=st[rt].r; 
 if(l==r) return l; 
 pushdown(rt); 
 if(st[lch].s>=x) return query1(x,lch); 
 if(st[lch].rs+st[rch].ls>=x) return st[lch].r-st[lch].rs+1; 
 return query1(x,rch); 
 } 
 int query2(int x,int rt) 
 { 
 int l=st[rt].l, r=st[rt].r; 
 if(l==r) return st[rt].c; 
 pushdown(rt); 
 int m=(l+r)/2; 
 if(x<=m) return query2(x,lch); 
 else return query2(x,rch); 
 } 
 int query3(int x,int rt) 
 { 
 int l=st[rt].l, r=st[rt].r; 
 if(l==r) return l; 
 if(x>st[lch].cnt) return query3(x-st[lch].cnt,rch); 
 else return query3(x,lch); 
 } 
 int main() 
 { 
 int n,m; 
 while(~scanf("%d%d",&n,&m)) 
 { 
 se=0; 
 build(1,n,1); 
 st[1].c=0; 
 while(m--) 
 { 
 char op[10]; 
 scanf("%s",op); 
 if(op[0]=='R') 
 { 
 printf("Reset Now\n"); 
 update(1,n,0,1); 
 for(int i=1;i<=se;i++) update2(u[i],0,1); 
 se=0; 
 } 
 else if(op[0]=='N') 
 { 
 int x; 
 scanf("%d",&x); 
 if(x<=st[1].s) 
 { 
 int k=query1(x,1); 
 printf("New at %d\n",k); 
 se++; 
 u[se]=k; v[se]=k+x-1; 
 update(u[se],v[se],se,1); 
 update2(u[se],1,1); 
 } 
 else printf("Reject New\n"); 
 } 
 else if(op[0]=='F') 
 { 
 int x; 
 scanf("%d",&x); 
 int k=query2(x,1); 
 if(k!=0) 
 { 
 printf("Free from %d to %d\n",u[k],v[k]); 
 update(u[k],v[k],0,1); 
 update2(u[k],0,1); 
 } 
 else printf("Reject Free\n"); 
 } 
 else if(op[0]=='G') 
 { 
 int x; 
 scanf("%d",&x); 
 if(st[1].cnt>=x) 
 { 
 int k=query3(x,1); 
 printf("Get at %d\n",k); 
 } 
 else printf("Reject Get\n"); 
 } 
 } 
 printf("\n"); 
 } 
 return 0; 
 }