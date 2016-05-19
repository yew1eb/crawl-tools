#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-10
///#define M 1000100
#define LL __int64
///#define LL long long
///#define INF 0x7ffffff
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
#define zero(x) ((fabs(x)<eps)?0:x)

const int maxn = 2010;

using namespace std;

struct node
{
    int x, y;
} f[maxn];

int main()
{
    int T;
    cin >>T;
    int Case = 1;
    while(T--)
    {
        int n, m;
        cin >>n>>m;
        int x, y;
        int d, b;
        for(int i = 0; i <= n; i++) f[i].x = f[i].y = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d %d",&x, &y, &d, &b);
            f[x].y += d;
            f[y].x += (d+b);
        }
        int flag = 0;
        for(int i = 1; i <= n; i++)
        {
            if(f[i].x < f[i].y)
            {
                flag = 1;
                break;
            }
        }
        cout<<"Case #"<<Case++<<": ";
        if(flag) cout<<"unhappy"<<endl;
        else cout<<"happy"<<endl;
    }
    return 0;
}