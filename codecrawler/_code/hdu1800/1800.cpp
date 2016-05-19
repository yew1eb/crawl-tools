#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> ma;

int main()
{
    int N, p, i;
    while(scanf("%d", &N) == 1)
    {
        if(!N) continue;
        ma.clear();
        for(i = 1; i <= N; i++)
        {
            scanf("%d", &p);
            if(ma.find(p) == ma.end())
            {
                ma[p] = 1;
            }
            else
            {
                ma[p]++;
            }
        }
        int maxx = -1;
        for(map<int, int>::const_iterator t = ma.begin(); t != ma.end(); t++)
        {
            int cnt = t->second;
            maxx = max(maxx, cnt);
        }
        printf("%d\n", maxx);
    }
    return 0;
}