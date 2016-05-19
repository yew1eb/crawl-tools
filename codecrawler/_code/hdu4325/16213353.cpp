/*
è½¬èª å»å´½å¤§çåå®¢çä¸æ®µè¯
ç¦»æ£åç®åçæ¥è¯´å°±æ¯åªåæä»¬éè¦çå¼æ¥ç¨,æ¯å¦è¯´åºé´[1000,2000],[1990,2012] æä»¬ç¨ä¸å°[-â,999][1001,1989][1991,1999][2001,2011][2013,+â]è¿äºå¼,æä»¥æåªéè¦1000,1990,2000,2012å°±å¤äº,å°å¶åå«æ å°å°0,1,2,3,å¨äºå¤æåº¦å°±å¤§å¤§çéä¸æ¥äº
æä»¥ç¦»æ£åè¦ä¿å­ææéè¦ç¨å°çå¼,æåºå,åå«æ å°å°1~n,è¿æ ·å¤æåº¦å°±ä¼å°å¾å¤å¾å¤
èè¿é¢çé¾ç¹å¨äºæ¯ä¸ªæ°å­å¶å®è¡¨ç¤ºçæ¯ä¸ä¸ªåä½é¿åº¦(å¹¶éä¸ä¸ªç¹),è¿æ ·æ®éçç¦»æ£åä¼é æè®¸å¤éè¯¯(åæ¬æä»¥åçä»£ç ,pojè¿é¢æ°æ®å¥å¼±)
ç»åºä¸é¢ä¸¤ä¸ªç®åçä¾å­åºè¯¥è½ä½ç°æ®éç¦»æ£åçç¼ºé·:
ä¾å­ä¸:1-10 1-4 5-10
ä¾å­äº:1-10 1-4 6-10
æ®éç¦»æ£ååé½åæäº[1,4][1,2][3,4]
çº¿æ®µ2è¦çäº[1,2],çº¿æ®µ3è¦çäº[3,4],é£ä¹çº¿æ®µ1æ¯å¦è¢«å®å¨è¦çæäºå¢?
ä¾å­ä¸æ¯å®å¨è¢«è¦çæäº,èä¾å­äºæ²¡æè¢«è¦ç
ä¸ºäºè§£å³è¿ç§ç¼ºé·,æä»¬å¯ä»¥å¨æåºåçæ°ç»ä¸å äºå¤ç,æ¯å¦è¯´[1,2,6,10]
å¦æç¸é»æ°å­é´è·å¤§äº1çè¯,å¨å¶ä¸­å ä¸ä»»æä¸ä¸ªæ°å­,æ¯å¦å æ[1,2,3,6,7,10],ç¶åååçº¿æ®µæ å°±å¥½äº.
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<memory.h>
using namespace std;
const int maxn=100002;
int sum[maxn<<2],st[maxn],ed[maxn],x[maxn<<2],col[maxn<<2],n,m,pos[maxn];
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
void pushUP(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushDOWN(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]+=col[rt];
        col[rt<<1|1]+=col[rt];
        sum[rt<<1]+=(m-(m>>1))*col[rt];
        sum[rt<<1|1]+=(m>>1)*col[rt];
        col[rt]=0;
    }
}
void build(int rt,int l,int r)
{
    col[rt]=0;sum[rt]=0;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushUP(rt);
}
void updata(int rt,int l,int r,int L,int R,int c)
{
    if(L<=l&&r<=R)
    {
        col[rt]+=c;
        sum[rt]+=(r-l+1)*c;
        return;
    }
    pushDOWN(rt,r-l+1);
    int mid=(l+r)>>1;
    if(mid>=L)updata(lson,L,R,c);
    if(mid<R) updata(rson,L,R,c);
    pushUP(rt);
}
int query(int rt,int l,int r,int pos)
{
    if(l==r)
    {
        return sum[rt];
    }
    pushDOWN(rt,r-l+1);
    int mid=(l+r)>>1;
    if(mid>=pos) return query(lson,pos);
    else return query(rson,pos);
}
int bin(int data,int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(x[mid]==data) return mid;
        if(x[mid]<data)l=mid+1;
        else r=mid;
    }
}
int main()
{
    int cas=1,i,j,cnt,t,idx;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&st[i],&ed[i]);
            x[++cnt]=st[i];
            x[++cnt]=ed[i];
        }
         for(i=0;i<m;i++)
        {
            scanf("%d",&pos[i]);
            x[++cnt]=pos[i];
        }
        sort(x+1,x+cnt+1);
        int tmp=unique(x+1,x+cnt+1)-(x+1);//å»éå½æ°
        for(i=tmp;i>=2;i--)//å©ç¨å¤§ççä¸æ®µè¯
        {
            if(x[i]!=x[i-1]+1)x[++tmp]=x[i-1]+1;
        }
        sort(x+1,x+tmp+1);
        build(1,1,tmp);
        for(i=0;i<n;i++)
        {
            int l=bin(st[i],1,tmp);
            int r=bin(ed[i],1,tmp);
            updata(1,1,tmp,l,r,1);
        }
        printf("Case #%d:\n",cas++);
        for(i=0;i<m;i++)
        {
            idx=bin(pos[i],1,tmp);
            printf("%d\n",query(1,1,tmp,idx));
        }
    }
    return 0;
}
