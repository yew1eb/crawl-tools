#include<stdio.h> 
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<time.h>
#include<bitset>
using namespace std;
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
const int N=1e5+10,M=0,Z=1e9+7;
int casenum,casei;
int n,m,K;
char a[N];
//ä»¥ä¸ä¸ºçææè¡¨ç¨åº
char b[4000];
bool flag;
map<string,int>mop;
void dfs(int p,int num)
{
    if(num>m)return;        //æ°éå¤ªå¤
    if(num+n-p<m)return;        //æ°éä¸å¤
    if(p==n)
    {
        flag=1;
        b[p]=0;
        puts(b);
        return;
    }
    for(int i=0;i<K;i++)
    {
        b[p]='A'+i;b[p+1]=0;
        for(int j=0;j<=p;j++)
        {
            int h=j;int t=p;
            while(h<t&&b[h]==b[t]){h++;t--;}
            if(h>=t&&++mop[b+j]==1)++num;
        }
        dfs(p+1,num);if(flag)return;b[p+1]=0;
        for(int j=0;j<=p;j++)
        {
            int h=j;int t=p;
            while(h<t&&b[h]==b[t]){h++;t--;}
            if(h>=t&&--mop[b+j]==0)--num;
        }
    }
}
void table()
{
    while(~scanf("%d%d%d",&n,&m,&K))
    {
        mop.clear();
        flag=0;
        dfs(0,0);
        if(!flag)puts("Impossible");
    }
}
//ä»¥ä¸ä¸ºæé ç¨åº
void solve()
{
    printf("Case #%d:\n",casei);
    if(n==m)
    {
        for(int i=0;i<n;i++)printf("%c",'A');
        puts("");
    }
    else if(n<m||K==1)
    {
        puts("Impossible");
    }
    else if(K==2)
    {
        if(n==8&&m==7)puts("AABABBAA");
        else if(m<8)puts("Impossible");
        else
        {
            a[0]='A';a[1]='A';a[2]='B';a[3]='A';a[4]='B';a[5]='B';
            int beh=m-8;
            int bef=n-beh;
            for(int i=6;i<bef;i++)a[i]=a[i%6];
            for(int i=bef;i<n;i++)a[i]=a[i-1];
            if(a[bef-1]!=a[bef-2])
            {
                int p=(bef-1)%6;
                if(p==0)
                {
                    a[bef++]='B';
                    a[bef++]='A';
                    a[bef++]='A';
                }
                else if(p==2)
                {
                    a[bef++]='B';
                }
                else if(p==3)
                {
                    a[bef++]='A';
                }
                else if(p==4)
                {
                    a[bef++]='A';
                    a[bef++]='A';
                }
            }
            for(int i=bef;i<n;i++)a[i]=a[i-1];a[n]=0;puts(a);
        }
    }
    else
    {
        if(m<3)puts("Impossible");
        else
        {
            int beh=m-3;
            int bef=n-beh;
            for(int i=0;i<bef;i++)a[i]='A'+i%3;
            for(int i=bef;i<n;i++)a[i]=a[i-1];a[n]=0;puts(a);
        }
    }
}
int main()
{
    //table();
    scanf("%d",&casenum);
    for(casei=1;casei<=casenum;casei++)
    {
        scanf("%d%d%d",&n,&m,&K);
        solve();
    }
}
/*
ãtrick&&åæ§½ã
1ï¼å¯¹äºæé çé¢ç®ï¼å¶å®å¯ä»¥ä¸å¼å§åä¸ªçæå¨ã
    å¯ä»¥æ¾è§å¾ï¼å¯ä»¥æè¡¥ä¸ï¼å¯ä»¥å¯¹ææ­£ç¡®æ§ï¼ç®ç´ä¸è½åèæï¼
2ï¼æç»´ä¸è¦å¤ªæµï¼k==2çæåµæ²¡æèèæ¸æ¥å°±åï¼å¯¼è´waäº1æ¬¡ï¼æ¥é2ä¸ªå°æ¶QwQ

ãé¢æã
Tï¼20000ï¼ç»æ°æ®ï¼
æ¯ç»æ°æ®ç»ä½ n,mï¼1<=n,m<=1e5ï¼ï¼kï¼1<=k<=26ï¼ã
è®©ä½ æé ä¸ä¸ªé¿åº¦æ°å¥½ä¸ºnçä¸²ï¼ä¸²ä¸­åªåå«åkä¸ªå¤§åå­ç¬¦ï¼ä½¿å¾å¶åå«æ°å¥½mä¸ªä¸ç¸åçåæä¸²ã

ãç±»åã
æé 

ãåæã
1ï¼é¦åæä»¬åç°ï¼å¦æn==mï¼ä»¥"AA...AA"çå½¢å¼æé å³å¯
2ï¼ç¶åæä»¬åç°ï¼å¦æm>nï¼æ¯ä¸å¯è½å®ç°çã
    å³ï¼å¨ä¸ä¸ªé¿åº¦ä¸ºnä¸ªå­ç¬¦ä¸²ä¸­ï¼æ¬è´¨ä¸ååæä¸²çæ°éä¸è¶è¿nãè¿ä¸ªå¯ä»¥ç¨ä¸å¥è¯è¯æââ
    ä»¥æ¯ä¸ªä½ç½®ä¸ºç»å°¾çåæä¸²ä¸­ï¼åªæè½å»¶å±åºçæé¿åæä¸²ææ¯æ°çã
    å ä¸ºââå¦åè¿ä¸ªåæä¸²ä¸å®æ¯å³äºæä¸ªä½ç½®å¯¹ç§°çï¼æèä¸æ¯æ°çãä½ç½®åªænä¸ªï¼æä»¥åæä¸²æå¤ä¹æ¯nä¸ªã
3ï¼äºæ¯ï¼ç°å¨å°±åªå©ä¸m<näºãç»åæè¡¨ï¼ä¾¿å¯ä»¥éè¿è§å¾å¾å¿«å¾å°æé æ¹æ³
(1)å¦æk==1ï¼æ¾ç¶æ è§£
(2)å¦æk==2ï¼
    m<8çè¯æ è§£ï¼å ä¸ºæä»¬å¦æè½åºç°éå¤åæä¸²ï¼ä¹åºäºè³å°åºç°8ä¸ªåæä¸²çåºç¡ä¸ã
    ï¼ç¶èæä¸ç¹ç¹æ®ï¼å½n=8æ¶må¯ä»¥=7ï¼
    è¿æ¯å ä¸ºå¯¹äºï¼AABABBï¼è¿ä¸ªä¸²æ ééå¤ï¼å½¢æAABABBAABABBAABABBâ¦â¦
    åæä¸²ä¹ä¸è¿åªæA,B,AA,BB,ABA,BAB,ABBA,BAABå«ä¸ªã
    äºæ¯ï¼å¨m>=8çæ¶åï¼åé¢n-(m-8)ä¸ªæ¯AABABBAABABBâ¦â¦
    åé¢çm-8ä¸ªåæä¸²ï¼è¦å¦ä½æé å¢ï¼
    æä»¬éå¤çè¿ä¸ªä¸²AABABBï¼é¿åº¦ä¸º6ï¼äºæ¯å6ä¸ªä½ç½®ä¸ºç»å°¾æ¶çæåµä½è®¨è®ºââ
    pos1:(AABABB)A            :
        å»¶å±Bï¼å¾å°BABBABï¼åå»¶å±Aï¼å¾å°ABABBABAï¼åå»¶å±Aï¼å¾å°AABABBABAAï¼åé¢ä¸ç´å»¶å±A
    pos2:(AABABB)AA            :
        åé¢ä¸ç´å»¶å±A
    pos3:(AABABB)AAB        :
        å»¶å±Bï¼å¾å°BBAABBï¼åé¢ä¸ç´å»¶å±B
    pos4:(AABABB)AABA        :
        å»¶å±Aï¼å¾å°AABAAï¼åé¢ä¸ç´å»¶å±A
    pos5:(AABABB)AABAB        :
        å»¶å±Aï¼å¾å°ABABAï¼åå»¶å±Aï¼å¾å°AABABAAï¼åé¢ä¸ç´å»¶å±A
    pos6:(AABABB)AABABB        :
        åé¢ä¸ç´å»¶å±B
(3)å¦æk==3ï¼
    m<3çè¯æ è§£ï¼å ä¸ºå¦ææä»¬è½åºç°éå¤åæä¸²ï¼ä¹åºäºè³å°åºç°3ä¸ªåæä¸²çåºç¡ä¸ã
    è¿æ¯å ä¸ºï¼æä»¬åç°ABCABCABCâ¦â¦è¿æ ·çä¸²ï¼åæä¸²çä¸ªæ°ä¹åªæ3ä¸ªï¼å³'A','B','C'ï¼å¶å®ä¸²é¿æ¾ä¸å°å¯¹åºã
    äºæ¯ï¼å¨m>=3çæ¶åï¼åé¢n-(m-3)ä¸ªæ¯ABCABCABCâ¦â¦ï¼ä½¿å¾å¶æå¤åªåºç°3ä¸ªåæä¸²ï¼
    èä¹åçm-3ä¸ªåæä¸²ï¼æä»¬éè¿ææåä¸ä¸ªå­ç¬¦ä¸ç´æ©å¢å¾å°ã

ãæ¶é´å¤æåº¦&&ä¼åã
Oï¼nï¼

ãæ°æ®ã
input
8 7 2
output
AABABBAA

*/