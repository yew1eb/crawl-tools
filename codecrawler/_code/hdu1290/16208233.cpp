#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a, ans;
    while(scanf("%d", &a) != EOF) {
        ans = (a*a*a+5*a+6)/6;
        printf("%d\n", ans);
    }
    return 0;
}
