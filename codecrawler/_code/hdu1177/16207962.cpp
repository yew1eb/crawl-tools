#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 150;
struct ss
{
    bool wo;
    int solve;
    int h;
    int m;
    int s;
};
bool cmp(ss a, ss b)
{
    if(a.solve > b.solve) return true;
    else if(a.solve == b.solve && a.h < b.h) return true;
    else if(a.solve == b.solve && a.h == b.h && a.m < b.m) return true;
    else if(a.solve == b.solve && a.h == b.h && a.m == b.m && a.s < b.s) return true;
    else return false;
}
int N, G, S, C, M;
int main()
{
    while(scanf("%d %d %d %d %d", &N, &G, &S, &C, &M) && (N+G+S+C+M))
    {
        ss f[maxn];
        for(int i = 0;i < N; ++i) f[i].wo = false;
        for(int i = 0;i < N; ++i)
        {
            //f[i].wo == false;
            scanf("%d %d:%d:%d", &f[i].solve, &f[i].h, &f[i].m, &f[i].s);
            if(i == M-1) f[i].wo = true;
        }
        sort(f, f+N, cmp);
        for(int i = 0;i < N; ++i)
        {
            if(f[i].wo != true) continue;
            if(i < G) cout <<"Accepted today? I've got a golden medal :)\n";
            else if(i < G+S) cout <<"Accepted today? I've got a silver medal :)\n";
            else if(i < G+S+C) cout<<"Accepted today? I've got a copper medal :)\n";
            else cout <<"Accepted today? I've got an honor mentioned :)\n";
            break;
        }
    }
    return 0;
}
