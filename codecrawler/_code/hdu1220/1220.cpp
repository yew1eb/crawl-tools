//数学，没化简，直接用
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int s = n * n * n;
        int ans = (s-4)*4 + 6*(n-2)*(s-5) + 3*(n-2)*(n-2)*(s-6) + (n-2)*(n-2)*(n-2)*(s-7)/2;
        printf ("%d\n", ans);
    }
    return 0;
}