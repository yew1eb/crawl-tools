#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <queue>
#define two(x) (1 << (x))
using namespace std;

const int N = 105;

int n, K;

struct State {
    int x, y;
    int key;
    int monster;
    int code;
    void encode()
    {
        int res = x;
        res = res * n + y;
        res = res * (K + 1) + key;
        res = res * 32 + monster;
        code = res;
    }
};
bool operator<(const State &lhs, const State &rhs)
{ return false; }
priority_queue<pair<int, State> > H;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dist[N * N * 11 * 33];
char a[N][N];
int monster_id[N][N];

void work()
{
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    int cmonster = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (a[i][j] == 'S') 
            monster_id[i][j] = cmonster++;
        else
            monster_id[i][j] = -1;
    }
    assert(cmonster <= 5);

    State start;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (a[i][j] == 'K') {
        start.x = i;
        start.y = j;
    }
    start.monster = 0;
    start.key = 0;
    start.encode();

    memset(dist, 0x3f, sizeof(dist));
    dist[start.code] = 0;

    while (!H.empty()) H.pop();
    H.push(make_pair(0, start));
    while (!H.empty()) {
        pair<int, State> p = H.top();
        int d = -p.first;
        State state = p.second;
        H.pop();
        if (d != dist[state.code]) continue;
        if (a[state.x][state.y] == 'T' && state.key == K) {
            printf("%d\n", d);
            return;
        }
        State state2;
        for (int k = 0; k < 4; ++k) {
            state2.x = state.x + dx[k];
            state2.y = state.y + dy[k];
            int d2;
            if (state2.x < 0 || state2.x >= n || state2.y < 0 || state2.y >= n) continue;
            if (a[state2.x][state2.y] == '#') continue;
            if (monster_id[state2.x][state2.y] >= 0 && (state.monster & two(monster_id[state2.x][state2.y])) == 0) {
                state2.monster = state.monster | two(monster_id[state2.x][state2.y]);
                d2 = dist[state.code] + 2;
            } else {
                state2.monster = state.monster;
                d2 = dist[state.code] + 1;
            }
            if (a[state2.x][state2.y] >= '1' && a[state2.x][state2.y] <= '9' && a[state2.x][state2.y] - '0' == state.key + 1) {
                state2.key = state.key + 1;
            } else {
                state2.key = state.key;
            }
            state2.encode();
            if (d2 < dist[state2.code]) {
                dist[state2.code] = d2;
                H.push(make_pair(-d2, state2));
            }
        }
    }
    printf("impossible\n");
}

int main()
{
    while (scanf("%d%d", &n, &K), n + K) work();
}