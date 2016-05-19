/*
 找到一个图，使得每一个连通分量最多有一个环
 */
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<algorithm>
 using namespace std;
 const int maxn = 10005;
 const int maxm = 100005;
 struct node{
     int u,v,val;
 }edge[ maxm ];
 int fa[ maxn ],circle[ maxn ];
 int find( int x ){
     if( fa[x]==x ) return x;
     fa[x] = find(fa[x]);
     return fa[x];
 }
 bool union_ab( int x,int y ){
     int fax = find(x);
     int fay = find(y);
     if( fax==fay ){
         if( circle[ fax ]==-1 ){
             circle[ fax ] = 1;
             return true;
         }//形成一个环
         return false;
         //已经是环
     }
     else{
         if( circle[ fax ]==circle[ fay ]&&circle[ fax ]==1 )
             return false;
         if( circle[ fax ]==1 )
             fa[ fay ] = fax;
         else
             fa[ fax ] = fay;
         //这里注意把环作为祖先，因为find
         return true;
     }
 }
 void init( int n ){
     for( int i=0;i<n;i++ ){
         fa[i] = i;
         circle[ i ] = -1;
     }
 }
 int cmp( node a,node b ){
     return a.val>b.val;
 }
 int main(){
     int n,m;
     while( scanf("%d%d",&n,&m)==2,n||m ){
         //if( n==0&&m==0 ) break;
         for( int i=0;i<m;i++ )
             scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].val);
         init( n );
         sort( edge,edge+m,cmp );
         int ans = 0;
         for( int i=0;i<m;i++ ){
             if( union_ab( edge[i].u,edge[i].v) )
                 ans += edge[i].val;
         }
         printf("%d\n",ans);
     }
     return 0;
 }