#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>

using namespace std;

int main()
{
    int a , b , c , d ;
    int temp ;
    int Case ;
    cin >> Case ;
    while( Case-- )
    {
        temp = 0 ;
        while( cin >> a >> b >> c >> d )
        {
            if( a == - 1 && b == -1 && c == -1 && d == -1 )
                break;
            int n = ( 5544 * a + 14421 * b + 1288 * c  ) % 21252 ;
            int ans = n > d ? n - d : 21252 + n - d ;
            cout << "Case " << ++temp << ": the next triple peak occurs in " << ans << " days." << endl;
        }
        if( Case != 0 )
            cout << endl ;
    }
    return 0 ;
}