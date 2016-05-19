#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if(x>9) pt(x/10);
    putchar(x%10+'0');
}

const unsigned __int64 mod = 1000007;

struct HASHS{
    __int64 statu[2200000], cnt[2200000];
    int head[mod+10], next[2200000], E;

    __int64 findhash( __int64 st ){
        return st % mod;
    }

    void init(){
        E = 0;
        memset( head, -1, sizeof( head ) );
    }

    void add( __int64 st ){
        int u = findhash( st );
        statu[E] = st;
        next[E] = head[u];
        head[u] = E++;
    }
    bool Find( __int64 st ){
        int u = findhash( st );
        for( int i = head[u]; i != -1; i = next[i] ){
            if( statu[i] == st ){
                return true;
            }
        }
        return false;
    }
}biao;

__int64 sum[1001000], K;
int N;
set<__int64> s;

int main(){
    int T, Case = 1;
    scanf( "%d", &T );
    while( T-- ){
        scanf( "%d%I64d", &N, &K );
        memset( sum, 0, sizeof( sum ) );
        for( int i = 1; i <= N; i++ ){
            rd( sum[i] );
        }
        for( int i = 1; i <= N; i++ ){
            if( i & 1 ){
                sum[i] = sum[i-1] + sum[i];
            }else{
                sum[i] = sum[i-1] - sum[i];
            }
        }
        biao.init();
        bool flag = false;
        for( int i = N; i >= 1; i-- ){
            biao.add( sum[i] );
            if( i & 1 ){
                if( biao.Find( sum[i-1] + K ) ){
                    flag = true;
                    break;
                }
            }else{
                if( biao.Find( sum[i-1] - K ) ){
                    flag = true;
                    break;
                }
            }
        }
        if( flag ){
            printf( "Case #%d: Yes.\n", Case++ );
        }else{
            printf( "Case #%d: No.\n", Case++ );
        }
    }
    return 0;
}

