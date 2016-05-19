#include <iostream>
#include <iomanip>

#include <string.h>
using namespace std;
int main()
{
    int n,sum;
    int i;
    char dey[8]="PERFECT",day[9]="ABUNDANT",xy[10]="DEFICIENT";
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n) && n)
    {
        

        sum=0;
        for(i=1;i<n;++i)
        {
            if(sum>n)
            {
                cout<<setw(5)<<n<<"  "<<day<<endl;
                break;
            }
            if(n%i==0)
                sum+=i;
        }
        if(sum==n)
            cout<<setw(5)<<n<<"  "<<dey<<endl;
        else if(sum<n)
            cout<<setw(5)<<n<<"  "<<xy<<endl;
    }
    printf("END OF OUTPUT\n");
    return 0;
}