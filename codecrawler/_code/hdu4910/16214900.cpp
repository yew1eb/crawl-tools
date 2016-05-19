#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const LL NUM=20;//è¿ç®æ¬¡æ°ï¼Miller_Rabinç®æ³ä¸ºæ¦çè¿ç®ï¼è¯¯å¤çä¸º2^(-NUM);
const int maxn=1e6+10;
int prime[maxn],c[maxn],tot;
LL t,f[1000];
LL mul_mod(LL a,LL b,LL n)//æ±a*b%nï¼ç±äºaåbå¤ªå¤§ï¼éè¦ç¨è¿ä½ä¹æ³
{
    a=a%n;
    b=b%n;
    LL s=0;
    while(b)
    {
        if(b&1)
            s=(s+a)%n;
        a=(a<<1)%n;
        b=b>>1;
    }
    return s;
}
LL pow_mod(LL a,LL b,LL n)//æ±a^b%n
{
    a=a%n;
    LL s=1;
    while(b)
    {
        if(b&1)
            s=mul_mod(s,a,n);
        a=mul_mod(a,a,n);
        b=b>>1;
    }
    return s;
}
bool check(LL a,LL n,LL r,LL s)
{
    LL ans,p,i;
    ans=pow_mod(a,r,n);
    p=ans;
    for(i=1;i<=s;i++)
    {
        ans=mul_mod(ans,ans,n);
        if(ans==1&&p!=1&&p!=n-1)return true;
        p=ans;
    }
    if(ans!=1)return true;
    return false;
}
bool Miller_Rabin(LL n)//Miller_Rabinç®æ³ï¼å¤æ­næ¯å¦ä¸ºç´ æ°
{
    if(n<2)return false;
    if(n==2)return true;
    if(!(n&1))return false;
    LL i,r,s,a;
    r=n-1;s=0;
    while(!(r&1)){r=r>>1;s++;}
    for(i=0;i<NUM;i++)
    {
        a=rand()%(n-1)+1;
        if(check(a,n,r,s))
            return false;
    }
    return true;
}
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL Pollard_rho(LL n,LL c)//Pollard_rhoç®æ³ï¼æ¾åºnçå å­
{
    LL i=1,j,k=2,x,y,d,p;
    x=rand()%n;
    y=x;
    while(true)
    {
        i++;
        x=(mul_mod(x,x,n)+c)%n;
        if(y==x)return n;
        if(y>x)p=y-x;
        else p=x-y;
        d=gcd(p,n);
        if(d!=1&&d!=n)return d;
        if(i==k)
        {
            y=x;
            k+=k;
        }
    }
}
void find(LL n)//æ¾åºnçææå å­
{
    if(Miller_Rabin(n))
    {
        f[t++]=n;//ä¿å­ææå å­
        return;
    }
    LL p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);//ç±äºpå¿å®ä¸ºåæ°ï¼æä»¥éè¿å¤æ¬¡æ±è§£å¿å®è½æ±å¾ç­æ¡
    find(p);
    find(n/p);
}
void init()//é¢å¤çï¼æ¾åºææ1e7ä»¥åçç´ æ°ï¼ä»¥åå°æ¥æ¾1e14èå´æ°çå å­çæ¶é´
{           //ç°è¡ç­ç´ æ°çæ¹æ³ï¼æ¶é´å¤æåº¦ä¸ºO(n)
    memset(c,false,sizeof(c));
    int i,j;
    tot=0;
    for(i=2;i<=1e6;i++)
    {
        if(!c[i])prime[tot++]=i;
        for(j=0;j<tot;j++)
        {
            if(i*prime[j]>1e6)break;
            c[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
    //printf("%d\n",tot);
    //for(i=0;i<20;i++)
    //    printf("prime[%d]:%d\n",i,prime[i]);
}
bool judge(LL n)
{
    int i,j,k;
    for(i=0;i<tot;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)n=n/prime[i];
            if(n==1)return true;
            return false;
        }
    }
    return false;
}
int main()
{
    //freopen("D:\\in.txt","r",stdin);
    //freopen("C:\\Documents and Settings\\Administrator\\æ¡é¢\\false.txt","w",stdout);
    srand(time(NULL));//éæºæ°è®¾å®ç§å­
    init();
    LL n;
    while(cin>>n)
    {
        if(n==-1)break;
        if(n==1){cout<<0<<endl;continue;}
        /*t=0;
        find(n);
        sort(f,f+t);
        LL i,j,k=0,ans=0;
        if(f[0]==2)k++;
        else ans++;
        for(i=1;i<t;i++)
        {
            if(f[i]==2)k++;
            if(f[i]!=f[i-1])ans++;
        }
        if(k>=1)
        ans+=k-1;
        //cout<<n<<":";
        if(ans<2)cout<<n-1<<endl;
        else cout<<1<<endl;*/
        LL i,j,k,ans=0;
        k=n;
        while(k%2==0){k=k/2;ans++;}
        if(ans>=1)ans--;
        if(k!=1)
        {
            if(Miller_Rabin(k))ans++;
            else
            {
                i=(LL)sqrt(k+0.5);
                if(i*i==k&&Miller_Rabin(i)||judge(k))ans++;
                else ans+=2;
            }
        }
        if(ans<2)cout<<n-1<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
