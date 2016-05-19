#include<stdio.h>
#include<string.h>
int set[1005],n,f,c,num[1005];
char ch[1005][20];
int search( char str[] )
{
    for( int i = 1; i < c; ++i )
         if( !strcmp( str,ch[i] ) )
             return i;
    strcpy( ch[c],str );
    int len = strlen( str );
    ch[c][len] = 0;
    return c++;
}
int main( )
{
    while( scanf( "%d",&n ),n )
    {
           c = 1;
           f = 1;
           for( int i = 0; i <= 2*n; ++i )
                set[i] = 2;
           for( int i = 1; i <= n; ++i )
           {
                int x,y;
                char str1[20],str2[20];
                scanf( "%s%s",str1,str2 );
                x = search( str1 );
                y = search( str2 );
                set[y] = 0；//标记在右边出现过
                if( set[x] == 2 )//防止在左边出现的已经在右边出现了
                    set[x] = 1;//标记在左边出现过
            }
            int cout = 0;
            for( int i = 1; i < c; ++i )
                 if( set[i] == 1 )
                     ++cout;
            if( cout != 1 )
                f = 0;
            puts( f ? "Yes":"No" );
           }
    return 0;
}