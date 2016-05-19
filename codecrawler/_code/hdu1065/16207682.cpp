#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>

using namespace std;
#define PI 3.1415926
int main()
{
    int Case , s ;
    double x , y , r_2 ;
    cin >> Case ;
    int temp = 0 ;
    while( Case-- )
    {
        cin >> x >> y ;
        r_2= x * x + y * y  ;
        s = ( int )(PI * r_2 / 100 )+ 1 ;
        printf( "Property %d: This property will begin eroding in year %d.\n" , ++temp , s ) ;
    }
    cout << "END OF OUTPUT." << endl ;
    return 0 ; 
}