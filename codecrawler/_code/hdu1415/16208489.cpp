#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>

using namespace std;

int main()
{
    int ca , cb , cc , x , y ;
    while( ~scanf( "%d%d%d" , &ca , &cb , &cc ) )
    {
        if( cb == cc )
            {
                printf( "fill B\n" ) ;
            }
        
        else if( ca == cc )
        {
            printf( "fill A\n" );
            printf( "pour A B\n" ) ;
        }
            else
            {
                x = y = 0 ;
                if( ca < cc )
                {
                    while( 1 )
                    {
                        if( y == 0 )
                        {
                            y = cb ;
                            printf( "fill B\n" ) ;
                        }
                    
                        if( y > ca - x )
                           {y -= ca - x ;
                             x = ca ;
                            
                            printf( "pour B A\n" ) ;
                        }
                        else
                        {
                            x += y ;
                            y = 0 ;
                            printf( "pour B A\n" ) ;
                        }
                        if( y == cc )
                            break ;
                        if( x == ca )
                        {
                            x = 0 ;
                            printf( "empty A\n" );
                        }
                    }
                }
                else
                {
                    while( 1 )
                    {
                        if( x == 0 )
                        {
                            x = ca ;
                            printf( "fill A\n" ) ;
                        }
                        if( x > cb - y )
                        {x -= cb - y ;
                            y = cb ;
                            
                            printf( "pour A B\n" );
                        }
                        else
                        {
                            y += x ;
                            x = 0 ;
                            printf( "pour A B\n" ) ;
                        }
                        if( y == cc )
                            break ;
                        if( y == cb )
                        {
                            y = 0 ;
                            printf( "empty B\n");
                        }
                    }
                }
            }
            printf( "success\n" ) ;
    }
    return 0 ;
}