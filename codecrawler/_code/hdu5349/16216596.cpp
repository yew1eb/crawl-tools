#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>

#define M 100010
using namespace std;
map<__int64, __int64>mp;
std::map<__int64, __int64>::iterator it;
int main()
{
    __int64 n;
    while (scanf("%I64d", &n) != EOF)
    {
        __int64 op, a;
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d", &op);
            if (op == 1)
            {
                scanf("%I64d", &a);
                mp[a]++;
            }
            else if (op == 2)
            {
                if (mp.size() == 0)
                    continue;
                it = mp.begin();
                int t = it->first;
                mp[t]--;
                if (mp[t] == 0)
                mp.erase(it);
            }
            else
            {
                if (mp.size() == 0)
                    printf("0\n");
                else
                {
                    it = mp.end();
                    it--;
                    printf("%I64d\n", it->first);
                }
            }
        }
    }
    return 0;
}
