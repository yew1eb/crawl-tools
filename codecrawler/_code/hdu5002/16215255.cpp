#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
struct Node *null;
struct Node{
    Node *fa,*ch[2];
    int val,size;  //valæ¯è¯¥ç¹çæéï¼sizeæ¯ä»¥å®ä¸ºæ ¹çå­æ çå¤§å°ã
    int same,add;
    int rev;
    int mm,mmc;
    int sm,smc;
    inline void clear(int _val){  //åå§åè¯¥ç¹çç¹æã
        fa = ch[0] = ch[1] = null;
        val = _val; size = 1;
        same = -INF;
        add = 0;
        mm = _val; mmc = 1;
        sm = -INF; smc = 0;
    }
    inline void add_val(int _val,int num){  //æå¼ä¸ºvalï¼åºç°çæ¬¡æ°ä¸ºnum
        if(_val == -INF)return;
        if(_val < sm)return;
        if(_val == sm)smc += num;
        else if(_val < mm){
            sm = _val; smc = num;
        }
        else if(_val == mm){
            mmc += num;
        }
        else{
            sm = mm; smc = mmc;
            mm = _val; mmc = num;
        }
    }
    inline void push_up(){
        size = 1 + ch[0]->size + ch[1]->size;
        mm = sm = -INF;
        mmc = smc = 0;
        add_val(val,1);
        add_val(ch[0]->mm,ch[0]->mmc);
        add_val(ch[0]->sm,ch[0]->smc);
        add_val(ch[1]->mm,ch[1]->mmc);
        add_val(ch[1]->sm,ch[1]->smc);
    }
    inline void setc(Node *p,int d){
        ch[d] = p;
        p->fa = this;
    }
    inline bool d(){
        return fa->ch[1] == this;
    }
    inline bool isroot(){
        return fa == null || fa->ch[0] != this && fa->ch[1] != this;
    }
    inline void flip(){
        if(this == null)return;
        swap(ch[0],ch[1]);
        rev ^= 1;
    }
    inline void update_add(int w){
        if(this == null)return;
        if(mm != -INF)mm += w;
        if(sm != -INF)sm += w;
        val += w;
        add += w;
    }
    inline void update_same(int w){
        if(this == null)return;
        mm = w; mmc = size;
        sm = -INF; smc = 0;
        same = w;
        val = w;
        add = 0;
    }
    inline void push_down(){
        if(same != -INF){
            ch[0]->update_same(same);
            ch[1]->update_same(same);
            same = -INF;
        }
        if(add){
            ch[0]->update_add(add);
            ch[1]->update_add(add);
            add = 0;
        }
        if(rev){
            ch[0]->flip();
            ch[1]->flip();
            rev = 0;
        }
    }
    inline void go(){
        if(!isroot())fa->go();
        push_down();
    }
    inline void rot(){
        Node *f = fa, *ff = fa->fa;
        int c = d(), cc = fa->d();
        f->setc(ch[!c],c);
        this->setc(f,!c);
        if(ff->ch[cc] == f)ff->setc(this,cc);
        else this->fa = ff;
        f->push_up();
    }
    inline Node* splay(){
        go();
        while(!isroot()){
            if(!fa->isroot())
                d()==fa->d() ? fa->rot() : rot();
            rot();
        }
        push_up();
        return this;
    }
    inline Node* access(){
        for(Node *p = this,*q = null; p != null; q = p, p = p->fa){
            p->splay()->setc(q,1);
            p->push_up();
        }
        return splay();
    }
    inline Node* find_root(){
        Node *x;
        for(x = access(); x->push_down(), x->ch[0] != null; x = x->ch[0]);
        return x;
    }
    void make_root(){
        access()->flip();
    }
    void cut(){
        access();
        ch[0]->fa = null;
        ch[0] = null;
        push_up();
    }
    void cut(Node *x){    //å é¤è¯¥èç¹åxä¹é´çè¾¹ã
        if(this == x || find_root() != x->find_root())return;
        else{
            x->make_root();
            cut();
        }
    }
    void link(Node *x){    //è¯¥èç¹é¾æ¥xèç¹ãï¼å³è¯¥èç¹åxèç¹ä¹é´å ä¸æ¡è¾¹ï¼
        if(find_root() == x->find_root())return;
        else {
            make_root(); fa = x;
        }
    }
};
void SAME(Node *x,Node *y,int w){    //ï¼2ï¼a->bçè·¯å¾ä¸çææç¹ææ¹ä¸ºxï¼åå«aï¼bï¼ï¼
    x->access();
    for(x = null; y != null; x = y, y = y->fa){
        y->splay();
        if(y->fa == null){
            y->ch[1]->update_same(w);
            x->update_same(w);
            y->val = w;
            y->push_up();
            return;
        }
        y->setc(x,1);
        y->push_up();
    }
}
void ADD(Node *x,Node *y,int w){  //ï¼3ï¼a->bçè·¯å¾ä¸çææç¹æå ä¸dï¼åå«aï¼bï¼ï¼
    x->access();
    for(x = null; y != null; x = y, y = y->fa){
        y->splay();
        if(y->fa == null){
            y->ch[1]->update_add(w);
            x->update_add(w);
            y->val += w;
            y->push_up();
            return;
        }
        y->setc(x,1);
        y->push_up();
    }
}
int MM,MMC;  //æå¤§å¼ï¼æå¤§å¼åºç°çæ¬¡æ°
int SM,SMC;  //ç¬¬äºå¤§å¼ï¼ååºç°çæ¬¡æ°
void ADD_VAL(int val,int num){    //æå¼ä¸ºvalï¼åºç°çæ¬¡æ°æ¯num
    if(val == -INF)return;
    if(val < SM)return;
    if(val == SM)SMC += num;
    else if(val < MM){
        SM = val;
        SMC = num;
    }
    else if(val == MM){
        MMC += num;
    }
    else {
        SM = MM; SMC = MMC;
        MM = val; MMC = num;
    }
}
void ask(Node *x,Node *y){    //æ¥è¯¢a->bçè·¯å¾ä¸ä¸¥æ ¼ç¬¬äºå¤§çå¼ï¼ä»¥åå®åºç°çæ¬¡æ°ï¼
    x->access();
    for(x=null; y != null; x = y, y = y->fa){
        y->splay();
        if(y->fa == null){
            MM = SM = -INF;
            MMC = SMC = 0;
            ADD_VAL(y->val,1);
            ADD_VAL(y->ch[1]->mm,y->ch[1]->mmc);
            ADD_VAL(y->ch[1]->sm,y->ch[1]->smc);
            ADD_VAL(x->sm,x->smc);
            ADD_VAL(x->mm,x->mmc);
            return;
        }
        y->setc(x,1);
        y->push_up();
    }
}
Node pool[MAXN],*tail;
Node *node[MAXN];
struct Edge{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int g[MAXN];
int fa[MAXN];
void bfs(int s){
    int l,r;
    g[l=r=1] = s;
    fa[s] = s;
    while(l <= r){
        int u = g[l++];
        for(int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[u])continue;
            fa[v] = u;
            node[v]->fa = node[u];
            g[++r] = v;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int iCase = 0;
    int n,m;
    scanf("%d",&T);
    while(T--){
        iCase++;
        printf("Case #%d:\n",iCase);
        scanf("%d%d",&n,&m);
        tail = pool;
        null = tail++;
        null->fa = null->ch[0] = null->ch[1] = null;
        null->size = null->rev = 0;
        null->same = -INF; null->add = 0;
        null->mm = null->sm = -INF;
        null->mmc = null->smc = 0;
        for(int i = 1;i <= n;i++){
            int v ;
            scanf("%d",&v);  //åå§åç¹æ
            node[i] = tail++;
            node[i]->clear(v);
        }
        init();
        int u,v;
        for(int i = 1;i < n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v); //å¶å®è¿éå¯ä»¥ç´æ¥ç¨node[u]->link(node[v]);æ¥å»ºæ ï¼ä¸è¿ä¼ç¨å¾®æ¢ä¸ç¹
            addedge(v,u);
        }
        bfs(1);//åé¢ä¸ä¸ªå¾ªç¯åè¾å¥è¾¹ï¼dfsç¨æ¥å»ºæ ãè¿æ ·ä¼æ¯æ¯æ¬¡è¾ä¸ä¸ªè¾¹å°±å»ºä¸æ¡è¾¹å¿«ä¸ç¹ï¼å¡æ¶é´å°±è¿æ ·åï¼ã
        int op;
        int x,y,a,b;
        while(m--){
            scanf("%d",&op);
            if(op == 1){
                scanf("%d%d%d%d",&x,&y,&a,&b);
                node[x]->cut(node[y]);  //å é¤x-yçè¾¹
                node[a]->link(node[b]);  //a-bå»ºè¾¹
            }
            else if(op == 2){
                scanf("%d%d%d",&a,&b,&x);
                SAME(node[a],node[b],x);  //ï¼2ï¼a->bçè·¯å¾ä¸çææç¹ææ¹ä¸ºxï¼åå«aï¼bï¼ï¼
            }
            else if(op == 3){
                scanf("%d%d%d",&a,&b,&x);
                ADD(node[a],node[b],x);  //ï¼2ï¼a->bçè·¯å¾ä¸çææç¹æå ä¸xï¼åå«aï¼bï¼ï¼
            }
            else{
                scanf("%d%d",&a,&b);
                ask(node[a],node[b]);  //æ¥è¯¢a->bçè·¯å¾ä¸ä¸¥æ ¼ç¬¬äºå¤§çå¼ï¼ä»¥åå®åºç°çæ¬¡æ°ï¼
                if(SM == -INF)
                    printf("ALL SAME\n");
                else printf("%d %d\n",SM,SMC);
            }
        }
    }
    return 0;
}
