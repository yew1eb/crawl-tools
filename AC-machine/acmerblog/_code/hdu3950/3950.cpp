//author: CHC
//First Edit Time:	2015-03-28 22:11
//Last Edit Time:	2015-03-31 09:40
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=51000 + 1000;
//const int INF = numeric_limits<int>::max();
const int INF = 0x3f3f3f3f;
const LL LL_INF= numeric_limits<LL>::max();
#define lson L,mid,rt<<1
#define rson mid+1,R,rt<<1|1
struct Tree {
    int st,len;
}tr[MAXN<<2],te[MAXN<<2];
set <int> s[MAXN];
void pushup(int rt){
    if(tr[rt<<1].st>tr[rt<<1|1].st) tr[rt]=tr[rt<<1|1];
    else tr[rt]=tr[rt<<1];
}
void build(int L,int R,int rt){
    if(L==R){
        s[L].clear();
        tr[rt].st=INF;
        tr[rt].len=L;
        return ;
    }
    int mid=(L+R)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int rt,int st,int len,int flag){
    if(L==R){
        if(flag){
            s[L].insert(st);
            tr[rt].st=*s[L].begin();
        }
        else {
            s[L].erase(st);
            if(s[L].begin()==s[L].end()){
                tr[rt].st=INF;
            }
            else {
                tr[rt].st=*s[L].begin();
            }
        }
        tr[rt].len=L;
        return ;
    }
    int mid=(L+R)>>1;
    if(len<=mid)update(lson,st,len,flag);
    else update(rson,st,len,flag);
    pushup(rt);
}
Tree query(int L,int R,int rt,int l,int r){
    if(l<=L&&R<=r){
        return tr[rt];
    }
    int mid=(L+R)>>1;
    Tree t1,t2;
    t1.st=INF;t2.st=INF;
    if(l<=mid)t1=query(lson,l,r);
    if(r>mid)t2=query(rson,l,r);
    if(t1.st<t2.st)return t1;
    return t2;
}
void pushup1(int rt){
    te[rt].st=te[rt<<1].st+te[rt<<1|1].st;
}
void build1(int L,int R,int rt){
    if(L==R){
        te[rt].st=0;
        te[rt].len=0;
        return ;
    }
    int mid=(L+R)>>1;
    build1(lson);
    build1(rson);
    pushup1(rt);
}
void update1(int L,int R,int rt,int st,int len,int flag){
    if(L==R){
        if(flag){
            te[rt].st=1;
            te[rt].len=len;
        }
        else {
            te[rt].st=0;
            te[rt].len=0;
        }
        return ;
    }
    int mid=(L+R)>>1;
    if(st<=mid)update1(lson,st,len,flag);
    else update1(rson,st,len,flag);
    pushup1(rt);
}
void query1(int L,int R,int rt,int rank,int &st,int &len){
    if(L==R){
        st=L;
        len=te[rt].len;
        return ;
    }
    int mid=(L+R)>>1;
    if(rank<=te[rt<<1].st)query1(lson,rank,st,len);
    else query1(rson,rank-te[rt<<1].st,st,len);
}
/*
void print1(int a,int b){
    printf("u1:%d %d\n",a,b);
}
*/
int main()
{
    int t,cas=0,n,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        printf("Case #%d:\n",++cas);
        //for(int i=0;i<=n;i++)s[i].clear();
        //for(int i=0;i<MAXN;i++)tr[i].st=INF;
        //memset(te,0,sizeof(te));
        build(1,n,1);
        update(1,n,1,1,n,1);
        build1(0,n+1,1);
        update1(0,n+1,1,0,1,1);
        update1(0,n+1,1,n+1,1,1);
        int st=n,et=n;
        char ch;
        int x,y,z;
        int where,len,sst,start;
        for(int i=0;i<q;i++){
            //printf("i:%d\n",i);
            scanf(" %c",&ch);
            if(ch=='A'){
                scanf("%d%d%d",&x,&y,&z);
                if(st>=x){
                    update(1,n,1,1,st,0);
                    if(st==n){
                        //printf("here\n");
                        if(n-x>0)
                        update(1,n,1,x+1,n-x,1);
                        //printf("%d %d\n",x+1,n-x);
                        update1(0,n+1,1,1,x,1);
                        //print1(1,x);
                        //printf("%d %d\n",1,x);
                        st=0;et=n-x;
                        sst=1;
                    }
                    else {
                        //printf("here\n");
                        if(st>=x+z){
                            where=st-z+1;
                            len=z;
                            update(1,n,1,where,len,1);
                            update1(0,n+1,1,where-x,x,1);
                            //print1(where-x,x);
                            sst=where-x;
                            st=st-x-z;
                            if(st){
                                update(1,n,1,1,st,1);
                            }
                        }
                        else {
                            len=st-x;
                            if(len){
                                //update(1,n,1,len+1,len,1);
                                update(1,n,1,x+1,len,1);
                            }
                            update1(0,n+1,1,1,x,1);
                            //print1(1,x);
                            sst=1;
                            st=0;
                        }
                    }
                }
                else {
                        //printf("here\n");
                    Tree tx=query(1,n,1,x,x+y+z);
                    //printf("%d %d\n",x,x+y+z);
                    //printf("%d %d\n",tx.st,tx.len);
                    if(tx.st==INF){
                        //puts("here11");
                        //printf("st:%d et:%d\n",st,et);
                        if(et>=x){
                            update(1,n,1,n-et+1,et,0);
                            where=n-(et-x)+1;
                            len=et-x;
                            et-=x;
                            if(len)
                                update(1,n,1,where,len,1);
                            //update1(0,n+1,1,n-et+1,x,1);
                            //sst=n-et+1;
                            update1(0,n+1,1,where-x,x,1);
                            //print1(where-x,x);
                            sst=where-x;
                        }
                        else {
                            sst=-1;
                        }
                    }
                    else {
                        //printf("\nhere");
                        update(1,n,1,tx.st,tx.len,0);
                        //printf("%d %d\n",tx.st,tx.len);
                        if(tx.st+tx.len-1==n){
                            sst=tx.st;
                            //et=len=tx.len-x;
                            et=len=et-x;
                            if(len)
                                update(1,n,1,tx.st+x,len,1);
                            update1(0,n+1,1,tx.st,x,1);
                            //print1(tx.st,x);
                            //et=len;
                        }
                        else if(tx.len>=x+z){
                            len=tx.len-(x+z);
                            if(len)
                                update(1,n,1,tx.st,len,1);
                            //len=z;
                            update(1,n,1,tx.st+len+x,z,1);
                            update1(0,n+1,1,tx.st+len,x,1);
                            //print1(tx.st+len,x);
                            sst=tx.st+len;
                        }
                        else {
                            len=tx.len-x;
                            if(len)
                                update(1,n,1,tx.st+x,len,1);
                            update1(0,n+1,1,tx.st,x,1);
                            //print1(tx.st,x);
                            sst=tx.st;
                        }
                    }
                }
                printf("%d\n",sst);
            }
            else {
                scanf("%d",&x);
                ++x;
                int where1,len1,where2,len2,where3,len3;
                if(x<te[1].st){
                    query1(0,n+1,1,x,where1,len1);
                    update1(0,n+1,1,where1,len1,0);
                    query1(0,n+1,1,x-1,where2,len2);
                    query1(0,n+1,1,x,where3,len3);
                    //printf("w3:%d w2:%d w1:%d\n",where3,where2,where1);
                    //printf("l3:%d l2:%d l1:%d\n",len3,len2,len1);
                    len=where1-(where2+len2);
                    if(len>0)
                        update(1,n,1,where2+len2,len,0);
                    //while(len<0);
                    //printf("uuu:%d %d\n",where2+len2,len);
                    len=where3-(where1+len1);
                    if(len>0)
                        update(1,n,1,where1+len1,len,0);
                    //while(len<0);
                    //printf("uuu:%d %d\n",where1+len1,len);
                    if(where3-(where2+len2)>0)
                    update(1,n,1,where2+len2,where3-(where2+len2),1);
                    //while((where3-(where2+len2))<0);
                    //printf("uuu:%d %d\n",where2+len2,where3-(where2+len2));
                    //printf("here1\n");
                    //printf("%d %d\n",where1,len1);
                    if(where2==0){
                        st=where3-(where2+len2);
                        //while(st<0);
                    }
                    if(where3==n+1){
                        et=where3-(where2+len2);
                        //while(et<0);
                        //et=n-(where2+len2)+1;
                        //puts("here22");
                        //printf("et:%d\n",et);
                        //et+=len1+where1-where2-1;
                        //update(1,n,1,n-et+1,et,1);
                    }
                }
            }
            //printf("st:%d et:%d\n",st,et);
        }
        //puts("here");
    }
    return 0;
}
