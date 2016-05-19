#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll __int64
ll t,tot,s1,s2;
ll d[35],f;
ll getshu(ll x)
{
    ll num=0;
    t=0;
    while(x)
    {
        d[t++]=x%2;
        if(x%2)num++;
        x=x/2;
    }
    return num;
}
ll quickpow(int a,int b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)ans=ans*a;
        a=a*a;
        b=b/2;
    }
    return ans;
}
int main()
{
    ll T,i,j,k,D,cases;
  cases=0;
    scanf("%I64d",&T);
    while(T--)
    {
        f=0;
        cases++;
        memset(d,0,sizeof(d));
        tot=0;
        t=0;
        scanf("%I64d%I64d%I64d",&D,&s1,&s2);
        ll y=D;
        y++;
      while(1)
      {
          tot=getshu(y);
          if(tot<s1)
          {
              for(i=0;i<t;i++)
              {
                  if(d[i]==0){
                    y+=1<<i;
                    break;
                  }
              }
          }
          else if(tot>s2)
          {
              for(i=0;i<t;i++)
              {
                  if(d[i]==1)
                  {
                      y+=1<<i;
                      break;
                  }
              }
          }
          else break;
      }
       printf("Case #%I64d: ",cases);
       printf("%I64d\n",y);
    }
    return 0;
}