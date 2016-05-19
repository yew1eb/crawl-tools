#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
#ifdef test
    freopen("input.txt", "r", stdin);
#endif
    int t, num;
    scanf("%d",&t);
    while(t--)
    {
        int ans = 0, flag = 0, m;
        scanf("%d", &num);
        for(int i=0; i<num; i++)
        {
            scanf("%d",&m);
            ans ^= m;
            if(m != 1)
                flag=1;
        }
        if(flag)
        {
            if(ans == 0)
                printf("Brother\n");
            else
                printf("John\n");
        }
        else
        {
            if(num%2 != 0)
                printf("Brother\n");
            else
                printf("John\n");
        }
    }
    return 0;
}
