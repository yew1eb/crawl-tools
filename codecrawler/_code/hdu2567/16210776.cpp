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

#pragma comment(linker, "/STACK:102400000,102400000")

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
string s , t;
int main()
{
    #ifdef DoubleQ
    freopen("in.txt","r",stdin);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    while(cin >> T)
    {
        while(T--)
        {
            s = "";
            t = "";
            cin >> s >> t;
            int len = s.length();
            int key = len / 2;
            for(int i = 0 ; i < key ; i ++)
                cout << s[i];
            cout << t ;
            for(int i = key ; i < len ; i ++)
                cout << s[i];
            cout << endl;
        }
    }
}
