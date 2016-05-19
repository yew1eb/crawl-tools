#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
int main(){
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--)
    {
        vector <int> g[30];
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {       
            g[s[i] - 'a'].push_back(i);
        }
        int ans = INF;
        for (int i = 0; i < 26; i++)
        {
            if (g[i].size() < 2) continue;
            for (int j = 0; j < g[i].size() - 1; j++)
            {
                ans = min(ans,g[i][j + 1] - g[i][j]);
            }
        }
        if (ans == INF) ans = -1; 
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}

