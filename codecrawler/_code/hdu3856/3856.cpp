#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 222222;

char str[ MAXN ];
int data[ MAXN * 2 ];
int p[ MAXN * 2 ];
int d[ MAXN * 2 ][30];
int n, len;

void init()
{
    int id,MaxL,MaxId;
    int i;
    MaxL=MaxId=0;
    len = strlen(&str[1]);
    for (i=1; i <= len; i++)
    {
        data[(i<<1)]=str[i];
        data[(i<<1)+1]=2;
    }
    data[0]=1;
    data[1]=2;
    n=(i<<1)+2;
    data[n]=0;
    MaxId=MaxL=0;
    p[0] = 1;
    for (i=1; i<n; i++)
    {
        if (MaxId>i)
            p[i]=min(p[2*id-i],MaxId-i);
        else
            p[i]=1;
        while (data[i+p[i]] == data[i-p[i]])
            p[i]++;
        if (p[i]+i>MaxId)
            MaxId=p[i]+i,id=i;
        //printf( "p[%d]=%d\n", i, p[i] );
    }
    for ( i = 1; i < n; ++i ) --p[i];

    return;
}

void RMQinit()
{
    for ( int i = 0; i <= n; ++i ) d[i][0] = p[i];
    for ( int j = 1; ( 1 << j ) <= n; ++j )
        for ( int i = 1; i + j - 1 <= n; ++i )
            d[i][j] = max( d[i][j - 1], d[ i + (1<<(j-1))][j - 1] );
    return;
}

int RMQquery( int L, int R )
{
    int k = 0;
    while ( (1 << (k + 1)) <= R - L + 1 ) ++k;
    return max( d[L][k], d[ R - ( 1 << k ) + 1 ][k] );
}

bool check( int L, int R, int mid )
{
    //if ( L + mid > R - mid ) return false;
    int ans = RMQquery( L + mid, R - mid );
    //printf("[%d %d]:%d\n", L + mid, R - mid, ans );
    //printf("ans = %d, mid = %d\n", ans, mid );
    if ( ans >= mid )
    {
        //puts("****");
        return true;
    }
    return false;
}

int BiSearch( int l, int r, int L, int R )
{
    int ans = 1;
    while ( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if ( check( L, R, mid ) )
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    return ans;
}

int main()
{
    int T;
    scanf( "%d", &T );
    getchar();
    while ( T-- )
    {
        memset( d, 0, sizeof(d) );
        memset( p, 0, sizeof(p) );
        gets( &str[1] );
        init();
        RMQinit();

        int Q;
        scanf( "%d", &Q );
        while ( Q-- )
        {
            int a, b;
            scanf( "%d%d", &a, &b );
            if ( a < 1 ) a = 1;
            if ( b > len ) b = len;
            if ( a > len )
            {
                puts("0");
                continue;
            }
            if ( a > b ) swap( a, b );
            int ans = BiSearch( 1, b - a + 1, a*2 - 1, b*2 + 1 );
            printf( "%d\n", ans );
        }
        getchar();
    }
    return 0;
}