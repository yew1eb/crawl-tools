#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ZeroOnepack( double pro[] ,int value[],double p ,int N, int sum )
{
    double f[10024] ={ 1.0 };
    for( int i = 0 ; i < N;  i++ )
    {
        for( int  j = sum ; j >= value[i] ; j -- )
        {
            if( f[j] < f[j - value[i]] * pro[i])
                f[j] = f[j - value[i]] * pro[i];     
        }     
    }
    for( int i = sum ; i >=0 ; i -- )
    {
       if( f[i] >= p )
          return i;  
    }   
}
int main( )
{
    int value[1024],N,Case,num;
    double p,pro[1024];
    while( scanf( "%d" ,&Case )==1 )
    {
        while( Case-- )
        {
            int sum = 0 ;
            scanf( "%lf%d",&p , &N );
            for( int i = 0 ; i < N; i++ )
            {
               scanf( "%d%lf" ,&value[i] , &pro[i] );
               pro[i] = 1.0 - pro[i];
               sum += value[i];   
            }
            printf( "%d\n",ZeroOnepack( pro , value,1.0- p, N,sum ) );
        }       
    }
    return 0;    
}