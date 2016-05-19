#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define rt return
#define sf scanf
#define pf printf
#define si(n) sf("%d",&n)
#define pi(n) pf("%d\n",n)
#define REP0(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,s,n) for(int i=s;i<=(n);i++)
#define db double
#define LL long long
#define op operator
#define INF 0x3fffffff
#define eps 1e-8
#define PI acos(-1)
#define maxn 1010
using namespace std;
int sig(db x){rt (x>eps)-(x<-eps);}
struct node{
    db x,y,ang;
    node(){}
    node(db a,db b){x=a,y=b;}
    void in(){sf("%lf%lf",&x,&y);}
    void out(){pf("%lf %lf\n",x,y);}
    node op + (node a) {rt node(x+a.x,y+a.y);}
    node op - (node a) {rt node(x-a.x,y-a.y);}
    db op * (node a) {rt x*a.x+y*a.y;}
    db op ^ (node a) {rt x*a.y-a.x*y;}
    db dis(node a) {rt sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));}
    friend bool op <(node a,node b) {
        if(a.y==b.y)rt a.x<b.x;
        rt a.y<b.y;
    }
    db cross(node a,node b) {return (a-*this)^(b-*this);}
    bool on_seg(node a,node b){
        return ((a-*this)^(b-*this))==0 && ((a-*this)*(b-*this))<=0 ;}
}p[maxn],s[maxn];
int n;
bool cmp(node a,node b){
    rt a.ang<b.ang;
}
int main(){
    #ifdef LJ
    freopen("in.txt","r",stdin);
    #endif
    int T;si(T);
    while(T--){
        si(n);
        for(int i=0;i<n;i++)p[i].in();
        int ans=0;
        sort(p,p+n);
//        for(int i=0;i<n;i++)p[i].out();
        for(int i=0;i<=n-3;i++){//ä½ä¸n-2 n-1ï¼å ä¸ºå©ä¸ä¸¤ä¸ªæ¯ä¸è½ææ3ç¹ä¸çº¿ç
            int cnt=0;
            for(int j=i+1;j<n;j++){
                s[cnt]=p[j]-p[i];
                s[cnt].ang=atan2(s[cnt].y,s[cnt].x);
                cnt++;
            }
            sort(s,s+cnt,cmp);
//            for(int j=0;j<cnt;j++)s[j].out();
            int j=0;
            while(j<cnt){
                int tmp=2;
                while(j<cnt-1&&sig(s[j]^s[j+1])==0){
                    tmp++;
                    j++;
                }
                j++;
                ans+=(tmp-1)*(tmp-2)/2;
//                pf("%d %d\n",tmp,ans);
            }
        }
        pi(ans);
    }
    rt 0;
}
