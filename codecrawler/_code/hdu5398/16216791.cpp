#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
#define N 100010
#define INF 0x3f3f3f3f

struct node{
    node *ch[2];//å·¦å³å­©å­èç¹å°å
    node *fa;//ç¶èç¹çå°åï¼ä½æ¯ä¸åäºæ®éæ ä¸­ç¶èç¹çå«ä¹
    int own;//ç¹çè¯ï¼ç­äºå¤å°æ æè°ï¼æä»¥åå§åä¸º0åå¯ä¸åä¿®æ¹ï¼å¦ææ¯è¾¹çè¯ï¼å°±æ¯å¤§çé£ä¸ªæ°
    int mingcd;//ç¹çè¯åå§åä¸ºINFï¼å¦ææ¯è¾¹çè¯ï¼å°±åå§åä¸ºä¸¤ä¸ªç¹çgcd
    node *minnode;//è¦åå§åä¸ºèªå·±ï¼å®æå¨çsplayæ ä¸­ï¼ä»¥å®ä¸ºæ ¹çèç¹ä¸­ï¼mingcdæå°ç
    int rev;//è¦åå§åä¸º0ï¼è¯¥èç¹å¤å­©å­èç¹å¤äºæ­£ç¡®æåµä¸ï¼å­©å­èç¹çå·¦å³å­©å­èç¹æ¯å¦éè¦äº¤æ¢

    void init(){//åå§åï¼å¦ææ¯ç¹çè¯å°±ä¸éè¦åè¿è¡ä»»ä½ä¿®æ¹äºï¼ä½æ¯å¦ææ¯è¾¹çè¯ï¼è¦çæåµä¿®æ¹mingcdåown
        ch[0]=NULL;
        ch[1]=NULL;
        fa=NULL;
        mingcd=INF;
        minnode=this;
        rev=0;
        own=0;

        return;
    }

    bool isroot(){//å¤æ­thisè¿ä¸ªèç¹æ¯ä¸æ¯å®æå¨splayæ çæ ¹èç¹,å¹¶ä¸æ¯å¤æ­å®æ¯ä¸æ¯æ´æ£µæ çæ ¹èç¹
        return fa==NULL||((fa->ch[0]!=this)&&(fa->ch[1]!=this));
    }

    int dir(){//ä½¿ç¨è¿ä¸ªå½æ°åéç¡®å®è¿ä¸ªç¹ä¸æ¯å®æå¨çsplayæ çæ ¹èç¹ï¼å¹¶ä¸æ å¿æ²¡æç§¯ç´¯
        return fa->ch[1]==this?1:0;
    }

    void setn(int d,node *child){//æchildè®¾ä¸ºthisçdå­©å­ï¼d=1æ¶ï¼å³å­©å­ï¼d=0æ¶ï¼å·¦å­©å­
        ch[d]=child;
        if(child){
           child->fa=this;
        }

        return;
    }

    void push_up(){//åä¸æ»ç»ï¼è¿æ¶å³ä½¿æäºæ å¿æ²¡æåä¸ä¼ ï¼ä¹ä¸å½±å
        minnode=this;

        if(ch[0]&&(minnode->mingcd>ch[0]->minnode->mingcd)){
            minnode=ch[0]->minnode;
        }
        if(ch[1]&&(minnode->mingcd>ch[1]->minnode->mingcd)){
            minnode=ch[1]->minnode;
        }

        return;
    }

    void rot(){//æè½¬ï¼åææ¯è¿ä¸ªç¹ä¸æ¯å®æå¨splayæ çæ ¹èç¹ï¼å¹¶ä¸æ å¿æ²¡æç§¯ç´¯
        int d=dir();
        node *tempfafa=fa->fa;

        if(!(fa->isroot())){
            tempfafa->ch[fa->dir()]=this;
        }
        fa->setn(d,ch[!d]);
        setn(!d,fa);
        fa=tempfafa;

        ch[!d]->push_up();

        return;
    }

    void fswitch(){//äº¤æ¢å·¦å³å­©å­ï¼å¹¶ä¸æ å¿å·¦å³å­©å­çå­©å­è¦äº¤æ¢ã
        swap(ch[0],ch[1]);
        rev^=1;
    }

    void push_down(){//æ è®°ä¸ä¼ 
        if(rev){
            if(ch[0]){
                ch[0]->fswitch();
            }
            if(ch[1]){
                ch[1]->fswitch();
            }
        }

        rev=0;

        return;
    }

    void go(){
        if(!isroot()){
            fa->go();
        }
        push_down();

        return;
    }

    void splay(){
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

    void access(){
        for(node *p=this,*q=NULL;p!=NULL;q=p,p=p->fa){
            p->splay();
            p->setn(1,q);
            p->push_up();
        }
        splay();

        return;
    }

    void cut(){//æ è®ºæ­¤æ¶æ´æ£µæ çæ ¹èç¹æ¯è°ï¼accessåæ­¤æ¶å®çç¶èç¹cutï¼æä»¥ä¸ä¸å®cutåªæ¡è¾¹
        access();
        ch[0]->fa=NULL;
        ch[0]=NULL;
        push_up();
    }

    void make_root(){
        access();
        fswitch();
    }

    void cut(node *another){//æ­¤æ¶æç¡®è¦æ±cut thisåanotherè¿æ¡è¾¹
        make_root();
        another->cut();
    }

    void link(node *another){//printf("wo shi da hao ren");
        /*another->make_root();
        another->fa=this;
        another->access();*///å¯æå¯æ 
        make_root();
        fa=another;
    }

    node *query(node *another){
        make_root();
        another->access();
        return another->minnode;

        /*another->make_root();
        access();

        return minnode;*/
    }
};

long long int ans[N];
vector<int> ver[N];
node *tree[N],pool[2*N],*tail;

node *newnode(){
    tail->init();
    tail++;

    return tail-1;
}

void init(int n){
    tail=pool;

    for(int i=1;i<=n;i++){
        tree[i]=newnode();
        tree[i]->own=i;
    }

    for(int i=n;i>=1;i--){
        for(int j=i+i;j<=n;j=j+i){
            ver[j].push_back(i);
        }
    }

    long long int tempans=0;
    for(int i=2;i<=n;i++){
        node *p=newnode();
        int temp=ver[i][0];
        p->own=i;
        p->mingcd=temp;
        p->link(tree[i]);
        p->link(tree[temp]);
        tempans=tempans+temp;

        /*if(i==4){
            node *temptree=tree[4]->query(tree[2]);
            printf("%d %d %d\n",temptree->own,temptree->mingcd,temptree->mingcd);
        }*/


        for(int j=1;j<ver[i].size();j++){
            int temp=ver[i][j];
            node *temptree=tree[temp]->query(tree[i]);
            /*if(temp==1000){
                printf("%d %d %d %d %d %d\n",i,j,temp,temptree->own,temptree->mingcd,temptree->mingcd);
            }*///éè¯¯å¯¼è´tree[x]->query(tree[y])æ»æ¯éä¸­tree[y]ä»£è¡¨ç¹çè¿ä¸ªèç¹

            if(temptree->mingcd<temp){
                /*if(i==24){
                    printf("%d %d\n",i,temptree->mingcd);
                }*/
                tempans=tempans-temptree->mingcd;
                tempans=tempans+temp;
                int t1=temptree->own;
                int t2=temptree->mingcd;
                temptree->cut(tree[t1]);
                temptree->cut(tree[t2]);
                temptree->init();
                temptree->mingcd=temp;
                temptree->own=i;
                temptree->link(tree[i]);
                temptree->link(tree[temp]);
            }
        }
        ans[i]=tempans;
    }

    return;
}

int main(){
    int n;

    n=100000;
    init(n);
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",ans[n]);
    }
}