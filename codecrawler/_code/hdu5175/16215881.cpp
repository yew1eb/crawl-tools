#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll n;
vector<ll> vl;
int main()
{
    int Case=1;
    while(scanf("%I64d",&n)!=EOF){
        vl.clear();
        printf("Case #%d:\n", Case++);
        for(ll c=1;c*c<=n;++c){
            if(n%c==0){
                ll b=n-c;
                if( b>0&&(n^b)==c){
                    vl.push_back(b);
                }
                if(n/c!=c){
                    b=n-n/c;
                    if(b>0&&b<=n&&((n^b)==(n/c))) vl.push_back(b);
                }
            }
        }
        sort(vl.begin(),vl.end());
        printf("%d\n",vl.size());
        for(int i=0;i<vl.size();++i){
            printf("%I64d",vl[i]);
            if(i!=vl.size()-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
