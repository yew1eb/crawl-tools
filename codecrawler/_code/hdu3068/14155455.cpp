// Manacher's algorithm: A linear time algorithm to find all palindrome substrings

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 110010;
//P[i]-1(0<=i<=2*(n-1)ä¸ºåå­ç¬¦ä¸²ä¸­åæä¸²çé¿åº¦
char Ma[MAXN*2];
int Mp[MAXN*2];

void Manacher(char s[], int len) {
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i=0; i<len; ++i) {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i=0; i<l; ++i) {
        Mp[i] = mx>i?min(Mp[2*id-i], mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i + Mp[i] > mx) {
            mx = i + Mp[i];
            id = i;
        }
    }
}

char s[MAXN];
int main()
{
    while(~scanf("%s", s) ){
        int n = strlen(s);
        Manacher(s, n);
        int ans = -1;
        for(int i=0; i<=2*(n-1); ++i) {
            ans = max(ans, Mp[i] - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
