#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
#include"queue"
#define N 31
typedef __int64 int64;
using namespace std;
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",(int)pow(2,n)-1);
    }
    return 0;
}

    