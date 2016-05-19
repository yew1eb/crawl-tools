#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

vector< pair<int,int> > v1,v2;

void get_pp(int g,int l)
{
    v1.clear();
    v2.clear();
    for(long long i=2;i*i<=l;i++)
    {
        int point_cnt1 = 0, point_cnt2 = 0;
        while(g % i == 0)
        {
            g /= i;
            point_cnt1 ++;
        }
        while(l % i == 0)
        {
            l /= i;
            point_cnt2 ++;
        }
        if(point_cnt1 != point_cnt2)
        {
            v1.push_back(make_pair(i,point_cnt1));
            v2.push_back(make_pair(i,point_cnt2));
        }
    }
    if(l != 1 && g != l)
    {
        v1.push_back(make_pair(l,0));
        v2.push_back(make_pair(l,1));
    }
}

long long solve(int g,int l)
{
    if(l % g != 0)
        return 0;
    get_pp(g,l);
    long long ans = 1;
    for(int i=0;i<(int)v1.size();i++)
        ans *= 6 * (v2[i].second - v1[i].second);
    return ans;
}

int main()
{
    int T,gcd,lcm;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&gcd,&lcm);
        printf("%I64d\n",solve(gcd,lcm));
    }
    return 0;
}
