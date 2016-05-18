#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const __int64 INF = 100000000000LL;

struct Node
{
    __int64 m, x;
    Node()
    {
        m = 0;
        x = 0;
    }
};

__int64 ten[10];

void init()
{
    __int64 num = 1;
    for(int i=0;i<10;++i)
    {
        ten[i] = num;
        num *= 10;
    }
}

int getLength(__int64 x)
{
    if(x == 0) return 1;
    int len = 0;
    while(x > 0)
    {
        x /= 10;
        ++ len;
    }
    return len;
}

int main()
{
    int caseNumber;
    __int64 n;
    init();
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        scanf("%I64d", &n);
        int len = getLength(n);
        queue<Node> q;
        q.push(Node());
        while(!q.empty())
        {
            Node u = q.front();
            if(u.x == len) break;
            for(int i=0;i<10;++i)
            {
                Node v;
                v.m = u.m + ten[u.x] * i;
                v.x = u.x + 1;
                if((v.m * v.m) % ten[v.x] == n % ten[v.x]) q.push(v);
            }
            q.pop();
        }
        __int64 ans = INF;
        while(!q.empty())
        {
            Node node = q.front();
            if(ans > node.m)
                ans = node.m;
            q.pop();
        }
        if(ans == INF) printf("None\n");
        else           printf("%I64d\n", ans);
    }
    return 0;
}