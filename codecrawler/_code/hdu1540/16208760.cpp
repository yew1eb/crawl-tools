#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

const int maxn = 50000+10;

int n,m;
int s[maxn],top;//sä¸ºæ¨¡ææ 

struct node
{
    int l,r;
    int ls,rs,ms;//ls,å·¦ç«¯æå¤§è¿ç»­åºé´ï¼rså³ç«¯æå¤§è¿ç»­åºé´ï¼msåºé´åæå¤§è¿ç»­åºé´
} a[maxn<<2];

void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].ls = a[i].rs = a[i].ms = r-l+1;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        init(l,mid,i*2);
        init(mid+1,r,2*i+1);
    }
}

void insert(int i,int t,int x)
{
    if(a[i].l == a[i].r)
    {
        if(x==1)
            a[i].ls = a[i].rs = a[i].ms = 1;//ä¿®å¤
        else
            a[i].ls = a[i].rs = a[i].ms = 0;//ç ´å
        return ;
    }
    int mid = (a[i].l+a[i].r)>>1;
    if(t<=mid)
        insert(2*i,t,x);
    else
        insert(2*i+1,t,x);
    a[i].ls = a[2*i].ls;//å·¦åºé´
    a[i].rs = a[2*i+1].rs;//å³åºé´
    a[i].ms = max(max(a[2*i].ms,a[2*i+1].ms),a[2*i].rs+a[2*i+1].ls);//ç¶äº²åºé´åçæå¤§åºé´å¿å®æ¯ï¼å·¦å­æ æå¤§åºé´ï¼å³å­æ æå¤§åºé´ï¼å·¦å³å­æ åå¹¶çä¸­é´åºé´ï¼ä¸èä¸­æå¤§çåºé´å¼
    if(a[2*i].ls == a[2*i].r-a[2*i].l+1)//å·¦å­æ åºé´æ»¡äºçè¯ï¼ç¶äº²å·¦åºé´è¦å ä¸å³å­©å­çå·¦åºé´
        a[i].ls += a[2*i+1].ls;
    if(a[2*i+1].rs == a[2*i+1].r-a[2*i+1].l+1)//åç
        a[i].rs += a[2*i].rs;
}

int query(int i,int t)
{
    if(a[i].l == a[i].r || a[i].ms == 0 || a[i].ms == a[i].r-a[i].l+1)//å°äºå¶å­èç¹æèè¯¥è®¿é®åºé´ä¸ºç©ºæèå·²æ»¡é½ä¸å¿è¦å¾ä¸èµ°äº
        return a[i].ms;
    int mid = (a[i].l+a[i].r)>>1;
    if(t<=mid)
    {
        if(t>=a[2*i].r-a[2*i].rs+1)//å ä¸ºt<=midï¼çå·¦å­æ ï¼a[2*i].r-a[2*i].rs+1ä»£è¡¨å·¦å­æ å³è¾¹è¿ç»­åºé´çå·¦è¾¹çå¼ï¼å¦ætå¨å·¦å­æ çå³åºé´åï¼åè¦çå³å­æ çå·¦åºé´æå¤é¿å¹¶è¿å
            return query(2*i,t)+query(2*i+1,mid+1);
        else
            return query(2*i,t);//å¦æä¸å¨å·¦å­æ çå³è¾¹çåºé´åï¼ååªéè¦çå·¦å­æ 
    }
    else
    {
        if(t<=a[2*i+1].l+a[2*i+1].ls-1)//åç
            return query(2*i+1,t)+query(2*i,mid);
        else
            return query(2*i+1,t);
    }
}

int main()
{
    int i,j,x;
    char ch[2];
    while(~scanf("%d%d",&n,&m))
    {
        top = 0;
        init(1,n,1);
        while(m--)
        {
            scanf("%s",ch);
            if(ch[0] == 'D')
            {
                scanf("%d",&x);
                s[top++] = x;
                insert(1,x,0);
            }
            else if(ch[0] == 'Q')
            {
                scanf("%d",&x);
                printf("%d\n",query(1,x));
            }
            else
            {
                if(x>0)
                {
                    x = s[--top];
                    insert(1,x,1);
                }
            }
        }
    }

    return 0;
}
