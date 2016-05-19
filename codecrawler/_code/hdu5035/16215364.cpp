#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    int T,N,c;
    double sum,a;
    scanf("%d",&T);
    for(int w = 1; w <= T; w++)
    {
        sum = 0.0;
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
        {
            scanf("%lf",&a);
            sum += a;
        }
        for(int j = 0; j < N; j++)
        scanf("%d",&c);
        printf("Case #%d: %.6lf\n",w,(N+1.0)/sum);
    }
    return 0;
}