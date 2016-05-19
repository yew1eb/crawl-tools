/*
 带权值的并查集
 ps:对于两个不在同一个集合里面的两个元素，把父节点接在一起即可
 */
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<algorithm>
 #include<iostream>
 #include<queue>
 #include<map>
 #include<math.h>
 using namespace std;
 typedef long long ll;
 //typedef __int64 int64;
 const int maxn = 50015;
 const int inf = 0x7fffffff;
 const double pi=acos(-1.0);
 const double eps = 1e-8;
 
 int dis[ maxn ],fa[ maxn ];
 
 void init( int n ){
     for( int i=0;i<=n;i++ ){
         dis[ i ] = 0;
         fa[ i ] = i;
     }
     return ;
 }
 int find( int x ){
     if( fa[x]==x ) return x;
     int tmp = find( fa[x] );
     dis[ x ] = dis[ x ]+dis[ fa[x] ];
     dis[ x ] = dis[ x ]%300;
     fa[ x ] = tmp;
     return fa[ x ];
 }
 bool unionab( int a,int b,int c ){
     int x = find(a);
     int y = find(b);
     //printf("fa[%d]=%d,fa[%d]=%d,dis[%d]=%d,dis[%d]=%d\n",a,x,b,y,a,dis[a],b,dis[b]);
     if( x==y ){
         if( ((dis[b]-dis[a]+300)%300)!=c ){//b在a的后面，保证是dis[b]-dis[a]
             //printf("test:%d %d\n",a,b);
             return false;
         }
     }
     else{
         dis[ y ] = dis[ a ]+c-dis[ b ]+300;
         dis[y] %= 300;
         fa[ y ] = x;
     }
     return true;
 }
 int main(){
     int n,m;
     while( scanf("%d%d",&n,&m)==2 ){
         int a,b,c;
         init( n );
         int res = 0;
         while( m-- ){
             scanf("%d%d%d",&a,&b,&c);
             bool f = unionab( a,b,c );
             if( f==false ) res++;
         }
         printf("%d\n",res);
     }
     return 0;
 }