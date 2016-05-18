#include <stdio.h>

int s(int i) {
    int n = 1;
    while(i > 1) {
        if (i%2 == 0)
            i /= 2;
        else
            i = 3*i+1;
        n++;
    }
    return n;
}


int main() {
    int a, b;
    int n, m;
        
    while(scanf("%d %d", &n, &m) != EOF) {
        a = n;
        b = m;
        if (a > b) {
            int t=a;
            a=b;
            b=t;
        }
        int sum = 0;
        int i, r;
        for (i = a; i <= b; i++) {
            r = s(i);
            if (r > sum)
                sum = r;
        }
        
        printf("%d %d %d\n", n, m, sum);

                                
    }
    return 0;
}