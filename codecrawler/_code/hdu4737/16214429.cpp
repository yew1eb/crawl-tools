#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=31;
const int maxm=101000;
int n,m,a[maxm],cnt[maxn];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0,num=0,pre=1;
    for(int i=1;i<=n;i++)
    {
        num|=a[i];
        for(int j=0;j<30;j++)
        if(a[i]&(1<<j))
            cnt[j]++;
        while(pre<=i&&num>=m)
        {
        ans+=i-pre;
        for(int j=0;j<30;j++)
            if(a[pre]&(1<<j))
            {
            cnt[j]--;
            if(!cnt[j])
                num^=(1<<j);
            }
        pre++;
        }
    }
    for(int i=pre;i<=n;i++)
        ans+=n-i+1;
    printf("Case #%d: %d\n",cas++,ans);

    }
    return 0;
}
