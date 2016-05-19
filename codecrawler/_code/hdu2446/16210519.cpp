#include<stdio.h>
#include<math.h>
typedef __int64 ll;

ll f1(ll n)
{
    return n*(n+1)*(n+2);
}

ll f2(ll n)
{
    return n*(n+1);
}

int main()
{
    ll s,t,tmp1,tmp2,tmp3,i,j,k,n;
    ll ans1,ans2,ans3;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&s);
        tmp1=(ll)pow(s*6.0,1.0/3.0)-2;
        for(i=tmp1;;i++)
            if(f1(i)>=6*s)
                break;
        ans1=i-1;
        n=f1(ans1+1)/6-f1(ans1)/6;
        s=s-f1(ans1)/6;
        tmp2=(ll)pow(s*2.0,0.5);
        for(i=tmp2;;i++)
            if(f2(i)>=2*s)
                break;
        ans2=i-1;
        ans3=s-f2(ans2)/2;
        printf("%I64d %I64d %I64d\n",ans1+1,ans2+1,ans3);
    }
    return 0;
}