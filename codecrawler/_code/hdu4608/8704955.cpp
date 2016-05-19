#include <iostream>
#include <cstring>
#include <cstdio>
#define base 10
using namespace std;
char s[100005];
int a[100005];
int len, x;

int main() {
    int T, n, m, i, j;
//    freopen("input.txt","r",stdin);
//    freopen("output2.txt","w",stdout);
    cin>>T;
    while(T--) {
        cin>>s;
        x = 0;
        i = 0;
        len = strlen(s);
        while(i<len) {
            x += (s[i]-'0')% base;
            i++;
        }
        for(i=0; i<len; i++) a[i] = s[len-i-1]-'0';
        if(x%10>=a[0]+1) {
            a[0] += 10 - x%10;
        } else {
            for(i=1; i<len; i++)
                if(a[i]<9) {
                    a[i]++;
                    x++;
                    for(j=0; j<i; j++) {x-=a[j];a[j] =0;}
                    if(x%10!=0) a[0] = base - x% base;
                    break;
                }
            if(i==len) {
                a[len] = 1;
                x++;
                for(j=0;j<len; j++){ x-=a[j]; a[j] =0;}
                len++;
                if(x%10!=0)  a[0] = base-x%base;
            }

        }
        for(i=len-1; i>=0; i--) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
