#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 20;
const int inf = 1000000000;
int s[N],k;
__int64 Abs(__int64 x)
{
    return x<0?-x:x;
}
__int64 fun(__int64 x)
{
    __int64 tem=0;
    while(x)
    {
        s[k++]=x%10;
        tem+=x%10;
        x/=10;
    }
    return tem;
}
int main()
{
    __int64 n,m,ans,tem;
    int t,v,j=1;
    while(scanf("%I64d%d",&n,&t)&&(n!=-1||t!=-1))
    {
        ans=k=0;
        v=1;m=fun(n);
        while(k--)
            if(v)
                ans+=s[k],v=0;
            else
                ans-=s[k],v=1;
        while(t--)
        {
            k=0;
            m+=fun(m);
            while(k--)
                if(v)
                    ans+=s[k],v=0;
                else
                    ans-=s[k],v=1;
        }
        printf("Case #%d: ",j++);
        if(Abs(ans)%11)
            puts("No");
        else
            puts("Yes");
    }
}