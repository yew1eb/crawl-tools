#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int ans;
    int i1, i2, i3, i4, i5;
    while(~scanf("%d",&n))
    {
        ans = 0;
        for(i1=0; i1<=n/50; ++i1)
        {
            for(i2=0; i2<=(n-i1*50)/25; ++i2)
            {
                for(i3=0; i3<=(n-i2*25 - i1*50)/10; ++i3)
                {
                    for(i4=0; i4<=(n-i3*10 - i2*25 - i1*50)/5; ++i4)
                    {
                        i5 = n - i4*5 - i3*10 - i2*25 - i1*50;
                        if(i5 + i4 + i3 + i2 + i1 <=100) ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
