#include<stdio.h>
#include<string.h>
#define N 20005
#include<algorithm>
using namespace std;
int stack[N];
int dp[N];
int maxx;
int n;
struct node
{
    int w;
    int h;
}a[N];
int cmp(struct node b,struct node c)
{
    if(b.w==c.w)
    return b.h<c.h;
    else return b.w>c.w;
}
void LIS()
{
    //dp[i]è¡¨ç¤ºåiä¸ªæ°å­ä¸­å ä¸ç¬¬iä¸ªæ°å­åï¼æå ä¸ªæ°å­æ¯éå¢çï¼å³åiä¸ªæ°å­ä¸­æå¤å°ä¸ªæ¯ç¬¬iä¸ªæ°å­å°ç+1
    //int stack[N];
    memset(dp,0,sizeof(dp));
    memset(stack,0,sizeof(stack));
    int top=0;
    stack[top]=-99999999;
    maxx=-1;
    for(int i=1; i<=n; i++)
    {
        //å¦æa[i]>æ é¡¶é¨åç´ ï¼ååæ 
        if(a[i].h>=stack[top])
        {
            stack[++top]=a[i].h;
            dp[i]=top;
        }
        //å¦æa[i]ä¸å¤§äºæ é¡¶é¨åç´ ï¼åäºåæ¥æ¾ç¬¬ä¸ä¸ªæ¯a[i]å¤§çåç´ 
        else
        {
            int l=1,r=top;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(a[i].h>=stack[mid])
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            //æ¿æ¢a[i]
            stack[l]=a[i].h;
            dp[i]=l;
        }
        if(dp[i]>maxx)
        maxx=dp[i];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].w,&a[i].h);
        }
        sort(a+1,a+n+1,cmp);
        LIS();
        printf("%d\n",maxx);
    }
    return 0;
}
/*
10
4
30 10 20 13 20 14 20 15//æ­¤æ ·ä¾å¯ä»¥è§£éä¸ºä»ä¹éæ©ä¸ä¸ªååºï¼ä¸ä¸ªéåºæå
4
10 10 20 10 20 10 30 25//æ­¤æ ·ä¾å³å®äºæ±çæé¿ä¸åå­åºååæ¬ç¸ç­æåµ
4
10 15 20 10 20 30 30 25
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
*/
