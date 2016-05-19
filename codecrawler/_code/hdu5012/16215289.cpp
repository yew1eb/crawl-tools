#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1000000;
bool vis[MAX];
int a;
int num[10];
pii que[MAX];
int front,tail;

void frac(int n)
{
   for(int i = 5; i >=0; --i){
        num[i] = n % 10;
        n /= 10;
    }
}
int get()
{
    int ans = 0;
    for(int i = 0; i < 6; ++i)
        ans = ans * 10 + num[i];
    return ans;
}

int tofront(int n)
{
    frac(n);
    int tmp = num[4];
    num[4] = num[0];
    num[0] = num[5];
    num[5] = num[1];
    num[1] = tmp;
    return get();
}
int toback(int n)
{
    frac(n);
    int tmp = num[4];
    num[4] = num[1];
    num[1] = num[5];
    num[5] = num[0];
    num[0] = tmp;
    return get();
}
int toleft(int n)
{
    frac(n);
    int tmp = num[0];
    num[0] = num[3];
    num[3] = num[1];
    num[1] = num[2];
    num[2] = tmp;
    return get();
}
int toright(int n)
{
    frac(n);
    int tmp = num[0];
    num[0] = num[2];
    num[2] = num[1];
    num[1] = num[3];
    num[3] = tmp;
    return get();
}

int bfs(int s, int t)
{
    memset(vis,0,sizeof(vis));
    front = tail = 0;
    que[tail++] = pii(s,0);
    vis[s] = true;
    while(front < tail){
        pii info = que[front++];
        int n = info.first, d = info.second;
        if(n == t) return d;
        int tmp = toleft(n);
        if(!vis[tmp]){
            vis[tmp] = true;
            que[tail++] = pii(tmp,d+1);
        }
        tmp = toright(n);
        if(!vis[tmp]){
            vis[tmp] = true;
            que[tail++] = pii(tmp,d+1);
        }
        tmp = tofront(n);
        if(!vis[tmp]){
            vis[tmp] = true;
            que[tail++] = pii(tmp,d+1);
        }
        tmp = toback(n);
        if(!vis[tmp]){
            vis[tmp] = true;
            que[tail++] = pii(tmp,d+1);
        }
    }
    return -1;
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&a) != EOF){
        int start = a;
        for(int i = 1; i < 6; ++i){
            scanf("%d",&a);
            start = 10 * start + a;
        }
        int end = 0;
        for(int i = 0; i < 6; ++i){
            scanf("%d",&a);
            end = end * 10 + a;
        }
        printf("%d\n",bfs(start,end));
    }
    return 0;
}
