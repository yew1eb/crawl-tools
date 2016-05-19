#include <stdio.h>

int main ( ) {
    int ct, t;
    double sum;
    printf ( "n e\n- " );
    for ( int i = 1; i <= 11; ++i )
        printf ( "-" );
    printf ( "\n" );                                                              
    ct = 0;
    do {
        sum = 1.0, t = 1;
        for ( int i = 1; i <= ct; ++i ) {
            t = t * i;
            sum += ( double )1 / t;
        }
        if ( ct > 2 ) printf ( "%d %.9lf\n", ct, sum );
        else if ( ct == 2 ) printf ( "%d %.1lf\n", ct, sum );
        else printf ( "%d %.0lf\n", ct, sum );
        ct++;
    }while ( ct < 10 );
}
