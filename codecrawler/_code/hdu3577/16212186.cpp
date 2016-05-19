#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
int ans[N];
struct node
{
    int l,r,v,lazy;
}node[N<<2];    //  çº¿æ®µæ çç©ºé´å¤§æ¦æ¯æ°ç»ç©ºé´ç4åï¼
void build(int l,int r,int numb)    //  çº¿æ®µæ çå»ºç«ï¼
{
    node[numb].l=l;
    node[numb].r=r;
    node[numb].v=0;
    node[numb].lazy=0;              //  ç¨äºlazyææ³ï¼æé«äºæçï¼
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,numb<<1);
    build(mid+1,r,numb<<1|1);
}
void PushUp(int numb)               //  å¾ä¸å¾ç¶èç¹æ¹åæ´æ°æ°æ®ï¼ä½æ¯è¿éä¸æ¯å·¦å³å¿å­çåï¼èæ¯æå¤§å¼ï¼å ä¸ºæ¯ç«å°äººæ°ï¼
{
    node[numb].v=max(node[numb<<1].v,node[numb<<1|1].v);
}
void PushDown(int numb)             //  åä¸å¾å·¦å³å¿å­æ¹åæ´æ°æ°æ®ï¼
{
    node[numb<<1].lazy+=node[numb].lazy;
    node[numb<<1|1].lazy+=node[numb].lazy;
    node[numb<<1].v+=node[numb].lazy;
    node[numb<<1|1].v+=node[numb].lazy;
    node[numb].lazy=0;              //  æ´æ°å®äºè¦æ¸é¶ï¼
}
void Insert(int l,int r,int numb)   //  æå¥æ´æ°æ°æ®ï¼
{
    if(node[numb].l==l&&node[numb].r==r)    //  å¦æåºé´å®å¨éåï¼åä¸éè¦åå¾ä¸æ´æ°äºï¼åä¿å­èµ·æ¥ï¼å¯ä»¥èçº¦å¾å¤çæ¶é´ï¼lazyææ³ï¼
    {
        node[numb].v+=1;
        node[numb].lazy+=1;
        return;
    }
    if(node[numb].lazy) PushDown(numb);     //  å ä¸ºæ²¡ææ¾å°å®å¨éåçåºé´ï¼æä»¥è¦åæ´æ°ä¸ä¸å±åºé´ï¼
    int mid=(node[numb].r+node[numb].l)>>1;
    if(l>mid) Insert(l,r,numb<<1|1);
    else if(r<=mid) Insert(l,r,numb<<1);
    else{
        Insert(l,mid,numb<<1);
        Insert(mid+1,r,numb<<1|1);
    }
    PushUp(numb);       //  æåè¿å¾å¾ä¸è¿åï¼æ´æ°ç¶èç¹åºé´ï¼
}
int query(int l,int r,int numb)     //  æ¥è¯¢åºé´lå°rï¼
{
    if(node[numb].l==l&&node[numb].r==r){
        return node[numb].v;
    }
    if(node[numb].lazy) PushDown(numb);     //  éçå48è¡ï¼
    int mid=(node[numb].r+node[numb].l)>>1;
    if(l>mid) return query(l,r,numb<<1|1);
    else if(r<=mid) return query(l,r,numb<<1);
    else{
        return max(query(l,mid,numb<<1),query(mid+1,r,numb<<1|1));  //  éçå28è¡ï¼
    }
}
int main()
{
    int t,Case=1,len=0,k,m,a,b;
    scanf("%d",&t);
    while(t--){
        len=0;
        memset(ans,0,sizeof(ans));
        scanf("%d%d",&k,&m);
        build(1,1000000,1);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            b--;                    //  è¿éæä¸ä¸ªé®é¢ï¼å°±æ¯ä¹å®¢ä»aä¸è½¦ï¼bä¸è½¦ï¼æä»¥ä¹å®¢å¨è½¦ä¸çåºé´ä¸ºï¼a,b--ï¼;
            if(query(a,b,1)<k){     //  è¡¨ç¤ºå¯ä»¥ä¸è½¦ï¼
                ans[len++]=i+1;
                Insert(a,b,1);
            }
        }
        printf("Case %d:\n",Case++);
        for(int i=0; i<len; i++)    //  æ ¼å¼é®é¢å®³æåWAäºä¸æ¬¡ï¼
            printf("%d ",ans[i]);
        printf("\n\n");
    }
    return 0;
}


