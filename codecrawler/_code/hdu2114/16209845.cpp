#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    __int64 n;
    __int64 sum,ans;
    __int64 s[5];
    while(scanf("%I64d",&n)!=EOF)
    {
        sum=0;
        sum=(n*(1+n))/2%10000;
        ans=(sum*sum)%10000;
        int k=0;
        memset(s,0,sizeof(s));
        while(ans)
        {
            if(k==4)
            break;
            s[k++]=ans%10;
            ans/=10;
        }
        for(int i=3;i>=0;i--)
        printf("%I64d",s[i]);
        printf("\n");
    }
    return 0;
}
