/*
çº¿æ®µæ æ±ç©å½¢é¢ç§¯çå¹¶ï¼ç¦»æ£åä¸åï¼
æXåæ æåºç¦»æ£ï¼æä¸¾æ¯ä¸ä¸ªåºé´ï¼ç¶åæ«æçº¿æ®µæ ï¼æ±çè¦ççYçé¿åº¦
ç¶å ï¼X[i+1]-X[i]ï¼ *L å³æ¯ææ±é¢ç§¯
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NN 300
#define Swap(a,b) (a=a^b,b=b^a,a=a^b)
struct node{
    int r,l,val;
}seg_tree[NN];
struct Link{
    int low_x,low_y,high_x,high_y;
}link[NN];
int X[NN];
int len_l,len_seg,len_x,val,get_ans;
int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
void Init(int root,int l,int r)
{
    int mid = (l+r)>>1;
    seg_tree[root].l = l;
    seg_tree[root].r = r;
    seg_tree[root].val = 0;
    len_seg = len_seg < root ? root : len_seg;
    if(r-l == 1)return ;
    Init(root*2,l,mid);
    Init(root*2+1,mid,r);
}
void insert(int root ,int l,int r){
    int mid = (seg_tree[root].l+seg_tree[root].r)>>1;
    if(root > len_seg ) return ;
    if(l <= seg_tree[root].l && r >= seg_tree[root].r)
        seg_tree[root].val = val;
    else if(r<=mid)insert(root*2,l,r);
    else if(l>=mid)insert(root*2+1,l,r);
    else {
        insert(root*2,l,mid);
        insert(root*2+1,mid,r);
    }
    return ;
}
void get_seg(int root)
{
    if(root > len_seg ) return ;
    if(seg_tree[root].val == val){    //ç¨æ¥åºåä¸ååºé´çYçé¿åº¦
        get_ans+=(seg_tree[root].r-seg_tree[root].l);
        return ;
    }
    get_seg(root*2);
    get_seg(root*2+1);
}
int main()
{
    int i,j,ans,x1,x2,y1,y2;    
    Init(1,0,100);
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)){
        ans=len_l=len_x=0;
        if(x1>x2)Swap(x1,x2);
        if(y1>y2)Swap(y1,y2);
        X[len_x++] = x1;
        X[len_x++] = x2;
        link[len_l].low_x = x1;
        link[len_l].low_y = y1;
        link[len_l].high_x = x2;
        link[len_l++].high_y=y2;
        while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)){
            if(x1 == -1 || x1 == -2)break;
            if(x1>x2)Swap(x1,x2);
            if(y1>y2)Swap(y1,y2);
            X[len_x++] = x1;
            X[len_x++] = x2;
            link[len_l].low_x = x1;
            link[len_l].low_y = y1;
            link[len_l].high_x = x2;
            link[len_l++].high_y=y2;
        }
        qsort(X,len_x,sizeof(int),cmp);
        for(i=0;i<len_x-1;i++){
            if(X[i] == X[i+1])continue;
            val++;//ä¿è¯äºä¸ååºé´ çº¿æ®µæ ä¸­valçå¼çä¸åï¼è¾¾å°ä¸æ¬¡å»ºæ ï¼å¤æ¬¡ä½¿ç¨çææï¼
            for(j=0;j<len_l;j++){
                if(link[j].low_x <= X[i] && link[j].high_x >= X[i+1])
                    insert(1,link[j].low_y,link[j].high_y);
            }
            get_ans=0;
            get_seg(1);
            ans += (X[i+1]-X[i])*get_ans;
        }
        printf("%d\n",ans);
        if(x1 == -2)break;
    }
    return 0;
}
