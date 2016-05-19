#include <iostream>
using namespace std;

int main()
{
    int i,sum1,sum2,sum3,n,r;

    for(i = 1000; i<9999; i++)
    {
        n = i;
        sum1 = sum2 = sum3 = 0;
        while(n)
        {
            r=n%10;
            sum1+=r;
            n/=10;
        }
        n = i;
        while(n)
        {
            r=n%12;
            sum2+=r;
            n/=12;
        }
        if(sum1 == sum2)
        {
            n = i;
            while(n)
            {
                r=n%16;
                sum3+=r;
                n/=16;
            }
            if(sum3 == sum1)
            cout << i << endl;
        }
    }


    return 0;
}
