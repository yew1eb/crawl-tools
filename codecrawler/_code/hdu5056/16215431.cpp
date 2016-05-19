#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define INF 1e9
#define maxn 100010
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define mset(x) memset(x,0,sizeof(x))
#define idx(x) x-'a'
typedef __int64 ll;

int t, k;
char s[maxn];
int    cc[27];

int main(){
//    freopen("a.txt","r",stdin);
//    freopen(".out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%s", s);
        cin>>k;

        mset(cc);
        int len = strlen(s);
        ll ans=0;

        for(int j=0, i=0; j<len; j++){
            cc[idx(s[j])]++;
            
            while(i<j && cc[idx(s[j])]>k){
                cc[idx(s[i])]--; 
                i++;
            }

            ans = ans + j-i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
