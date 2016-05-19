/*
ID:cxlove
PROB:hdu 3954
DATA:2012.5.8
HINT:çº¿æ®µæ 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define LL long long
using namespace std;
int sum[15],n,k,q;
struct Line{
    int left,right,mid;
    int exp,level;   //åºé´æå¤§çç»éªï¼ç­çº§ 
    int min_dist,lazy;   //åºé´åçº§æéçæå°ç»éªåºæ°ï¼ææ°æ è®° 
}L[50005];
//å»ºæ 
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].min_dist=sum[1];    //åå§ç­çº§ä¸º1ï¼æä»¥ç»éªåºæ°ä¾¿æ¯sum[1]/1 
    L[step].exp=0;         //åå§ç»éªä¸º0 
    L[step].level=1;         //åå§ç­çº§ä¸º1 
    L[step].lazy=0;
    if(l==r)
        return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
//åä¸æ´æ°ï¼lazyæ´æ°å°å­èç¹
void PushDown(int step){
    L[2*step].exp+=L[step].lazy*L[2*step].level;
    L[2*step].min_dist-=L[step].lazy;
    L[2*step].lazy+=L[step].lazy;

    L[2*step+1].exp+=L[step].lazy*L[2*step+1].level;
    L[2*step+1].min_dist-=L[step].lazy;
    L[2*step+1].lazy+=L[step].lazy;

    L[step].lazy=0;
}
//åä¸æ´æ°ï¼æ´æ°äºå­èç¹åï¼æ´æ°ç¶èç¹
void PushUp(int step){
    L[step].exp=max(L[2*step].exp,L[2*step+1].exp);
    L[step].level=max(L[2*step].level,L[2*step+1].level);
    L[step].min_dist=min(L[2*step].min_dist,L[2*step+1].min_dist);
}
//æ´æ°æä½
void update(int step,int l,int r,int e){
    //å¶å­èç¹
    if(L[step].left==L[step].right){
        L[step].exp+=L[step].level*e;   
        while(L[step].exp>=sum[L[step].level])
            L[step].level++;
        //è®¡ç®è¿éè¦å¤å°ç»éªåºæ°åçº§
        L[step].min_dist=(sum[L[step].level]-L[step].exp)/L[step].level+((sum[L[step].level]-L[step].exp)%L[step].level!=0);
        return ;
    }
    if(L[step].left==l&&L[step].right==r){
        //åºé´åæè±éè¦åçº§äº
        if(e>=L[step].min_dist){
            //lazyæ´æ°å­èç¹ 
            PushDown(step);
            //æ´æ°å­åºé´ 
            update(2*step,l,(l+r)/2,e);
            update(2*step+1,(l+r)/2+1,r,e);
            //æ´æ°ç¶èç¹ 
            PushUp(step);
        }
        //å½åæ²¡æè±éåçº§ 
        else{
            L[step].exp+=L[step].level*e;
            L[step].min_dist-=e;
            L[step].lazy+=e;
        }
        return ;
    }
    //åä¸æ´æ° 
    if(L[step].lazy)
        PushDown(step);
    if(r<=L[step].mid)
        update(2*step,l,r,e);
    else if(l>L[step].mid)
        update(2*step+1,l,r,e);
    else{
        update(2*step,l,L[step].mid,e);
        update(2*step+1,L[step].mid+1,r,e);
    }
    PushUp(step);
}
int query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].exp;
    if(L[step].lazy)
        PushDown(step);
    if(r<=L[step].mid)
        return query(2*step,l,r);
    else if(l>L[step].mid)
        return query(2*step+1,l,r);
    else
        return max(query(2*step,l,L[step].mid),query(2*step+1,L[step].mid+1,r));
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<k;i++)
            scanf("%d",&sum[i]);
        sum[k]=1<<30;   //è¿éä¸å¯å° 
        printf("Case %d:\n",++cas);
        bulid(1,1,n);
        while(q--){
            char str[10];
            int x,y,e;
            scanf("%s",str);
            if(str[0]=='W'){
                scanf("%d%d%d",&x,&y,&e);
                update(1,x,y,e);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%d\n",query(1,x,y));
            }
        }
        printf("\n");
    }
    return 0;
}
