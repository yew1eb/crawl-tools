/*
 * Author: yew1eb
 * Created Time:  2014-11-17 09:07:34
 * File Name: G:\ACM\code\hdu4546.cpp
 */
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int inf = 0x7fffffff;
const ll  INF = 1e18;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int maxn = 20000;
int f[maxn];
struct node{
    int sum, idx;
    node(int _s=0, int _i=0):sum(_s),idx(_i){}
    bool operator <(const node &rhs)const{
    return sum + f[idx] > rhs.sum + f[rhs.idx]; //±£Ö¤µÚi´Î£¬¼ÓÈë¶ÓÁÐµÄÊÇµÚiÐ¡¡£
    }
};

priority_queue<node> pq;

int main() {
    int T, n, m;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca){
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; ++i) scanf("%d", &f[i]);
        sort(f, f+n);
        int ans = 0;
        while(!pq.empty())pq.pop();
        node tmp = node(0, 0);
        pq.push(tmp);
        while(m--){
            tmp = pq.top();
            ans = tmp.sum + f[tmp.idx];
            tmp.idx += 1;
            pq.pop();
            if(tmp.idx<n){
                pq.push(tmp);
                pq.push(node(ans, tmp.idx));
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}

