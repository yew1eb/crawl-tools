#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100010;
int N,K,M;
LL a[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    LL cas=0;
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(LL i=1; i<=N; i++) scanf("%I64d",&a[i]);
        sort(a+1,a+N+1);
        int i=0;
        while(i<N&&a[i+1]<=M) i++;
        printf("Case #%I64d:\n",++cas);
        if(i==0)
        {
            printf("madan!\n");
            continue;
        }
        LL cur=K;
        LL last=a[i];
        bool flag=1;
        i++;
        while(i<=N)
        {
            if(a[i]-last>cur)
            {
                flag=0;
                break;
            }
            if(i<N&&a[i+1]-last<=cur)i++;
            else
            {
                cur--;
                cur=max(cur,0LL);
                last=a[i];
                i++;
            }
        }
        if(flag) printf("why am I so diao?\n");
        else printf("madan!\n");
    }
    return 0;
}