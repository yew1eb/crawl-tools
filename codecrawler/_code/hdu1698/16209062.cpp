#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define L(x) (x<<1)    
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)
#define NN 100010
struct node{
    int l,r;
    int val;        //è®°å½åºé´åçåç´ å¼ï¼å¦æåºé´åå¼ä¸åï¼val == 0
    int sum;        //è®°å½åºé´å
}seg_tree[NN<<2];
//å¾æ°´çå»ºæ ï¼æ²¡å¥è¦æ±
void build(int t,int l,int r){
    int mid = MID(l,r);
    seg_tree[t].l=l;
    seg_tree[t].r=r;
    seg_tree[t].val = 1;
    if(r-l == 1){
        seg_tree[t].sum = 1;
        return ;
    }
    build(L(t),l,mid);
    build(R(t),mid,r);
    seg_tree[t].sum = seg_tree[L(t)].sum + seg_tree[R(t)].sum;
}
void updata(int t,int l,int r,int val){
    int mid = MID(seg_tree[t].l,seg_tree[t].r);
    if(l == seg_tree[t].l  && r == seg_tree[t].r){
        seg_tree[t].val = val;
        seg_tree[t].sum = (r-l)*val;
        return ;
    }
    if(seg_tree[t].val > 0){        //æ´æ°çæ¶åéè¦æ³¨æçå°æ¹ï¼åå¼å§æ²¡ææè¿ä¸ªä¸è¥¿ï¼sumä¸ç´åºé
                                    //å ä¸ºï¼ä¸ä¸æ¬¡æ´æ°å°ä¸å®å±æ¬¡å°±åæ­¢çè¯ï¼å½åæ´æ°å°æ´æ·±ä¸å±çæ¶å
                                    //æè®¸ä¼å ä¸ºvalä¸åå¯¼è´è¿åsumåºé.
        seg_tree[L(t)].val = seg_tree[t].val;
        seg_tree[L(t)].sum = (seg_tree[L(t)].r-seg_tree[L(t)].l)*seg_tree[t].val;
        seg_tree[R(t)].val = seg_tree[t].val;
        seg_tree[R(t)].sum = (seg_tree[R(t)].r-seg_tree[R(t)].l)*seg_tree[t].val;
        seg_tree[t].val = 0;
    }
    if(mid <= l)updata(R(t),l,r,val);
    else if( mid >=r)updata(L(t),l,r,val);
    else {
        updata(L(t),l,mid,val);
        updata(R(t),mid,r,val);    
    }
    seg_tree[t].sum = seg_tree[L(t)].sum + seg_tree[R(t)].sum;
}
int main()
{
    int t,n,q,x,y,z,k=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        build(1,0,n);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&x,&y,&z);
            updata(1,x-1,y,z);
        }
        printf("Case %d: The total value of the hook is %d.\n",k++,seg_tree[1].sum);
    }
    return 0;
}