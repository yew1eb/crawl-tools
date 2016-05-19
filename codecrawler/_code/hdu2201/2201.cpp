#include <cstdlib>
#include <cstdio>
#include <cstring> 
using namespace std;

int main()
{
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        printf("%.2lf\n", 1.0/N);
    }
    return 0;
}