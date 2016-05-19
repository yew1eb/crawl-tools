# include <iostream>
# include <cmath>
#include<cstdio>
using namespace std;
int main()
{
    int k;
    __int64 a,b,c,d;
    while(cin>>k)
    {
       cin>>a>>b;
        c=(__int64)(pow(2,k-1))-1;
        d=(-1)*(__int64)(pow(2,k));
        if((a<0&&b>0)||(a>0&&b<0))
        {
            cout<<"WaHaHa"<<endl;
            continue;
        }
        if(k==64)
        {
            if(a>0&&b>0&&c-a<b)
                printf("Yes\n");
            else if(a<0&&b<0&&d-a>b)
                printf("Yes\n");
            else printf("WaHaHa\n");
            continue;
        }
        if(a>0&&c-a<b)
            printf("Yes\n");
        else if (a<0&&d-a>=b)
            printf("Yes\n");
        else
            printf("WaHaHa\n");
    }
    return 0;
}
