#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[100];
int n;

int main()
{
    while( scanf("%s",name) == 1 ){
           int t = strlen(name);
           scanf("%d",&n);
           n %= 8;
           if( n < 0 )
               n += 8;
           if( n == 0 )
               printf("%s\n",name);
           else if( n==4 ){
                for( int i=t-1 ; i>=0 ; i-- )
                     printf("%c",name[i]);
                printf("\n");     
           }
           else if( n == 1 ){
                for( int i=t-1; i>=0 ; i-- ){
                     for( int j=i ; j>0 ; j-- )
                          printf(" ");
                     printf("%c\n",name[i]);
                }
           }
           else if( n == 2 ){
                for( int i=t-1 ; i>=0 ; i-- ){
                     for( int j=0 ; j<(t/2) ; j++ )
                          printf(" ");
                printf("%c\n",name[i]);     
                }
           }
           else if( n == 3 ){
                for( int i=t-1 ; i>=0 ; i-- ){
                     for( int j=t-1 ; j>i ; j-- )
                          printf(" ");
                     printf("%c",name[i]);
                     printf("\n");
                }
           }
           else if( n == 5 ){
                for( int i=0 ; i<t ; i++ ){
                     for( int j=i+1 ; j<t ; j++ )
                          printf(" ");
                     printf("%c\n",name[i]);
                }
           }
           else if( n == 6 ){
                for( int i=0 ; i<t ; i++ ){
                     for( int j=0 ; j<t/2 ; j++ )
                          printf(" ");
                printf("%c\n",name[i]);    
                } 
           }
           else if( n == 7 ){
                for( int i=0 ; i<t ; i++ ){
                     for( int j=0 ; j<i ; j++ )
                          printf(" ");
                     printf("%c\n",name[i]);                           
                }     
           }
    }    
    return 0;
}
