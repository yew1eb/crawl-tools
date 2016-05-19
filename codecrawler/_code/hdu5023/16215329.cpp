#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define LL int

const int maxn = 1100017;
LL add[maxn<<2];
LL sum[maxn<<2];
void PushUp(int rt)
{
    //æå½åç»ç¹çä¿¡æ¯æ´æ°å°ç¶ç»ç¹
    sum[rt] = sum[rt<<1] | sum[rt<<1|1];//æ»å±çé¢è²
}
void PushDown(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = add[rt] ;
        sum[rt<<1|1] = add[rt] ;
        add[rt] = 0;//å°æ è®°åå¿å­èç¹ç§»å¨åï¼ç¶èç¹çå»¶è¿æ è®°å»æ
        //ä¼ éåï¼å½åèç¹æ è®°åæ¸ç©º
    }
}
void build(int l,int r,int rt)
{
    add[rt] = 0;//åå§åä¸ºææç»ç¹æªè¢«æ è®°
    if (l == r)
    {
        sum[rt]=2;//åå§é¢è²ä¸º2
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        add[rt] =1<<(c-1);//ä½è¿ç®å·¦ç§»è¡¨ç¤ºææç§é¢è²
        sum[rt] =1<<(c-1);
        return ;
    }
    PushDown(rt , r - l + 1);//----å»¶è¿æ å¿ååä¸ä¼ é
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(L , R , c , lson);//æ´æ°å·¦å¿å­
    if (mid < R)
        update(L , R , c , rson);//æ´æ°å³å¿å­
    PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    //è¦årtå­èç¹çå¼æ¶ï¼ä¹è¦åærtçå»¶è¿æ è®°åä¸ç§»å¨
    PushDown(rt , r - l + 1);
    int mid = (l + r) >> 1;
    LL ret = 0;
    if (L <= mid)
        ret |= query(L , R , lson);
    if (mid < R)
        ret |= query(L , R , rson);
    return ret;
}
int main()
{
    int N , Q;
    int a , b , c;
    while(scanf("%d%d",&N,&Q))
    {
        if(N==0 && Q==0)
            break;
        build(1 , N , 1);//å»ºæ 
        while(Q--)//Qä¸ºè¯¢é®æ¬¡æ°
        {
            char op[2];
            scanf("%s",op);
            if(op[0] == 'Q')//Qä¸ºè¯¢é®æ¬¡æ°
            {
                scanf("%d%d",&a,&b);
                LL tt=query(a , b , 1 , N , 1);
                LL flag = 0;
                for(int i=1; i<=30; i++)
                {
                    if(tt>>(i-1)&1 && flag==0)
                    {
                        printf("%d",i);
                        flag = 1;
                    }
                    else if(tt>>(i-1)&1)
                        printf(" %d",i);
                }
                printf("\n");
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                update(a , b , c , 1 , N , 1);
            }
        }
    }
    return 0;
}
