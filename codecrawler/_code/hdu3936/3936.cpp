#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int mod=1000000007;
const int gg=400000003;
int unit[ 3 ][ 3 ]={{2,0,-1},{1,0,0},{0,1,0}};
int ma[ 3 ][ 3 ][ 3 ];
void init( int to ){
 for( int i=0;i<3;i++ )
 for( int j=0;j<3;j++ )
 ma[ to ][ i ][ j ]=unit[ i ][ j ];
}
void macpy( int to,int from ){
 for( int i=0;i<3;i++ )
 for( int j=0;j<3;j++ )
 ma[ to ][ i ][ j ]=ma[ from ][ i ][ j ];
}
void cal( int a,int b,int c ){ 
 for( int i=0;i<3;i++ )
 for( int j=0;j<3;j++ ){
 ma[ c ][ i ][ j ]=0;
 for( int k=0;k<3;k++ )
 ma[ c ][ i ][ j ]=( (long long)ma[ a ][ i ][ k ]*ma[ b ][ k ][ j ]+ma[ c ][ i ][ j ] )%mod;
 } 
}
void gao( long long len ){
 if( len==1 ){
 init( 2 );
 return;
 }
 gao( len/2 );
 if( len%2 ){
 init( 1 );
 cal( 2,1,0 );
 cal( 2,0,1 );
 macpy( 2,1 );
 }
 else{
 cal( 2,2,1 );
 macpy( 2,1 );
 }
 
}
long long get( void ){
 return ( ( long long )ma[ 2 ][ 0 ][ 0 ]*4+(long long)ma[ 2 ][ 0 ][ 1 ]*2+(long long)ma[ 2 ][ 0 ][ 2 ]+(long long)ma[ 2 ][ 2 ][ 0 ]*4+(long long)ma[ 2 ][ 2 ][ 1 ]*2+(long long)ma[ 2 ][ 2 ][ 2 ]+1)%mod;
}
int main( void ){
 
 int q;
 scanf( "%d",&q );
 for( ;q;q-- ){
 long long l,r,cl=0,cr;
 scanf( "%I64d%I64d",&l,&r ); 
 if( --l ){
 gao( 4*l-3 );
 cl=get( );
 }
 gao( 4*r-3 );
 cr=get( );
 printf( "%d\n",( int )( ( ( ( ( cr-cl )%mod )*gg)%mod+mod )%mod ) );
 }
}