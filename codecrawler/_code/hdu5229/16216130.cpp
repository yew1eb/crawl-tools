#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> mp;
int gcd(int n,int m)
{
    if(m==0)
    return n;
    else
    return gcd(m,n%m);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        int n;
        scanf("%d",&n);
        int odd=0,even=0;
        string s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            mp[s]++;
            if(s.size()%2)
            {
                odd++;
                ans+=even;
            }
            else
            {
                even++;
                ans+=odd;
            }
        }
        map<string,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            int cur=it->second;
            ans+=(cur*(cur-1))/2;
        }
        int all=n*(n-1)/2;
        int gd=gcd(ans,all);
        printf("%d/%d\n",ans/gd,all/gd);
    }
    return 0;
}
