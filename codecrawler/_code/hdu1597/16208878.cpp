#include <iostream>
#include <math.h>
using namespace std;
#define sum(n)  ((n&1)?(n*(n+1)/2):(n/2*(n+1)))
__int64 n;
__int64 result;

void get_digit()
{
    //é¦åè·å¾åºé´
    __int64 low = (__int64)sqrt((double)n*2.0);
    __int64 first;
    for(__int64 i = low ; ;i++)
    {
        if(sum(i) >= n )
        {
            first = i; 
            break;
        }
    }
    __int64 second = n - sum((first -1));
    result = second%9?second%9:9;
}

int main()
{
    __int64 k;
    cin >> k;
    {
        while(k--)
        {
            cin >> n ;
            get_digit();
            cout << result <<endl;
        }
    }
    return 0;
}