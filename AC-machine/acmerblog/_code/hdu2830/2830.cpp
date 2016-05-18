#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1005
using namespace std;

int N, M, high[MAXN], temp[MAXN];

char G[MAXN][MAXN];

int deal()
{
    int Max = 0;
    memcpy(temp, high, sizeof (high));
    sort(temp+1, temp+M+1);
    for (int i = M;  i >= 1; --i) {
        if (temp[i]) {
            Max = max((M-i+1)*temp[i], Max);
        }
    }
    return Max;
}

int DP()
{
    int Max = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (G[i][j] == '1') { 
                ++high[j];
            } 
            else {
                high[j] = 0;
            } 
        }
        Max = max(Max, deal());
    }
    return Max;
}


int main()
{
    while (scanf("%d %d", &N, &M) == 2) {
        memset(high, 0, sizeof (high));
        for (int i = 1; i <= N; ++i) {
            scanf("%s", G[i]+1);
        }
        printf("%d\n", DP());
    } 
    return 0;
}