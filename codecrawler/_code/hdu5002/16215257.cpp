#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 100010
#define INF 0x3f3f3f3f

struct node{
    node *fa;
    node *ch[2];
    /*long long */int num;
    /*long long */int allto;
    /*long long */int allreduce;
    /*long long */int maxnum;
    int maxcou;
    /*long long */int smaxnum;
    int smaxcou;
    int sons;
    int rev;

    void init(int tempnum){/*å·²éªè¯ï¼æ­£ç¡®*/
        fa=NULL;
        ch[0]=NULL;
        ch[1]=NULL;
        num=tempnum;
        allto=INF;
        allreduce=INF;
        maxnum=num;
        maxcou=1;
        smaxnum=-INF;
        smaxcou=0;
        sons=1;
        rev=0;
    }

    bool isroot(){//å·²éªè¯ï¼æ­£ç¡®
        return fa==NULL||(fa->ch[0]!=this&&fa->ch[1]!=this);
    }

    void changeallto(int tempallto){/*å·²éªè¯ï¼æ­£ç¡®*/
        num=tempallto;
        allto=tempallto;
        allreduce=INF;
        maxnum=allto;
        maxcou=sons;
        smaxnum=-INF;
        smaxcou=0;

        return;
    }

    void changeallreduce(int tempallreduce){/*å·²éªè¯ï¼æ­£ç¡®*/
        num=num+tempallreduce;
        if(allreduce==INF){
            allreduce=0;
        }
        allreduce=allreduce+tempallreduce;//è¿éætempallreduceåæäºallreduce,åäºä¸å¤©
        maxnum=maxnum+tempallreduce;
        if(smaxnum!=-INF){
            smaxnum=smaxnum+tempallreduce;//è¿éætempallreduceåæäºallreduceï¼åäºä¸å¤©
        }

        return;
    }

    void fswitch(){/*å·²éªè¯ï¼æ­£ç¡®*/
        rev^=1;
    swap(ch[0],ch[1]);

        return;
    }

    void push_down(){/*å·²éªè¯ï¼æ­£ç¡®*/
        if(rev){
            rev=0;
            if(ch[0]){
                ch[0]->fswitch();
            }
            if(ch[1]){
                ch[1]->fswitch();
            }
        }
        if(allto!=INF){
            if(ch[0]){
                ch[0]->changeallto(allto);
            }
            if(ch[1]){
                ch[1]->changeallto(allto);
            }
            allto=INF;
        }

        if(allreduce!=INF){
            if(ch[0]){
                ch[0]->changeallreduce(allreduce);
            }
            if(ch[1]){
                ch[1]->changeallreduce(allreduce);
            }
            allreduce=INF;
        }

        return;
    }

    void go(){/*å·²éªè¯ï¼æ­£ç¡®*/
        if(!isroot()){
            fa->go();
        }
        push_down();

        return;
    }

    int dir(){/*å·²éªè¯ï¼æ­£ç¡®*/
        return fa->ch[1]==this?1:0;
    }

    void changemax(node *tempch){/*å·²éªè¯ï¼æ­£ç¡®*/
        if(maxnum<tempch->maxnum){
            if(maxnum<tempch->smaxnum){
                smaxnum=tempch->smaxnum;
                smaxcou=tempch->smaxcou;
            }
            else if(maxnum>tempch->smaxnum){
                smaxnum=maxnum;
                smaxcou=maxcou;
            }
            else{
                smaxnum=maxnum;
                smaxcou=maxcou+tempch->smaxcou;
            }

            maxnum=tempch->maxnum;
            maxcou=tempch->maxcou;
            }
        else if(maxnum>tempch->maxnum){
            if(smaxnum<tempch->maxnum){
                smaxnum=tempch->maxnum;
                smaxcou=tempch->maxcou;
            }
            else if(smaxnum==tempch->maxnum){
                smaxcou=smaxcou+tempch->maxcou;
            }
        }
        else{
            maxcou=maxcou+tempch->maxcou;
            if(smaxnum<tempch->smaxnum){
                smaxnum=tempch->smaxnum;
                smaxcou=tempch->smaxcou;
            }
            else if(smaxnum==tempch->smaxnum){
                smaxcou=smaxcou+tempch->smaxcou;
            }
        }
        sons+=tempch->sons;

        return;
    }

    void push_up(){/*å·²éªè¯ï¼æ­£ç¡®*/
        sons=1;
        maxnum=num;
        maxcou=1;
        smaxnum=-INF;
        smaxcou=0;
        if(ch[0]!=NULL){
            changemax(ch[0]);
        }
        if(ch[1]!=NULL){
            changemax(ch[1]);
        }

        return;
    }

    void setedge(int d,node *tempch){/*å·²éªè¯ï¼æ­£ç¡®*/
        ch[d]=tempch;
        if(tempch){
            tempch->fa=this;
        }

        return;
    }

    void rot(){/*å·²éªè¯ï¼æ­£ç¡®*/
        int d=dir();
        node *tempfafa=fa->fa;

        if(!(fa->isroot())){
            tempfafa->ch[fa->dir()]=this;
        }
        fa->setedge(d,ch[!d]);
        setedge(!d,fa);
        fa=tempfafa;

        ch[!d]->push_up();

        return;
    }

    void splay(){/*å·²éªè¯ï¼æ­£ç¡®*/
        go();
        while(!isroot()){

            if(!(fa->isroot())){
                dir()==fa->dir()?fa->rot():rot();
            }
            rot();
        }
        push_up();

        return;
    }
    void access(){/*å·²éªè¯ï¼æ­£ç¡®*/
        for(node *p=this,*q=NULL;p!=NULL;q=p,p=p->fa){
            p->splay();
            p->setedge(1,q);/*è°éï¼ç»è¿è¿æ­¥ååï¼ä½¿å¾tree[2]çfaä¹æ¯tree[2];*/
            p->push_up();
        }
        splay();

        return;
    }

    void cut(){
        access();
        ch[0]->fa=NULL;
        ch[0]=NULL;
        push_up();

        return;
    }

    void make_root(){/*å·²éªè¯ï¼æ­£ç¡®*/
        access();
        fswitch();

        return;
    }

    void cut(node *another){/*å·²éªè¯ï¼æ­£ç¡®*/
        make_root();
        another->cut();

        return;
    }

    void link(node *another){/*å·²éªè¯ï¼æ­£ç¡®*/
        another->make_root();
        another->fa=this;

        return;
    }

    void changeto(node *another,int tempallto){/*å·²éªè¯ï¼æ­£ç¡®*/
        make_root();
        another->access();
        another->changeallto(tempallto);
    }

    void changereduce(node *another,int tempallreduce){/*å·²éªè¯ï¼æ­£ç¡®*/
        make_root();
        another->access();
        another->changeallreduce(tempallreduce);
    }

    pair<int,int> query(node *another){/*å·²éªè¯ï¼æ­£ç¡®*/
        make_root();
        another->access();
        pair<int,int> p;
        p.first=another->smaxnum;
        p.second=another->smaxcou;

        return p;
    }
};

node *tree[N],pool[N];

int main(){
    int t;
    int n,m;
    int w;
    int c,x,y,a,b;

    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        printf("Case #%d:\n",cas);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&w);
            pool[i].init(w);
            tree[i]=&(pool[i]);
        }

        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            tree[a]->link(tree[b]);
        }

        for(int i=1;i<=m;i++){
            scanf("%d",&c);

            if(c==1){
                scanf("%d%d%d%d",&x,&y,&a,&b);
                tree[x]->cut(tree[y]);
                tree[a]->link(tree[b]);
            }
            else if(c==2){
                scanf("%d%d%d",&a,&b,&x);
                tree[a]->changeto(tree[b],x);
            }
            else if(c==3){
                scanf("%d%d%d",&a,&b,&x);
                tree[a]->changereduce(tree[b],x);
            }
            else if(c==4){
                scanf("%d%d",&a,&b);
                pair<int,int> p=tree[a]->query(tree[b]);
                if(p.first==-INF){
                    printf("ALL SAME\n");
                }
                else{
                    printf("%d %d\n",p.first,p.second);
                }
            }
        }
    }

    return 0;
}