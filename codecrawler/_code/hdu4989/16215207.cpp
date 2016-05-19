//15ms
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
long long a[100];
set<long long> s;
set<long long>::iterator it;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        s.clear();
        for(int j=0;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                s.insert(a[j]+a[k]);
            }
        }
        long long ans=0;
        for(it=s.begin();it!=s.end();it++)
        {
            ans=ans+*it;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
