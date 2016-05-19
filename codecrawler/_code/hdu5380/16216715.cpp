#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#define mp make_pair
#define INF 1000000000
#define MAXN 200050
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define P pair<int,int>
#define LL long long
using namespace std;

int a[MAXN];
LL buy[MAXN],sell[MAXN];
int len[MAXN];
LL now[MAXN];
int q[MAXN];
void work(){
    int st=0,ed=0;
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=0;i<=n;++i)scanf("%I64d%I64d",&buy[i],&sell[i]);

    now[0]=c;
    q[ed++]=0;
    LL ans=c*buy[0];
    for(int i=1;i<=n;++i){

        //æ£æå°è¾¾è¿ä¸ªåå¸çæ¶è
        int dis=a[i]-a[i-1];
        LL sum=c-dis;
        while(dis){
            int x=q[st];
            if(now[x]>dis){
                now[x]-=dis;
                dis=0;
            }else{
                dis-=now[x];
                now[x]=0;
                st++;
            }
        }

        //å¦ææ²¹ç®±ä¸­çæ²¹çä»·æ ¼å°äºå½ååå¸çååºä»·æ ¼ï¼é£ä¹è¿äºæ²¹çä»·æ ¼ä¼ç­äºå½ååå¸çååºä»·æ ¼ï¼å¯ä»¥æ³è±¡æå¨è¿ä¸ªåå¸å¨é¨ååºï¼ç¶åååä»·ä¹°åæ¥ã
        int era=0;
        while(st<ed){
            int x=q[st];
            if(buy[x]<sell[i]){
                era+=now[x];
                st++;
            }else
                break;
        }
        if(era!=0){
            st--;
            now[q[st]]=era;
            buy[q[st]]=sell[i];
        }


        //å¯¹äºæ²¹ç®±ä¸­ä»·æ ¼æ¯å½ååå¸ä¹°å¥ä»·æ ¼æ´é«çæ²¹ï¼å¨é¨ç´æ¥éåºæ²¹ç®±ãä»¥åæ¥çä»·æ ¼åæã
        bool flag=true;
        while(flag&&st<ed){
            flag=false;
            int x=q[ed-1];
            if(buy[x]>=buy[i]){
                flag=true;
                ans-=now[x]*buy[x];
                sum-=now[x];
                now[x]=0;
                ed--;
            }
        }

        //å°æ²¹ç®±å æ»¡ã
        q[ed++]=i;
        now[i]=c-sum;
        ans+=(c-sum)*buy[i];
    }

    //å°é®ç®±ä¸­å©ä½çéåºã
    while(st<ed){
        int x=q[st++];
           ans-=now[x]*buy[x];
    }
    printf("%I64d\n",ans);
}
int main()
{
    len[0]=len[1]=0;
    for(int i=2;i<MAXN;++i){
        int k=0;
        while((1<<k)<=i)k++;
        len[i]=k-1;
    }
    int tt;
    scanf("%d",&tt);
    while(tt--){
        work();
    }
}
