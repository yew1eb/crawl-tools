#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define red(i,s,t) for(int i=s-1;i>=t;i--)
#define ree(i,now) for(int i=head[now];i!=-1;i=edge[i].next)
#define clr(a,v) memset(a,v,sizeof a)
#define L t<<1
#define R t<<1|1
#define MID(l,r) int mid=(l+r)>>1
#define lowbit(x) (x&(-x))
#define SQR(a) ((a)*(a))

inline int input(){
    int ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return isN?-ret:ret;
}

inline void output(ll x){    
    if(x<0){    
        putchar('-');x=-x;    
    }    
    int len=0,data[20];    
    while(x){    
        data[len++]=x%10;x/=10;    
    }    
    if(!len)    data[len++]=0;    
    while(len--)   
        putchar(data[len]+48);    
    putchar('\n');  
}  

const int MAXN=5900100;
int n,m,x,p;
int shotx,a,b,c,k;
ll pre,ans;
int ls[MAXN],rs[MAXN],num[MAXN],tot,root[100005];
ll sum[MAXN];

inline void copy(int k,int p){
    ls[k]=ls[p],rs[k]=rs[p],num[k]=num[p],sum[k]=sum[p];
}

inline int build(int l,int r){
    int k=(++tot);
    sum[k]=num[k]=0;
    if(l!=r){
        MID(l,r);
        ls[k]=build(l,mid);
        rs[k]=build(mid+1,r);
    }
    return k;
}

inline int add(int p,int l,int r,int x,int y,int w){
    int k=(++tot);copy(k,p);
    if(l>=x && r<=y){
        num[k]++,sum[k]+=w;
    }
    else{
        MID(l,r);
        if(y<=mid) ls[k]=add(ls[p],l,mid,x,y,w);
        else if(x>mid) rs[k]=add(rs[p],mid+1,r,x,y,w);
        else{
            ls[k]=add(ls[p],l,mid,x,mid,w);
            rs[k]=add(rs[p],mid+1,r,mid+1,y,w);
        }
    }
    return k;
}

inline int queryN(int p,int l,int r,int x){
    int ans=num[p];
    if(l!=r){
        MID(l,r);
        if(x<=mid) ans+=queryN(ls[p],l,mid,x);
        else ans+=queryN(rs[p],mid+1,r,x);
    }
    return ans;
}

inline ll queryS(int p,int l,int r,int x){
    ll ans=sum[p];
    if(l!=r){
        MID(l,r);
        if(x<=mid) ans+=queryS(ls[p],l,mid,x);
        else ans+=queryS(rs[p],mid+1,r,x);
    }
    return ans;
}

inline int Binary_Search(int s,int t,int shotx,int k){
    int cnt;
    while(s<=t){
        MID(s,t);
        cnt=queryN(root[mid],1,x,shotx);
        if(cnt==k) return mid;
        if(cnt<=k) s=mid+1;
        else t=mid-1;
    }
    return s;
}

struct TARGET{
    int l,r,d;
    void read(){
        l=input(),r=input(),d=input();
    }
    bool operator < (const TARGET &a) const{
        return d<a.d || (d==a.d&&l<a.l) || (d==a.d&&l==a.l&&r<a.r);
    }
}target[100005];


int main(){
    //cout<<sizeof(sum)+sizeof(num)+sizeof(ls)+sizeof(rs)+sizeof(root)<<endl;
    while(~scanf("%d%d%d%d",&n,&m,&x,&p)){
        rep(i,0,n) target[i].read();
        sort(target,target+n);
        tot=0;
        root[0]=build(1,x);
        rep(i,0,n){
            root[i+1]=add(root[i],1,x,target[i].l,target[i].r,target[i].d);
        }
        pre=1;
        rep(i,0,m){
            shotx=input(),a=input(),b=input(),c=input();
            k=(pre*a+b)%c;
            if(!k) pre=0;
            else{
                int pos=Binary_Search(0,n,shotx,k);//äºåå¨shotxå¤åªæ£µçº¿æ®µæ çç®æ æ°==k
                ans=queryS(root[pos],1,x,shotx);
                if(pre>p) ans<<=1;
                pre=ans;
            }
            output(pre);
        }
    }
    return 0;
}
