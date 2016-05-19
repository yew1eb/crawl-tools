#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int r[] = { 15 , 7 , 4 , 2 , 1 };

int main ( )
{
    int n;
    while ( ~scanf  ( "%d" , &n ) )
    {
        bool flag = false;
        for ( int i = 0 ; i < 5 ; i++ )
        {
            if ( n - r[i] < 1 ) continue;
            if ( flag ) printf ( " " );
            printf ( "%d" , n - r[i] );
            flag = true;
        }
        puts ( "" );
    }
}