#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi ;
typedef vector<string> vs;
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define pb push_back
 
char buf[11111] ;
string tmp ;
struct Query{
    string word ;
    vs url ;
    int len ;
    void get(){
        scanf("%s",buf);
        word = buf ;
        gets(buf);
        istringstream sin( buf ) ;
        for(len = 0 ; sin >> tmp; len++) url.pb(tmp);
    }
}Q[111] ,F[111];

double getQF(int t){
    int n = Q[t].len ;
    int m = F[t].len ;
    int num = 0;

    double ans = 0;
    Rep(j,m)
        Rep(i,n)
            if(Q[t].url[i]==F[t].url[j]){
                num ++ ;
                ans += num*1.0/(j+1);
                break;
            }
    ans /= n ;
    return ans ;
}

int main()
{
    int T , cas = 1;
    scanf("%d",&T);
    while(T--){
        int n ;
        scanf("%d",&n);
        Rep(i,n) Q[i].get();
        Rep(i,n) F[i].get();

        double ans = 0;
        Rep(i,n)ans += getQF(i);
        ans /= n ;
        printf("Case #%d: %.6f\n",cas++,ans);
    }
    return 0;
}
