#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef double DB;
typedef unsigned uint;
typedef unsigned long long uLL;

/** Constant List .. **/ //{

const int MOD = int(1e9)+7;
const int INF = 0x3f3f3f3f;
const LL INFF = 0x3f3f3f3f3f3f3f3fLL;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0); //M_PI;
int a[100001];

int main()
{
    #ifdef ZH
    freopen("in.txt","r",stdin);
    #endif
    int n;
    int t = 1;
    while(~scanf("%d",&n) && n)
    {
        int sum = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        int aver = sum / n;
        sort(a , a + n);
        int cnt = 0;
        for(int i = n - 1 ; i >= 0 ; i --)
        {
            if(a[i] == aver)
                break;
            if(a[i] > aver)
               cnt += a[i] - aver;
        }
        printf("Set #%d\n",t ++);
        printf("The minimum number of moves is %d.\n\n",cnt);
    }
}
