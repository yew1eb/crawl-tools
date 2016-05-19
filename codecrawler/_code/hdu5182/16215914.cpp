#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 1000007

using namespace std;

int n;

struct Node
{
    int d,x,y,id;
}p[MAX];

bool cmp ( Node a , Node b )
{
    if ( a.d == b.d ) 
    {
        if ( a.y == b.y ) return a.id < b.id;
        return a.y < b.y;
    } 
    return a.d > b.d;
}

int ans[MAX];

int main ( )
{
    while ( ~scanf ( "%d" , &n ) )
    {
        for ( int i = 0 ; i < n ; i++ ) 
        {
            scanf ( "%d%d" , &p[i].x , &p[i].y );
            p[i].d = p[i].x - p[i].y;
            p[i].id = i;
        }
        sort ( p , p+n , cmp );
        for ( int i = 0 ; i < n-1 ; i++ )
            printf ( "%d " , p[i].id );
        printf ( "%d\n" , p[n-1].id );
    }
}