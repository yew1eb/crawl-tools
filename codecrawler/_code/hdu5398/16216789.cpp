#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
//å è¾¹ç»´æ¤æå¤§çææ 
int now_ans;
const int INF=10000010;
namespace LCT{
    const int INF=1e9;
    #define NIL mem
    const int max_n=300100;
    const int mpool=300100;
    struct Node {
        int val;
        int sum;
        int pos,mpos;
        bool root,rev;
        int l,r;
        Node *lch,*rch,*fa;
        Node(){
            mpos=pos=0;
            sum=val=0;
        }
        Node(int _val,int _pos,Node *_lch,Node* _rch,Node *_fa)
        :val(_val),pos(_pos),lch(_lch),rch(_rch),fa(_fa){
            mpos=pos;
            sum=val;
            root=true;
            rev=false;
        }
    }mem[mpool],*pool[mpool];
    struct link_cut_tree{
        Node *node[3000000];
        int tp;
        Node *stk[max_n];
        int n,tot;
        int max1(int a,int b){
            if(node[a]->val<node[b]->val){
                return a;
            }
            else {
                return b;
            }
        }
        void init(){
            NIL->val=INF;
            NIL->sum=0;;
            node[0]=NIL;
            NIL->lch=NIL->rch=NIL->fa=NIL;
            NIL->pos=NIL->mpos=0;
            tot=0;
            for(int i=1;i<max_n;i++){
                pool[tot++]=mem+i;
            }
        }
        void build(int _n){
            n=_n;
            tp=n+1;
            for(int i=1;i<=n;i++){
                node[i]=new(pool[--tot])Node(0,0,NIL,NIL,NIL);
            }
        }
        void apy(int num,int val,int l,int r){
            node[num]=new(pool[--tot])Node(val,num,NIL,NIL,NIL);
            node[num]->l=l,node[num]->r=r;
        }
        void reverse(Node *t){
            if(t==NIL)return;
            t->rev^=1;
            swap(t->rch,t->lch);
        }
        void pushdown(Node *t){
            if(t==NIL)return;
            if(t->rev){
                t->rev=false;
                reverse(t->lch);
                reverse(t->rch);
            }
        }
        void update(Node *t){
            if(t==NIL)return;
            t->mpos=max1(t->pos,max1(t->lch->mpos,t->rch->mpos));
            t->sum=t->lch->sum+t->rch->sum+t->val;
        }
        void zig(Node *t){
            Node *f=t->fa,*c=t->rch;
            if(f->root)t->root=true,f->root=false;
            else (f->fa->lch==f?f->fa->lch:f->fa->rch)=t;
            t->fa=f->fa,t->rch=f,f->lch=c,c->fa=f,f->fa=t;
            update(f);
        }
        void zag(Node *t){
            Node *f=t->fa,*c=t->lch;
            if(f->root)t->root=true,f->root=false;
            else (f->fa->lch==f?f->fa->lch:f->fa->rch)=t;
            t->fa=f->fa,t->lch=f,f->rch=c,c->fa=f,f->fa=t;
            update(f);
        }
        void splay(Node *t){
            Node *p=t;
            int top=0;
            stk[top]=t;
            while(!p->root){
                stk[++top]=p->fa;
                p=p->fa;
            }
            while(top>=0){
                pushdown(stk[top--]);
            }
            while(!t->root){
                if(t->fa->root){
                    if(t->fa->lch==t)zig(t);
                    else zag(t);
                }
                else {
                    if(t->fa->fa->lch==t->fa){
                        if(t->fa->lch==t)zig(t->fa),zig(t);
                        else zag(t),zig(t);
                    }
                    else {
                        if(t->fa->lch==t)zig(t),zag(t);
                        else zag(t->fa),zag(t);
                    }
                }
            }
            update(t);

        }
        void evert(Node *t){
            t=expose(t);
            reverse(t);
        }
        Node * expose(Node *t){
            Node *p=t,*q=NIL;
            while(p!=NIL){
                splay(p);
                p->rch->root=true;
                p->rch=q;
                q->root=false;
                q=p;
                update(p);
                p=p->fa;
            }
            return q;
        }
        void cut(int a,int b){
            evert(node[b]);
            expose(node[a]);
            splay(node[a]);
            node[a]->lch->fa=NIL;
            node[a]->lch->root=true;
            node[a]->lch=NIL;
            return;
        }
        void erase(int a){
            int l=node[a]->l,r=node[a]->r;
            cut(a,l);
            cut(a,r);
            pool[tot++]=node[a];
            return;
        }
        Node * getroot(Node *t){
            t=expose(t);
            while(1){
                if(t->lch!=NIL)t=t->lch;
                else return t;
            }
        }
        void link(int a,int b){
            if(getroot(node[a])==getroot(node[b])){
                cut_it(a,b);
            }
            evert(node[b]);
            splay(node[b]);
            node[b]->fa=node[a];
            expose(node[b]);

        }
        void Link(int a,int b){
            apy(++tp,b,a,b);
            link(tp,a);
            link(b,tp);
        }
        void cut_it(int a,int b){
            expose(node[a]);
            Node *p=node[b],*q=NIL;
            int tp;
            while(p!=NIL){
                splay(p);
                if(p->fa==NIL){
                    tp=max1(p->pos,max1(p->rch->mpos,q->mpos));
                }
                p->rch->root=true;
                p->rch=q;
                p->rch->root=false;
                update(p);
                q=p;
                p=p->fa;
            }
            now_ans-=node[tp]->val;
            erase(tp);
        }
        void dfs(Node *t){
            if(t==NIL)return ;
            pushdown(t);
            dfs(t->lch);
            printf("%d %d\n",t->pos,t->val);
            dfs(t->rch);
        }
    };
}
LCT::link_cut_tree T;


const int  N=100100;
vector<int> fac[N];
void prepare(){
    for(int i=1;i<N;i++){
        for(int j=i+i;j<N;j+=i){
            fac[j].push_back(i);
        }
    }
}
int ans[N];
int main(){
    prepare();
    T.init();
    T.build(N-1);
    now_ans=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<fac[i].size();j++){
            T.Link(i,fac[i][j]);
            now_ans+=fac[i][j];
        }
        ans[i]=now_ans;
    }
//    return 0;
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",ans[n]);
    }
    return 0;
}
