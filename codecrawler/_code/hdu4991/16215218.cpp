#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int mod=123456789;
const int N=10002;
int sum[101][N<<2];//çº¿æ®µæ å­å¨å N*4
struct node
{
    int v;
    int idx;
}a[N];
bool operator <(const node &a,const node &b)
{
    return a.v<=b.v;//æ=å· ä¿è¯éå¤çæ°ä¸ä¼æ´æ°å¤æ¬¡
}
void update(int idx,int len,int suml,int root,int l,int r)//æ´æ°idxä¸æ ä¸ºç»å°¾é¿åº¦ä¸ºlençä¸²æ°ç®ä¸ºsuml
{
    if(l==r) {
        sum[len][root]=suml;
        return;
    }
    int mid=(l+r)>>1;
    if(idx<=mid) update(idx, len, suml, root*2, l, mid);
    else update(idx, len, suml, root*2+1, mid+1, r);

    sum[len][root]=sum[len][root*2]+sum[len][root*2+1];
    sum[len][root]%=mod;
}
int query(int la,int ra,int len,int root,int l,int r)//ç»è®¡è¾å¥çla~raä¸æ åºé´é¿åº¦ä¸ºlençåºåæ°
{
    if(la>ra) return 0;
    if(la<=l&&ra>=r) return sum[len][root];
    int mid=(l+r)>>1;
    if(ra<=mid) return query(la,ra,len,root*2,l,mid)%mod;
    if(la>mid) return query(la,ra,len,root*2+1,mid+1,r)%mod;
    int ans=(query(la,ra,len,root*2,l,mid)+query(la,ra,len,root*2+1,mid+1,r))%mod;
    return ans;
}
int main()
{
    int n,k,i,j;
    while(~scanf("%d%d",&n,&k))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].idx=i;
        }
        memset(sum,0,sizeof(sum));
        sort(a+1,a+1+n);//æç§a[i].vèªå°å°å¤§æåºï¼ä¿è¯äºéå¢é¡ºåº
        for(i=1;i<=n;i++)
        {
            update(a[i].idx,1,1,1,1,n);
            for(j=1;j<k;j++)
            {
                int suml=query(1,a[i].idx-1,j,1,1,n);
                if(!suml) break;
                update(a[i].idx,j+1,suml,1,1,n);
            }
        }
        printf("%d\n",sum[k][1]);
    }
    return 0;
}
