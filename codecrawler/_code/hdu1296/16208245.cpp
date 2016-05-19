#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int const nMax = 10100;

#define sf scanf
#define pf printf
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

char s[nMax];
int x;

#define ll long long
ll go(int &i) {
    int a,b,c;
    a = 1;
    b = 0;
    if(s[i] == '-') a*=-1,i++;
    if(s[i] == '+') i++;
    while(s[i]>='0' && s[i]<='9') {
        b = b*10 + s[i]-'0';
        i ++;
    }
    if(b==0) b = 1;
    c = 0;
    if(s[i] == 'X') {
        i++;
        if(s[i]=='^') {
            i++;
            c = 0;
            while(s[i]>='0' && s[i]<='9') {
                c = c*10 + s[i] - '0';
                i ++;
            }
        }else {
            c = 1;
        }
    }
    ll ret = 0;
    ret = (ll)a*b;
    for(int i=0;i<c;i++) ret *= x;
    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    while(cin >> x >> s) {
        int i = 0;
        int l = strlen(s);
        ll ans = 0;
        while(i<l) {
            ans += go(i);
        }
        cout << ans << endl;
    }
    return 0;
}
