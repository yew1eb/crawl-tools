#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define N 1020
#define mxn 50020

int sum[mxn];
struct trie {
    int ch[mxn][26], lst[mxn], f[mxn], cnt[mxn];
    int sz;
    void init() {
        memset( ch[0], -1, sizeof( ch[0] ) );
        cnt[0] = 0;
        sz = 1;
    }
    int creat() {
        memset( ch[sz], -1, sizeof( ch[sz] ) );
        cnt[sz] = 0;
        return sz++;
    }
    void insert( char *s, int num ) {
        int t = 0;
        for( int i = 0; s[i]; ++i ) {
            int c = s[i] - 'A';
            if( ch[t][c] == -1 )
                ch[t][c] = creat();
            t = ch[t][c];
        }
        cnt[t] = num;
    }
    void build() {
        queue<int> q;
        f[0] = 0;
        for( int i = 0; i < 26; ++i )
            if( ch[0][i] == -1 )
                ch[0][i] = 0;
            else {
                f[ch[0][i]] = 0;
                lst[ch[0][i]] = 0;
                q.push( ch[0][i] );
            }
        while( !q.empty() ) {
            int t = q.front(); q.pop();
            for( int c = 0; c < 26; ++c ) 
                if( ch[t][c] == -1 )
                    ch[t][c] = ch[f[t]][c];
                else {
                    int nxt = ch[t][c];
                    f[nxt] = ch[f[t]][c];
                    lst[nxt] = cnt[f[nxt]]? f[nxt]: lst[f[nxt]];
                    q.push( nxt );
                }
        }
    }
    void query( char *s ) {
        int t = 0;
        for( int i = 0; s[i]; ++i ) {
            if( s[i] < 'A' || s[i] > 'Z' ) {
                t = 0;
                continue;
            }
            int c = s[i] - 'A';
            t = ch[t][c];
            int tmp = t;
            while( tmp ) {
                if( cnt[tmp] )
                    sum[cnt[tmp]] ++;
                tmp = lst[tmp];
            }
        }
    }
    void debug() {  
        for( int i = 0;i < sz; i++ ) {  
            printf( "id = %3d,fail = %3d,cnt = %3d,chi = [", i, f[i], cnt[i] );  
            for( int j = 0; j < 10; j++ )  
                printf( "%2d",ch[i][j] );  
            printf( "]\n" );  
        }  
    } 
}ac;
char s[N][55];
char t[2000020];
int n;

int main() {
//    freopen( "tt.txt", "r", stdin );
    while( scanf( "%d", &n ) != EOF ) {
        memset( sum, 0, sizeof( sum ) );
        ac.init();
        for( int i = 1; i <= n; ++i ) {
            scanf( "%s", s[i] );
            ac.insert( s[i], i );
        }
        ac.build();
        getchar();
        gets( t );
        ac.query( t );
        for( int i = 1; i <= n; ++i ) {
            if( sum[i] )
                printf( "%s: %d\n", s[i], sum[i] );
        }
    }
    return 0;
}