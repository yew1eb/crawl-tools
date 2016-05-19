#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long LL;
const double pi=4.0*atan(1.0);
const int MAXN=200005;
const int INF=20000;
char s[MAXN];
int a[MAXN];
int qianzui[MAXN];//åç¼å
//å¥å¶æï¼ä¸ªæ°
/* 0å¶æ°1  */
/* 1å¶æ°0  */
/* 0å¥æ°0  */
/* 1å¥æ°1  */
//ä»¥ä¸åç§ä¸å®è½ä½¿æå¯¹åºçå¼å¨é¨åå°
//å¶ä½æåµå¿é¡»èå»ä¸ä¸ªæå°å¼
int main()
{

    int i,j,k;    
    int cas=1;
    int temp,sum,ans,sign;
    int slen,len;
    int T;
    //freopen("1007.in","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&T)!=EOF)
    {
        for(cas=1;cas<=T;cas++)
        {
            //æåé¢å ä¸ª'0'ï¼å»æäº ???æ°å­ çæåµ
            s[0]='0';
            scanf("%s",s+1);
            slen=strlen(s);
            a[0]=0;
            qianzui[0]=0;
            sum=0;
            for(i=1;i<slen;i++)
            {
                scanf("%d",a+i);
                qianzui[i]=qianzui[i-1]+a[i];
            }
            i=0;
            int left,right;
            ans=0;
            int mm;
            while(i<slen)
            {
                sign=0;
                mm=INF;
                //æ¾ç¬¬ä¸ä¸ªï¼ å¹¶è®°å½ä¸æ 
                for(;i<slen;i++)
                {
                    if(s[i]=='?')
                    {
                        left=i;
                        sign=1;
                        break;

                    }
                }
                if(sign==0)//å¦æsign==0ï¼é£ä¹æå³çå©ä¸çå¨æ¯æ°å­
                    break;
                for(;i<slen;i++)
                {

                    if(s[i]!='?')
                    {
                        mm=min(a[i],mm);
                        right=i;
                        break;
                    }
                    else
                    {
                        mm=min(a[i],mm);
                    }
                }

                if(i==slen)//æ­¤æ¶ä»£è¡¨ æ°å­???...?
                {
                    //ä¸å®é½è½åå°
                    ans+=qianzui[slen-1]-qianzui[left-1];
                }
                else
                {
                    //left,rightä¸å®å¨
                    right--;
                    len=right-left+1;

                    if(s[left-1]=='0'&&s[right+1]=='0'||(s[left-1]=='1'&&s[right+1]=='1'))
                    {
                        if(len%2==1)
                        {
                            ans+=qianzui[right+1]-qianzui[left-1];
                        }
                        else
                        {
                            ans+=qianzui[right+1]-qianzui[left-1];
                            ans-=mm;
                        }
                    }
                    else 
                    {
                        if(len%2==0)
                        {
                            ans+=qianzui[right+1]-qianzui[left-1];
                        }
                        else
                        {
                            ans+=qianzui[right+1]-qianzui[left-1];
                            ans-=mm;
                        }

                    } 
                }
            }
            //ç®ä¸ç¡®å®çå¼
            for(i=1;i<slen;i++)
            {
                if(s[i-1]!='?'&&s[i]!='?')
                {
                    int t1=s[i-1]-'0';
                    int t2=s[i]-'0';
                    ans+=(t1^t2)*a[i];
                }
            }
            printf("Case #%d: %d\n",cas,ans);

        }
    }
    return 0;
}