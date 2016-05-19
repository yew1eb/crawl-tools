#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string s[102];
int n;
bool check(string sub) {
    int i, j;
    string tmp;
    for(i=0; i<sub.size(); i++)
        tmp +=sub[ sub.size()-1-i];
    for(i=0; i<n; i++)
        if(s[i].find(sub)==s[i].npos && s[i].find(tmp)==s[i].npos)
            return false;
    return true;
}
void solve(int t,int p) {
    string sub;
    int i, j, k;
    int ans =0;
    for(i=0; i<t; i++)
        for(j=t-1; j>=i; j--) {
            if(j-i+1<ans) continue;
            sub = s[p].substr(i,j-i+1);
            if(check(sub)) {
                if(j-i+1>ans) ans = j-i+1;
            }
        }
    cout<<ans<<endl;
}
int main() {
    int T,i,t,sub_i, j;
    cin>>T;
    while(T--) {
        cin>>n;
        t = 200;
        for(i=0; i<n; i++) {
            cin>>s[i];
            if(s[i].size()<t) {
                t =s[i].size();
                sub_i = i;
            }
        }
        solve(t, sub_i);
    }
    return 0;
}
