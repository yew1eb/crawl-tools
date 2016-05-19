#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int T, n, m;

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < 12;i++)
            for (int j = 0; j < 60;j++)
                for (int k = 0; k < 6; k++)
                {
                    int a = i * 3600 + j * 60 + k * 10, b = j * 60 + k * 10;
                    int c = max(a * 100 - b * 1200, b * 1200 - a * 100);
                    c = min(4320000 - c, c);
                    if (c == n) printf("%02d:%02d:%02d\n", i, j, k * 10);
                }
    }
    return 0;
}