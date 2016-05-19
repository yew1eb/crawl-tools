#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 100010;
const int INF = - 0x3f3f3f3f;

inline void merge(int &m1,int &m2,int &c1,int &c2,int t1,int t2,int k1,int k2){
    if(t1>m1) m2=m1,c2=c1,m1=t1,c1=k1;
    else if(t1==m1) c1+=k1;
    else if(t1>m2) m2=t1,c2=k1;
    else if(t1==m2) c2+=k1;
    if(t2>m2) m2=t2,c2=k2;
    else if(t2==m2) c2+=k2;
}
struct Node{
    int w,max1,max2,cnt1,cnt2,tag1,tag2,rev,size;
    Node *lc,*rc,*fa,*path_fa;
    void update(){
        size=1;max1=w;cnt1=1;max2=INF;cnt2=0;
        if(lc) size+=lc->size,merge(max1,max2,cnt1,cnt2,lc->max1,lc->max2,lc->cnt1,lc->cnt2);
        if(rc) size+=rc->size,merge(max1,max2,cnt1,cnt2,rc->max1,rc->max2,rc->cnt1,rc->cnt2);
    }
    void flip(){rev^=1;swap(lc,rc);}
    void same(int t){tag1=0;tag2=1;w=max1=t;max2=INF;cnt1=size;cnt2=0;}
    void inc(int t){tag1+=t;w+=t;max1+=t;if(max2!=INF) max2+=t;}
    void sink(){
        if(tag2){
            if(lc) lc->same(w);
            if(rc) rc->same(w);
            tag2=tag1=0;
        }
        else{
            if(lc) lc->inc(tag1);
            if(rc) rc->inc(tag1);
            tag1=0;
        }
        if(rev){
            if(lc) lc->flip();
            if(rc) rc->flip();
            rev=0;
        }
    }
    void zig(){
        Node *p=lc;
        p->rc=((lc=p->rc) ? lc->fa=this : this);
        if(p->fa=fa) fa->lc==this ? fa->lc=p : fa->rc=p;
        fa=p;swap(path_fa,p->path_fa);
        update();p->update();
    }
    void zag(){
        Node *p=rc;
        p->lc=((rc=p->lc) ? rc->fa=this : this);
        if(p->fa=fa) fa->lc==this ? fa->lc=p : fa->rc=p;
        fa=p;swap(path_fa,p->path_fa);
        update();p->update();
    }
}pool[MaxN],*pos[MaxN],*tail;

int n,m;

inline void init(int n){
    for(int i=1;i<=n;i++){
        tail->tag1=tail->tag2=tail->rev=0,
        tail->lc=tail->rc=tail->fa=tail->path_fa=0,pos[i]=tail++;
    }
}

void splay(Node *p){
    p->sink();
    while(p->fa){
        if(p->fa->fa){
            p->fa->fa->sink();
            p->fa->sink();p->sink();
            if(p->fa==p->fa->fa->lc){
                if(p==p->fa->lc) p->fa->fa->zig(),p->fa->zig();
                else p->fa->zag(),p->fa->zig();
            }
            else{
                if(p==p->fa->lc) p->fa->zig(),p->fa->zag();
                else p->fa->fa->zag(),p->fa->zag();
            }
        }
        else{
            p->fa->sink();p->sink();
            if(p==p->fa->lc) p->fa->zig();
            else p->fa->zag();
        }
    }
    p->update();
}

void expose(int u){
    Node *p=pos[u],*q;
    splay(p);
    if(q=p->rc) q->fa=0,q->path_fa=p;
    p->rc=0;p->update();
    while(q=p->path_fa){
        splay(q);
        if(q->rc) q->rc->fa=0,q->rc->path_fa=q;
        (q->rc=p)->fa=q;p->path_fa=0;q->update();
        splay(p);
    }
}

void make_root(int u){
    Node *p=pos[u];
    expose(u);
    if(p->lc) p->lc->fa=0,p->lc->path_fa=p,p->lc->flip();
    p->lc=0;p->update();
}

void cut(int u,int v){
    Node *p=pos[v];
    make_root(u);expose(v);
    if(p->lc) p->lc->fa=0;
    p->lc=0;p->update();
}

void join(int u,int v){
    make_root(v);expose(u);
    pos[v]->path_fa=pos[u];
    expose(v);    
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int P=1;P<=T;P++){
        scanf("%d%d",&n,&m);
        tail=pool;init(n);
        for(int i=1,w;i<=n;i++) scanf("%d",&w),pos[i]->w=w,pos[i]->update();
        for(int i=1;i<n;i++){
            int u,v;scanf("%d%d",&u,&v);
            join(u,v);
        }
        printf("Case #%d:\n",P);
        for(int i=1;i<=m;i++){
            int c,x,y,a,b;
            scanf("%d",&c);
            switch(c){
                case 1:{
                    scanf("%d%d%d%d",&x,&y,&a,&b);
                    cut(x,y);join(a,b);break;
                }
                case 2:{
                    scanf("%d%d%d",&a,&b,&x);
                    make_root(a);expose(b);pos[b]->same(x);
                    break;
                }
                case 3:{
                    scanf("%d%d%d",&a,&b,&x);
                    make_root(a);expose(b);pos[b]->inc(x);
                    break;
                }
                case 4:{
                    scanf("%d%d",&a,&b);
                    make_root(a);expose(b);
                    if(pos[b]->max2==INF) puts("ALL SAME");
                    else printf("%d %d\n",pos[b]->max2,pos[b]->cnt2);
                    break;
                }
            }
        }
    }
    return 0;
}