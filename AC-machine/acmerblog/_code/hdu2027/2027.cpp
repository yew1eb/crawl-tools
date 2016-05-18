#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

int T , sign[200]  , hash[5]={'a' , 'e' , 'i' , 'o' , 'u'}; 

char str[105];

int main()
{
    scanf( "%d%*" ,&T );
    while( T-- )
    {
        memset( sign , 0 ,sizeof(sign) );
        gets( str );
        int len = strlen ( str );
        for( int i=0 ; i<len ; ++i )
            sign[str[i]]++;
        for( int i=0 ;i< 5;++i )
            printf( "%c:%d\n" ,hash[i],sign[hash[i]]);
        if( T > 0)  
            puts( "" );  
    }
    return 0;
}