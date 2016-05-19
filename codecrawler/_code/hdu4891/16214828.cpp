#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int n, cnt1, cnt2, flag;
long long ans;
string s, t;

int main() {
    while (scanf("%d", &n) != EOF) {
        getchar();
        s.clear();
        for (int i = 0; i < n; i++) {
            getline(std::cin, t);
            s += t;
        }
        ans = cnt1 = flag = 1;
        cnt2 = 2;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{') 
                flag = 0;
            else if (s[i] == '}') {
                flag = 1; 
                ans *= cnt1; 
                if (ans > MAXN)
                    break;
                cnt1 = 1;
            }
            else if (s[i] == '$') { 
                flag = -flag; 
            }
            if (flag == 0) {
                if (s[i] == '|') 
                    cnt1++; 
            }
            if (flag == -1) {
                if (s[i] == ' ' && s[i + 1] == ' ')            
                    cnt2++;    
                else if (s[i] == ' '){
                    ans *= cnt2; 
                    cnt2 = 2;
                }
                if (ans > MAXN)
                    break;
            }
        } 

        if (ans > MAXN)
            printf("doge\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}
