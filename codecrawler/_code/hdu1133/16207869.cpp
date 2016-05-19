#include <iostream>
#include <string>
using namespace std;
#define MAX 100
#define BASE 10000
void multiply(int a[],int Max,int b)  //å¤§æ°ä¹å°æ°
{
    int i,array=0;
    for (i=Max-1; i>=0; i--)   
    {
        array+=b*a[i];
        a[i] = array%BASE;
        array /= BASE;   
    }
}

void divide(int a[], int Max, int b)  //å¤§æ°é¤å°æ°
{
    int i,div=0;
    for (i=0;i<Max; i++)   
    {
        div = div*BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}
int fact[205][MAX];
void setFact ()  //æ±åº0-200çé¶ä¹å¼ 
{
     fact[0][MAX-1] = fact[1][MAX-1] = 1;
     for ( int i = 2; i <= 200; ++ i )
     {
           memcpy ( fact[i] , fact[i-1] , MAX * sizeof ( int ) );
           multiply ( fact[i] , MAX , i ); 
     } 
}
void outPut ( int ctl[MAX] )
{
     int i = 0;
     while ( i < MAX && ctl[i] == 0 )//å»æåé¢çä¸º0çé¡¹ 
     {
             i ++ ; 
     }
     printf ( "%d", ctl[i++] );             
     while ( i < MAX )   
     {
             printf ( "%04d", ctl[i++] );   
     } 
     putchar ( '\n' ); 
}
int res[MAX];
int main ()
{
     int M,N;
     int ca = 1;
     setFact();  //æè¡¨ 
     while ( cin >> M >> N , M + N )
     {
             printf ( "Test #%d:\n",ca++ );
             if ( N > M )
             {
                  puts ( "0" );
                  continue; 
             }
             memcpy ( res , fact[M+N] , MAX * sizeof ( int ) ); //é¶ä¹ ( m + n )!
             multiply ( res, MAX, M - N + 1 );    // ( m + n )! * ( m-n+1 )
             divide ( res, MAX, M + 1 );   // ( m + n )! * ( m-n+1 )  / ( m+ 1 )         
             outPut ( res );
     }
     return 0;
}