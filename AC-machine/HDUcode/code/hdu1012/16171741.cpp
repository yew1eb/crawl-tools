#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    double e;
    int i, tmp;
    e = 1;
    tmp = 1;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    for(i = 1; i < 10; i++) {
        tmp *= i;
        e += 1.0/tmp;
        if(i>=3) printf("%d %.9lf\n", i, e);
        else if(2 == i) printf("%d %.1lf\n", i, e);
        else printf("%d %.0lf\n",i, e);
    }
    return 0;
}
