
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
using namespace std;
int main() {
    int n;
    while(cin>>n&&n) {
        string s; cin>>s;
        string f[1000];
        int a=0,j;
        for(j=0; a+n<=s.size(); j++,a+=n) {
            f[j].assign(s,a,n);
            if(j%2)reverse(f[j].begin(),f[j].end());
        }
        if(a<s.size()-1){
            int l=s.size()-a;
            f[j].assign(s,a,l);
            ++j;
        }
        for(int i=0,k;i<n;++i)
            for(k=0;k<j;k++)
                cout<<f[k][i];
        cout<<endl;
    }
    return 0;
}


