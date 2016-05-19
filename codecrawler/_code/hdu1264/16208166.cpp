// File Name: hdu1264.cpp                                                                                                                                                                
// Author: Toy
// Created Time: 2013å¹´03æ11æ¥ ææä¸ 18æ¶03å16ç§

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main ( ) {
    int x1, x2, y1, y2, ans, k;
    bool cmp[101][101];
    memset ( cmp, 0, sizeof ( cmp ) );
    while ( scanf ( "%d%d%d%d", &x1, &y1, &x2, &y2 ) != EOF ) {
        if ( x1 == x2 && x2 == y1 && y1 == y2 && ( x1 == -1 || x2 == -2 ) ) {
            ans = 0;
            for ( int i = 0; i < 101; ++i )
                for ( int j = 0; j < 101; ++j )
                    if ( cmp[i][j] ) ans++;
            printf ( "%d\n", ans );
            memset ( cmp, 0, sizeof ( cmp ) );
        }
        else {
            if ( x1 > x2 ) {
                k = x2;
                x2 = x1;
                x1 = k;
            }
            if ( y1 > y2 ) {
                k = y2;
                y2 = y1;
                y1 = k;
            }
            for ( int i = x1; i < x2; ++i )
                for ( int j = y1; j < y2; ++j )
                    cmp[i][j] = 1;
        }
    }
    return 0;
}  