#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define INF 0x7fffffff
#define LL long long
#define LD long double
#define PII pair<int,int>
#define x first
#define y second
#define pb push_back
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

#define N 100010
int last[N],link[N],next[N],ord[N];

struct heap {

 vector<int> h,pos;
 int n;

 heap() : h(N),pos(N),n(0) {}

 inline int cmp(int p,int q) {
 p=h[p],q=h[q];
 return next[p]>next[q];
 }

 void swap(int p,int q) {
 if (p==q) return;
 int &pos1=pos[h[p]],
 &pos2=pos[h[q]];
 std::swap(h[p],h[q]);
 std::swap(pos1,pos2);
 }

 int goup(int x) {
 while (x>1 && cmp(x,x/2)) {
 swap(x,x/2);
 x/=2;
 }
 return x;
 }

 void godown(int x) {
 loop:
 if (x*2>n) return;
 int y=x*2;
 if (y+1<=n && cmp(y+1,y)) y++;
 if (cmp(y,x)) {
 swap(x,y);
 x=y;
 } else return;
 goto loop;
 }

 void deln() {
 pos[h[n]]=0;
 h[n]=0;
 n--;
 }

 void pop() {
 swap(1,n);
 deln();
 godown(1);
 }

 void pop(int x) {
 x=pos[x];
 swap(x,n);
 deln();
 x=goup(x);
 godown(x);
 }

 void push(int x) {
 n++;
 h[n]=x;
 pos[x]=n;
 goup(n);
 }

 int top() {return h[1];}
 int size() {return n;}
 int find(int x) {return pos[x]>0;}
};

int main() {
 //freopen("data.txt","r",stdin);
 int c,n,b;
 while (~scanf("%d%d%d",&c,&n,&b)) {
 fill(last,last+N,0);
 fill(link,link+N,INF);
 for (int i=1,k;i<=b;i++) {
 scanf("%d",ord+i),ord[i]++;
 if (last[ord[i]]) {
 link[last[ord[i]]]=i;
 }
 last[ord[i]]=i;
 }

 heap h;
 int ans=0;
 for (int i=1;i<=b;i++) {
 if (!h.find(ord[i])) {
 if (h.size()==c) h.pop();
 ans++;
 } else {
 h.pop(ord[i]);
 }
 next[ord[i]]=link[i];
 h.push(ord[i]);

 //printf("i=%d push(%d,%d) |h|=%d ans=%d\n",i,ord[i]-1,next[ord[i]],sz(h),ans);
 }
 printf("%d\n",ans);
 }
 return 0;
}