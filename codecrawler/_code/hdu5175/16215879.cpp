#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
vector<LL>vec;
LL n;
LL gcd(LL a,LL b)
{
    if(b)return gcd(b,a % b);
    return a;
}
int main()
{
    int _ = 0;
    while(scanf("%I64d",&n) != EOF)
    {
        vec.clear();
        LL cnt = sqrt(n + 1) + 1;
        for(LL i = 1;i <= cnt;i++)
            if((n % i) == 0)
            {
                if((n ^ i) < n && gcd(n,n ^ i) == i)
                    vec.push_back(i ^ n);
                LL cur = n / i;
                if(cur != i && (n ^ cur) < n && gcd(n,n ^ cur) == cur)
                    vec.push_back(n ^ cur);
            }
        sort(vec.begin(),vec.end());
        cnt = unique(vec.begin(),vec.end()) - vec.begin();
        printf("Case #%d:\n%I64d\n",++_,cnt - 1);
        if(1 >= cnt)puts("");
        for(LL i = 1;i < cnt;i++)
        {
            if(i != cnt - 1)printf("%I64d ",vec[i]);
            else printf("%I64d\n",vec[i]);
        }
    }
    return 0;
}
