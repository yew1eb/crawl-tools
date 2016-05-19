#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_ = 110010;

char str[MAX_*2], str1[MAX_];
int p[MAX_*2];

int main() {
    int mx,id;
    while(~scanf("%s",str1)) {
        int t = 1,len = strlen(str1);
        str[0] = '$';
        for(int i = 0; i < len; ) {
            if(t & 1)
                str[t++] = '#';
            else {
                str[t++] = str1[i++];
            }
        }
        str[t++] = '#';
        str[t] = '\0';
        mx = 0;
        for(int i = 1; i < t; i++) {
            if(i < mx) {
                p[i] = min(p[id*2-i],mx-i);
            } else p[i] = 1;
            for(; str[p[i]+i] == str[i-p[i]]; p[i]++);

            if(p[i] + i > mx) {
                mx = p[i] + i;
                id = i;
            }
        }
        int ans = -1;
        for(int i = 1; i < t; i++){
            if(p[i] - 1 > ans){
                ans = p[i] - 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
