/*
ID: yueqiq
PROG: numtri
LANG: C++
*/
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#define Si set<int>
#define LL long long
#define pb push_back
#define PS printf(" ")
#define Vi vector<int>
#define LN printf("\n")
#define lson l,m,rt << 1
#define rson m+1,r,rt<<1|1
#define SD(a) scanf("%d",&a)
#define PD(a) printf("%d",a)
#define SET(a,b) memset(a,b,sizeof(a))
#define FF(i,a) for(int i(0);i<(a);i++)
#define FD(i,a) for(int i(a);i>=(1);i--)
#define FOR(i,a,b) for(int i(a);i<=(b);i++)
#define FOD(i,a,b) for(int i(a);i>=(b);i--)
#define readf freopen("input.txt","r",stdin)
#define writef freopen("output.txt","w",stdout)
const int maxn = 10001;
const int INF = 1111;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const double pi = acos(-1.0);
const double eps= 1e-7;
using namespace std;
int N,K;
double len[maxn];
bool judge(double k){
    int num=0;
    FOR(i,1,N){
        int t=(int)(len[i]/k);
        num+=t;
        if(num > K) return false;//kè¿å°
    }
    if(num < K) return true;
    else return false; //å³ä½¿num==K ä¹æ¯å¤ªå°
}
int main()
{
    while(~scanf("%d%d",&N,&K),K+N){
        double l=0,r=0,mid,sum;
        FOR(i,1,N){
            scanf("%lf",&len[i]);
            sum+=len[i];
        }
        //printf("%lf  %lf\n",l,r);
        r=sum/K;
        while(l+eps<r){
            mid=(l+r)/2.0;
            //printf("mid :%lf   %s\n",mid,judge(mid)?"big":"small");
            if(judge(mid)) r=mid;
            else l=mid;
        }
        printf("%.2lf\n",(l+r)/2.0);
    }
    return 0;
}


