#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstdlib>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;
template<class T>inline T read(T&x)
{
    char c;
    while((c=getchar())<=32)if(c==EOF)return 0;
    bool ok=false;
    if(c=='-')ok=true,c=getchar();
    for(x=0; c>32; c=getchar())
        x=x*10+c-'0';
    if(ok)x=-x;
    return 1;
}
template<class T> inline T read_(T&x,T&y)
{
    return read(x)&&read(y);
}
template<class T> inline T read__(T&x,T&y,T&z)
{
    return read(x)&&read(y)&&read(z);
}
template<class T> inline void write(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x<10)putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
template<class T>inline void writeln(T x)
{
    write(x);
    putchar('\n');
}
//-------ZCC IO template------
const int maxn=1e4+10;
const double inf=99999999;
#define lson (rt<<1),L,M
#define rson (rt<<1|1),M+1,R
#define M ((L+R)>>1)
#define For(i,t,n) for(int i=(t);i<=(n);i++)
typedef long long  LL;
typedef double DB;
typedef pair<int,int> P;
#define bug printf("---\n");
#define mod  100007

int num[maxn];
int pos[maxn];
int a[maxn];
int main()
{
    int n,m;
    while(read(n))
    {
        memset(num,0,sizeof(num));
        memset(pos,0,sizeof(pos));
        int mx=0;
        For(i,1,n)
        {
            int tmp;
            read(tmp);
            a[i]=tmp;
            num[tmp]++;//è®°å½æ¯å¦æè¿ä¸ªæ°
            pos[tmp]=i;//è®°å½è¿ä¸ªæ°çä½ç½®
            mx=max(mx,tmp);//æå¤§çå¼ï¼æ¥æ¾çè¾¹ç
        }
        int ans=0;

        for(int i=1;i<=n;i++)
        {

            int mn=inf;
            for(int j=a[i]+a[i];j<=mx;j+=a[i])
            {

                if(num[j]&&pos[a[i]]<pos[j]&&pos[j]<=n)
                {
                    mn=min(mn,pos[j]);
                }
            }
            if(mn!=inf)ans+=mn;
        }


        writeln(ans);
    }
    return 0;
}


