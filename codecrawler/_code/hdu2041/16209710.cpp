#include <cstdio>
#include <cmath>
int step[50];
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        step[1] = 1;
        step[2] = 2;
        for(int i=3; i<m; i++)
        {
            step[i] = step[i-1] + step[i-2];
        }
        printf("%d\n",step[m-1]);
    }
    return 0;
}
