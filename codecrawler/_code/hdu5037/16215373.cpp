#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>
#include<ctime>
using namespace std;
typedef long long i64;
#define SS(a)           scanf("%d",&a)
#define MM(name,what)   memset(name,what,sizeof(name))
#define MC(a,b)            memcpy(a,b,sizeof(b))
#define MAX(a,b)        ((a)>(b)?(a):(b))
#define MIN(a,b)        ((a)<(b)?(a):(b))
#define read            freopen("in.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-9;
const double pi = acos(-1.0);

int n, m, l;
vector<int>v;
int id;

int get(){
    return v[id++];
}

int start(){    

    int now = 0;
    int ans = 0;
    int temp;
    v.push_back(m);
    int pre = -l;
    for (int i = 0;i < v.size(); i++){
        int next = v[i];
        temp = next - now;
        int t2 = temp / (l + 1);
        pre += t2*(l + 1);
        ans += t2 * 2;
        if (next - pre>l){
            pre = now + t2*(l + 1);
            now = next;
            ans++;
        }
        else if (next - pre <= l){
            now = next;
        }
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    for (int tt = 1; tt <= T;tt++){
        cin >> n >> m >> l;
        v.clear();
        int now;
        for (int i = 1; i <= n; i++){
            //cin >> now;
            SS(now);
            v.push_back(now);
        }
        sort(v.begin(), v.end());
        cout << "Case #" << tt << ": ";
        cout << start() << endl;
    }
    return 0;
}