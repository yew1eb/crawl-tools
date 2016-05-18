#include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<queue>
 #include<stdlib.h>
 #include<algorithm>
 using namespace std;
 const int maxn = 100005;
 const int maxm = 1005;
 int book[ maxn ],pos[ maxn ];
 //int vis[ maxn ];
 struct node{
     int book[ 12 ];
     int cnt;
 }stu[ maxm ];
 int main(){
     int m,n;
     while( scanf("%d%d",&m,&n)!=EOF ){
         for( int i=0;i<=m;i++ ){
             stu[ i ].cnt=0;
         }
         memset( book,-1,sizeof( book ));//book[ i ] the i people
         memset( pos,-1,sizeof( pos ));// pos[ k ] the kth place
         int ca;
         scanf("%d",&ca);
         for( int t=1;t<=ca;t++ ){
             char tmp[5];
             scanf("%s",&tmp);
             if( tmp[0]=='B' ){
                 int u,b;
                 scanf("%d%d",&u,&b);
                 if( book[ b ]!=-1 ){
                     printf("The book is not in the library now\n");
                 }
                 else if( stu[ u ].cnt>=9 ){
                     printf("You are not allowed to borrow any more\n");
                 }
                 else {
                     stu[ u ].book[ stu[u].cnt ]=b;
                     pos[ b ]=stu[ u ].cnt;
                     book[ b ]=u;
                     stu[ u ].cnt++;
                     printf("Borrow success\n");
                 }
             }
             else if( tmp[0]=='R' ){
                 int b;
                 scanf("%d",&b);
                 if( book[ b ]==-1 ){
                     printf("The book is already in the library\n");
                 }
                 else {
                     printf("Return success\n");
                     for( int j=pos[b];j<stu[book[b]].cnt-1;j++ ){
                         stu[ book[b] ].book[ j ]=stu[ book[b] ].book[ j+1 ];
                         pos[ stu[ book[b] ].book[ j+1 ] ]=j;
                     }
                     
                     stu[ book[b] ].cnt--;
                     book[ b ]=-1;
                     pos[ b ]=-1;
                     
                 }
             }
             else if( tmp[0]=='Q' ){
                 int u;
                 scanf("%d",&u);
                 if( stu[ u ].cnt==0 ){
                     printf("Empty\n");
                 }
                 else {
                     int temp[ 12 ];
                     int k=0;
                     for( int i=0;;i++ ){
                         if( pos[stu[u].book[ i ]]!=-1 ){
                             temp[ k++ ]=stu[u].book[i];
                             if( k>=stu[u].cnt ) break;
                         }
                     }
                     sort( temp,temp+k );
                     for( int i=0;i<k;i++ ){
                         if( i==0 ) printf("%d",temp[i]);
                         else printf(" %d",temp[i]);
                     }
                     printf("\n");
                 }
             }
         }
         printf("\n");
     }
     return 0;
 }