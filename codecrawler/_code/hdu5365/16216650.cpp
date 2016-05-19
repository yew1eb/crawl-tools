#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<map>
#include<set>
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define sfs(a) scanf("%s",a)
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfs(a) printf("%s\n",a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,num) scanf("%d%d%d",&a,&b,&num)
#define for1(i,a,b) for(int i=(a);i<b;i++)
#define for2(i,a,b) for(int i=(a);i<=b;i++)
#define for3(i,a,b)for(int i=(b);i>=a;i--)
#define MEM1(a) memset(a,0,sizeof(a))
#define MEM2(a) memset(a,-1,sizeof(a))
#define ll __int64
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
int n,m;
#define M 110
#define N 10010
#define Mod 1000000007
#define p(x,y) make_pair(x,y)
struct Node{
    int x,y;
}f[25];
int getDis(Node p1,Node p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
bool check(int a,int b,int c,int d){
    vector<int> v;
    v.push_back(getDis(f[a],f[b]));
    v.push_back(getDis(f[a],f[c]));
    v.push_back(getDis(f[a],f[d]));
    v.push_back(getDis(f[b],f[c]));
    v.push_back(getDis(f[b],f[d]));
    v.push_back(getDis(f[c],f[d]));
    sort(v.begin(),v.end());
    if(v[0]==v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == 2*v[0] && v[5] == 2*v[0])
        return true;
    return false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
    while(sf(n)!=EOF){
        for(int i=0;i<n;i++)
            sfd(f[i].x,f[i].y);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int s=k+1;s<n;s++){
                        if(check(i,j,k,s))
                            ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
