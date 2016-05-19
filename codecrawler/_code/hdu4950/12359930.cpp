#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<sstream>
#include<string>
#include<climits>
#include<set>
#include<bitset>
#include<cmath>
#include<deque>
#include<map>
#include<queue>
#include<stack>
#define LL long long
using namespace std;

int main()
{
    int cas=1;
    int n;
    LL h,a,b,k;
    while(cin>>h>>a>>b>>k)
    {


        if(h==0&&a==0&&b==0&&k==0) break;
        printf("Case #%d: ",cas++);
        if(a==b&&a>=h) {printf("YES\n");continue;}
        if(a==b&&a<h) {printf("NO\n");continue;}
        if(a<b&&a>=h) {printf("YES\n");continue;}
        if(a<b&&a<h){printf("NO\n");continue;}
        if(a>b){
            if(a>=h) {printf("YES\n");continue;}
            if((k-1)*b+h-k*a<1) printf("YES\n");
            else{
                if(k*a<=(k+1)*b) printf("NO\n");
                else printf("YES\n");
            }

        }

    }
    return 0;
}
