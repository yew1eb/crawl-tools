#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <assert.h>

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define eps 1e-8
#define M_PI 3.141592653589793

typedef long long ll;
const ll mod=1000000007;
const int inf=0x7fffffff;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

using namespace std;
map<string,map<string,int> >dict;
int main()
{
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--){
       dict.clear();
       int n;cin>>n;
       for(int i=0;i<n;i++){
         string a,b;int v;
         cin>>a>>b>>v;
         dict[b][a]+=v;
       }
       for(map<string,map<string,int> >::iterator it=dict.begin();it!=dict.end();it++){
           cout<<it->first<<endl;
           for(map<string,int>::iterator iter=it->second.begin();iter!=it->second.end();iter++){
              cout<<"   |----"<<iter->first<<"("<<iter->second<<")"<<endl;
           }
       }
       if(T) cout<<endl;
    }
}
