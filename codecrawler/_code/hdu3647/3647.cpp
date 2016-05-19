 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 
 char tet[20];   //记录方块的下降次序
 int box[45];    //把方块分成小格子，记录每列有多个小格子
 int m, n;
 
 bool DFS( int cur )
 {
     if ( cur == 10 ) return true;
 
     switch( tet[cur] )
     {
         case 'I' :
         for ( int i = 0; i < n; i++ )
         {
             if ( box[i] + 4 <= m )   //判断能不能竖着放
             {
                 box[i] += 4;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 4;
             }
             if ( i + 3 < n && box[i] == box[i + 1] && box[i + 1] == box[i + 2] && box[i + 2] == box[i + 3] && box[i] + 1 <= m )    //能不能横着放
             {
                 for ( int j = i; j < i + 4; j++ ) ++box[j];
                 if ( DFS( cur + 1 ) ) return true;
                 for ( int j = i; j < i + 4; j++ ) --box[j];
             }
         }
         break;
 
         case 'O':
         for ( int i = 0; i < n; i++ )
         {
             if ( i + 1 < n && box[i] == box[i + 1] && box[i] + 2 <= m )
             {
                 box[i] += 2;
                 box[i + 1] += 2;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 2;
                 box[i + 1] -= 2;
             }
         }
         break;
 
         case 'L' :
         for ( int i = 0; i < n; i++ )
         {
             if ( i + 1 < n && box[i] + 3 <= m && box[i] == box[i + 1] )    //正着放L
             {
                 box[i] += 3;
                 box[i + 1] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 3;
                 box[i + 1] -= 1;
             }
 
             if (i + 2 < n && box[i] + 1 == box[i + 1] && box[i + 1] == box[i + 2] && box[i] + 2 <= m && box[i + 1] + 1 <= m )    //顺时针旋转90°
             {
                 box[i] += 2;
                 box[i + 1] += 1;
                 box[i + 2] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 2;
                 box[i + 1] -= 1;
                 box[i + 2] -= 1;
             }
 
             if (i + 1 < n && box[i] + 1 <= m && box[i + 1] + 3 <= m && box[i + 1] + 2 == box[i] )    //顺时针旋转180°
             {
                 box[i] += 1;
                 box[i + 1] += 3;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 3;
             }
 
             if (i + 2 < n && box[i] == box[i + 1] && box[i + 1] == box[i + 2] && box[i + 2] + 2 <= m )    //顺时针旋转270°
             {
                 box[i] += 1;
                 box[i + 1] += 1;
                 box[i + 2] += 2;
                 if ( DFS(cur + 1) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 1;
                 box[i + 2] -= 2;
             }
 
         }
         break;
 
         case 'J' :
         for ( int i = 0; i < n; i++ )
         {
             if (i + 1 < n && box[i] == box[i + 1] && box[i + 1] + 3 <= m )         //0
             {
                 box[i] += 1;
                 box[i + 1] += 3;
                 if ( DFS(cur + 1) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 3;
             }
             if (i + 2 < n && box[i] == box[i + 1] && box[i + 1] == box[i + 2] && box[i] + 2 <= m)         //90
             {
                 box[i] += 2;
                 box[i + 1] += 1;
                 box[i + 2] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 2;
                 box[i + 1] -= 1;
                 box[i + 2] -= 1;
             }
             if (i + 1 < n && box[i] + 2 == box[i + 1] && box[i] + 3 <= m && box[i + 1] + 1 <= m )         //180
             {
                 box[i] += 3;
                 box[i + 1] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 3;
                 box[i + 1] -= 1;
             }
             if (i + 2 < n && box[i] == box[i + 1] && box[i + 2] + 1 == box[i + 1] && box[i] + 1 <= m && box[i + 2] + 2 <= m)         //270
             {
                 box[i] += 1;
                 box[i + 1] += 1;
                 box[i + 2] += 2;
                 if ( DFS(cur + 1) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 1;
                 box[i + 2] -= 2;
             }
         }
         break;
 
         case 'Z' :
         for ( int i = 0; i < n; i++ )
         {
             if (i + 2 < n && box[i + 2] == box[i + 1] && box[i + 1] + 1 == box[i] && box[i] + 1 <= m && box[i + 1] + 2 <= m )  //0
             {
                 box[i] += 1;
                 box[i + 1] += 2;
                 box[i + 2] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 2;
                 box[i + 2] -= 1;
             }
             if (i + 1 < n && box[i] + 1 == box[i + 1] && box[i] + 2 <= m && box[i + 1] + 2 <= m)   //90
             {
                 box[i] += 2;
                 box[i + 1] += 2;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 2;
                 box[i + 1] -= 2;
             }
         }
         break;
 
         case 'S' :
         for ( int i = 0; i < n; i++ )
         {
             if (i + 2 < n && box[i] == box[i + 1] && box[i + 1] + 1 == box[i + 2] && box[i + 1] + 2 <= m && box[i + 2] + 1 <= m )    //0
             {
                 box[i] += 1;
                 box[i + 1] += 2;
                 box[i + 2] += 1;
                 if ( DFS(cur + 1) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 2;
                 box[i + 2] -= 1;
             }
             if (i + 1 < n && box[i + 1] + 1 == box[i] && box[i] + 2 <= m && box[i + 1] + 2 <= m )    //90
             {
                 box[i] += 2;
                 box[i + 1] += 2;
                 if ( DFS(cur + 1) ) return true;
                 box[i] -= 2;
                 box[i + 1] -= 2;
             }
         }
         break;
 
         case 'T' :
         for ( int i = 0; i < n; i++ )
         {
             if ( i + 2 < n && box[i] == box[i + 1] && box[i + 1] == box[i + 2] && box[i + 1] + 2 <= m ) //0
             {
                 box[i] += 1;
                 box[i + 1] += 2;
                 box[i + 2] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 2;
                 box[i + 2] -= 1;
             }
 
             if ( i + 1 < n && box[i] + 1 == box[i + 1] && box[i] + 3 <= m ) //90
             {
                 box[i] += 3;
                 box[i + 1] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 3;
                 box[i + 1] -= 1;
             }
             if ( i + 2 < n && box[i] == box[i + 2] && box[i + 1] + 1 == box[i] && box[i + 1] + 2 <= m ) //180
             {
                 box[i] += 1;
                 box[i + 1] += 2;
                 box[i + 2] += 1;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 2;
                 box[i + 2] -= 1;
             }
 
             if ( i + 1 < n && box[i + 1] + 1 == box[i] && box[i + 1] + 3 <= m ) //270
             {
                 box[i] += 1;
                 box[i + 1] += 3;
                 if ( DFS( cur + 1 ) ) return true;
                 box[i] -= 1;
                 box[i + 1] -= 3;
             }
         }
         break;
     }
     return false;
 }
 
 int main()
 {
     while ( scanf( "%d%d", &n, &m ), n || m )
     {
         for ( int i = 0; i < 10; i++ )
         {
             getchar();
             tet[i] = getchar();
         }
 
         memset( box, 0, sizeof(box) );
 
         if ( DFS(0) ) puts("Yes");
         else puts("No");
     }
     return 0;
 }
