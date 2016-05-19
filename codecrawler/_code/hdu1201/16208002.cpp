#include <stdio.h>                                                                                                                              

int cmp ( int year ) {
    if ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) 
        return 1;
    else 
        return 0;
}

int main ( ) {
    int year, month, day, sum, ct;
    scanf ( "%d", &ct );
    while ( ct-- ) {
        scanf ( "%d-%d-%d", &year, &month, &day );
        if ( month == 2 && day == 29 ) {
            printf ( "-1\n" );
            continue;
        }
        sum = 0;
        for ( int i = 1; i <= 18; ++i ) {
            if ( cmp ( year ) && month <= 2 || cmp ( year + 1 ) && month > 2 ) 
                sum += 366;
            else 
                sum += 365;
            year++;
        }
        printf ( "%d\n", sum );
    }
    return 0;
}
