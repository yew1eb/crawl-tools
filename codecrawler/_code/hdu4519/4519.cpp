#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,m;
        scanf("%d%d%d",&n,&k,&m);
        if(n<m)
        {
            printf("%d\n",k);
            continue;
        }
        if(n*k%m)
            printf("%d\n",n*k/m+1);
        else
            printf("%d\n",n*k/m);
    }
    return 0;
}
