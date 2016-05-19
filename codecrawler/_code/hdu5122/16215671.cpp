#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <deque>
#include <map>
#define cler(arr, val)    memset(arr, val, sizeof(arr))
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long  LL;
const int MAXN = 230+1;
const int MAXM = 140000;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int a[10000100];
int main()
{
#ifndef ONLINE_JUDGE
       freopen("in.txt", "r", stdin);
   //  freopen("out.txt", "w", stdout);
#endif
    int t,n,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int maxx=999999999,sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(maxx<a[i])
                sum++;
            else maxx=a[i];
        }
        printf("Case #%d: ",cas++);
        cout<<sum<<endl;
    }
}