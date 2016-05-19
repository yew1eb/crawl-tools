#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const LL NUM=10;//è¿ç®æ¬¡æ°ï¼Miller_Rabinç®æ³ä¸ºæ¦çè¿ç®ï¼è¯¯å¤çä¸º2^(-NUM);
LL t,f[100];
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
int main()
{
    srand(time(NULL));//éæºæ°è®¾å®ç§å­
    LL n;
    while(cin>>n)
    {
        if(n==1){cout<<"is not a D_num"<<endl;continue;}//ç¹å¤
        t=0;
        find(n);
        if(t!=2&&t!=3){cout<<"is not a D_num"<<endl;continue;}
        sort(f,f+t);
        if(t==2)
        {
            if(f[0]!=f[1])cout<<f[0]<<" "<<f[1]<<" "<<n<<endl;
            else cout<<"is not a D_num"<<endl;
        }
        else//næ¯ä¸ä¸ªç´ æ°çä¸æ¬¡æ¹
        {
            if(f[0]==f[1]&&f[1]==f[2])cout<<f[0]<<" "<<f[0]*f[0]<<" "<<n<<endl;
            else cout<<"is not a D_num"<<endl;
        }
    }
    return 0;
}
