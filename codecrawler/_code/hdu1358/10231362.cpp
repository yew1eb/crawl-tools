/************************************************
 * Author: yew1eb
 * Created Time: 2014/3/6 15:31:36
 * File Name: hdu1358.cpp
 *************************************************/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
const int maxn = 1000000 + 10;

char P[maxn];
int f[maxn];


void getFail1(char* P, int* f)
{
    int m = strlen(P);
    f[0] = f[1] = 0;
    for(int i=1; i<m; ++i)
    {
        int j = f[i];
        while(j && P[i] != P[j] ) j = f[j];
        f[i+1] = (P[i] == P[j]) ? j+1 : 0;
    }
}

void getFail2(char* P, int* f)
{
    int i, j;
    int m = strlen(P);
    j = f[0] = -1;
    i = 0;
    while(i<m)
    {
        while(-1!=j && P[i] != P[j] ) j = f[j];
        f[++i] = ++j;
    }
}

int main()
{
    int n, cas  = 0;
    while(scanf("%d",&n),n)
    {
        scanf("%s",P);
        //getFail1(P, f);
        getFail2(P, f);
        //getFail3(P, f);
        printf ("Test case #%d\n",++cas);
        for(int i =2; i<=n; ++i)
            if(f[i]>0&&i %(i-f[i]) == 0)
                printf("%d %d\n",i, i/(i-f[i]) );
        printf("\n");
    }
    return 0;
}
