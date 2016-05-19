#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node 
{
    int num;
    int index;
}a[5];

bool cmp ( Node a , Node b )
{
    return a.num > b.num;
} 
int main ( )
{
    int t;
    scanf ( "%d" , &t );
    int n;
    while ( t-- )
    {
        scanf ( "%d" , &n );
        int temp;
        for ( int i = 1 ; i <= n ; i++ )
        {
           a[i].num = 0;
           for ( int j = 1 ; j <= 3 ; j++ )
           {     
                scanf ( "%d" , &temp );
                a[i].num = max ( temp , a[i].num );
           }
            a[i].index = i;
        }
        sort ( a+1 , a+n+1 , cmp );
        int ans[5];
        for ( int i = 1 ; i <= n ; i++ )
            ans[a[i].index] = i;
        for ( int i = 1 ; i < n ; i++ )
            printf ( "%d " , ans[i] );
        printf ( "%d\n" , ans[n] );
    }
}