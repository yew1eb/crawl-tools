#include<stdio.h>
#include<string.h>
#define ll __int64
ll c[100000+5],v[100000+5];
int n;
int Lowbit(int k)
{
    return (k&-k);
}
void update(int pos,int num,int val)
{
    while(pos<=n)
    {
        c[pos]+=num;
        v[pos]+=val;
        pos+=Lowbit(pos);
    }
}
ll sum_count(int pos)
{
    ll  s=0;

    while(pos>0)
    {
        s+=c[pos];
        pos-=Lowbit(pos);
    }
    return s;
}
ll sum(int pos)
{
    ll s=0;

    while(pos>0)
    {
        s+=v[pos];
        pos-=Lowbit(pos);
    }
    return s;
}
int main()
{
    int i,x;
    while(scanf("%d",&n)!=-1)
    {
        memset(c,0,sizeof(c));
        memset(v,0,sizeof(v));
        ll ans=0,k2,k1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            update(x,1,x);
            k1=i-sum_count(x);///å°æ­¤ä¸ºæ­¢  æ¯xå¤§çä¸ªæ°ï¼
///sum_count[x] ä¸ºè¾å¥iä¸ªæ°çæ¶å xä¹åæsum_count[x]ä¸ªæ¯xå°çæ° ç¨iç¸ååä¸ºå¤§äºxçä¸ªæ°
            if(k1!=0)
            {
            k2=sum(n)-sum(x);///å°æ­¤ä¸ºæ­¢  æ¯xå¤§çæ°çåï¼
            ans+=x*k1+k2;///å°æ­¤ä¸ºæ­¢ æ¯xå¤§çæ°ä¸xäº¤æ¢ä¹åçåï¼
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

