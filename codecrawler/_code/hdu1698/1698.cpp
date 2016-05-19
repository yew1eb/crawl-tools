/*
 线段树+修改区间+询问区间
 */
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<algorithm>
 #include<iostream>
 #include<queue>
 #include<vector>
 #include<map>
 #include<math.h>
 typedef long long ll;
 //typedef __int64 int64;
 const int maxn = 100005;
 const int maxm = 1005;
 const int inf = 0x7FFFFFFF;
 const double pi = acos(-1.0);
 const double eps = 1e-8;
 using namespace std;
 #define LEFT( x ) (x<<1)
 #define RIGHT( x ) ((x<<1)+1)
 struct node{
     int l,r,sum;
     int flag;
 }tree[ maxn<<2 ];
 int data[ maxn ];
 void pushup( int n ){
     tree[ n ].sum = tree[ LEFT( n ) ].sum+tree[ RIGHT( n ) ].sum;
     return ;
 }
 void pushdown( int n,int m ){//下标为n，这段区间有m个数
     if( tree[ n ].flag!=0 ){
         tree[ LEFT( n ) ].flag = tree[ RIGHT( n ) ].flag = tree[ n ].flag;
         tree[ LEFT( n ) ].sum =  tree[ n ].flag*(m-m/2);//tree[ n ].flag*((m+1)/2);
         tree[ RIGHT( n ) ].sum = tree[ n ].flag*(m/2);//tree[ n ].flag*( m-(m+1)/2 );
         tree[ n ].flag = 0;
     }
     return;
 }
 void build( int l,int r,int n ){
     if( l==r ){
         tree[ n ].sum = data[ l ];
         tree[ n ].flag = 0;
         tree[ n ].l=tree[ n ].r = l;
         return ;
     }
     tree[ n ].flag = 0;
     tree[ n ].l = l;
     tree[ n ].r = r;
     int mid;
     mid = (l+r)>>1;
     build( l,mid,LEFT( n ) );
     build( mid+1,r,RIGHT( n ) );
     pushup( n );
     return;
 }
 void update( int a,int b,int c,int l,int r,int n ){
     if( a==l&&b==r ){
         tree[ n ].flag = c;
         tree[ n ].sum = (r-l+1)*c;
         return ;
     }
     pushdown( n,r-l+1 );
     //printf("test\n");
     int mid;
     mid = (l+r)>>1;
     if( mid>=b ) update( a,b,c,l,mid,LEFT( n ) );
     else if( mid<a ) update( a,b,c,mid+1,r,RIGHT( n ));
     else {
         update( a,mid,c,l,mid,LEFT( n ) );
         update( mid+1,b,c,mid+1,r,RIGHT( n ) );
     }
     pushup( n );
     return ;
 }
 int query( int a,int b,int l,int r,int n ){
     if( a==l&&b==r ){
         return tree[ n ].sum;
     }
     pushdown( n,r-l+1 );
     int mid;
     mid = (l+r)>>1;
     if( mid>=b ) return query( a,b,l,mid,LEFT( n ) );
     else if( mid<a ) return query( a,b,mid+1,r,RIGHT( n ));
     else return query( a,mid,l,mid,LEFT( n ) )+query( mid+1,b,mid+1,r,RIGHT( n ));
 }
 int main(){
     int ca;
     scanf("%d",&ca);
     for( int t=1;t<=ca;t++ ){
         int n;
         scanf("%d",&n);
         for( int i=1;i<=n;i++ ){
             data[ i ] = 1;
         }
         build( 1,n,1 );
         int op;
         scanf("%d",&op);
         while( op-- ){
             int a,b,c;
             scanf("%d%d%d",&a,&b,&c);
             update( a,b,c,1,n,1 );
         }
         printf("Case %d: The total value of the hook is %d.\n",t,tree[ 1 ].sum);
     }
     return 0;
 }