#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <climits>
#define eps 1e-8
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int maxn = 110;
int n,k;
int recursion(int n,int k)
{
    if(n==k) return k;       //è¾¹çæ¡ä»¶
    int x=recursion(n-n/k,k);//èå©èå¨ä¸ä¸ä¸ªå­åºåçç¼å·è®°ä¸ºx
    return (x-1)/(k-1)+x;    //é£ä¹è¿ä¸è½®çç¼å·y=y/k+x;
}
int main()
{
 //  freopen("input.txt","r",stdin);
   int T;cin>>T;
   while(T--){
    cin>>n>>k;
    cout<<recursion(n,k)<<endl;;
   }
   return 0;
}
