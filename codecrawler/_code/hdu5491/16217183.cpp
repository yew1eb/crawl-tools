#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))

ll ans;
int d,s1,s2;
int a[33];

int main ()
{
    int T;
    scanf ("%d",&T);
    for (int ii=1; ii<=T; ii++)
    {
        scanf ("%d%d%d",&d,&s1,&s2);
        ans=d;
        printf ("Case #%d: ",ii);
        int k=1,sum=0;
        CL(a);
        while (d)
        {
            a[k++]=d&1;
            if (d&1) sum++;//æ»å±æå¤å°ä¸ª1
            d=d>>1;
        }
        bool flag=false;
        int t,cnt=0,ret=0;
        for (int i=1; i<=k; i++)
        {
            if (!flag&&a[i]==0) ret++;//æ«å°¾ç0æ°
            if (a[i]==1) {flag=true; cnt++;}//æ«å°¾ç1æ°
            if (flag&&a[i]==0) {t=i; break;}
        }
        //cout<<ret<<" "<<cnt<<" "<<t<<endl;
        if (!ret)//æ«å°¾æ²¡0
        {
            if (sum-cnt>=s1-1) ans+=1;//å¦ææ»æ°åå»æ«å°¾1çæ°éä»»å¨[s1-1, s2]åï¼ç´æ¥å 1 
            else                       //å ä¸ºè¿ä½ä¼å¤åºä¸ä¸ª1ï¼æä»¥æ¯s1-1
            {
                int p=s1-(sum-cnt);//å¦åä¸ä½ä¸ä½çè¡¥1
                if (p==1) ans=d+1;
                else
                {
                    ans=ans+1;
                    p--;
                    while (p--)
                    {
                        ans=ans+(1<<p);
                    }
                }
            }
        }
        else//å¦ææ«å°¾æ0
        {
            if (sum<s2)//æ»1æ°å°äºs2
            {
                ans=ans+1;
            }
            else//æ»1æ°ç­äºs2
            {
                int g=ret;
                while (g--)//ææ«å°¾ç1åæ1
                    ans=ans+(1<<g);
                ans+=1;
                int p=sum-cnt+1;
                if (p<s1)//å¦æ1çä¸ªæ°è¿å°äºs1ï¼é£å°±ååæçæ«å°¾æ²¡1çæåµäº
                {
                    int h=s1-p;
                    while (h--)
                    {
                        ans=ans+(1<<h);
                    }
                }
            }
        }
        printf ("%I64d\n",ans);
    }
    return 0;
}
