#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define ull unsigned long long

using namespace std;

int M,L;
char s[100010];
const int seed=31;
ull nbase[100010];
ull hash[100010];
ull h[100010];

void solve()
{
    int len=strlen(s+1);
    hash[len+1]=0;
    for (int i=len;i>=1;i--)
        hash[i]=hash[i+1]*seed+s[i]-'a';
    for (int i=1;i+L-1<=len;i++)
        h[i]=hash[i]-hash[i+L]*nbase[L];
    int ans=0;
    for (int i=1;i<=L&&i+L*M-1<=len;i++)
    {
        map <ull,int> mp;
        for (int t=0;t<M;t++)
        {
            ull hh=h[i+t*L];
            mp[hh]++;
        }
        if (mp.size()==M)
            ans++;
        for (int t=M;i+(t+1)*L-1<=len;t++)
        {
            ull hh=h[i+(t-M)*L];
            mp[hh]--;
            if(!mp[hh])
                mp.erase(hh);
            hh=h[i+t*L];
            mp[hh]++;
            if (mp.size()==M)
                ans++;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    nbase[1]=seed;
    for (int i=2;i<=100010;i++)
        nbase[i]=nbase[i-1]*seed;
    while (~scanf("%d%d",&M,&L))
    {
        scanf("%s",s+1);
        solve();
    }
}
