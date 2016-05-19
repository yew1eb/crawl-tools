#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
    int id[101];
    int tot;
};

struct DP{
    int sumv;
    int sume;
}dp[1<<16];
int v[101], e[101];
int N, E;
Node node[101];

int main(){
    int T;
    cin >> T;
    while( T-- ){
        cin >> N >> E;
        for( int i = 1; i <= N; i++ ){
            cin >> v[i];
        }
        for( int i = 1; i <= N; i++ ){
            cin >> e[i];
        }
        for( int i = 1; i <= N; i++ ){
            cin >> node[i].tot;
            for( int j = 0; j < node[i].tot; j++ ){
                cin >> node[i].id[j];
            }
        }
        memset( dp, -1, sizeof( dp ) );
        dp[0].sume = dp[0].sumv = 0;
        for( int i = 0; i < ( 1 << N ); i++ ){
            if( dp[i].sume == -1 ){
                continue;
            }
            for( int j = 1; j <= N; j++ ){
                if( i & ( 1 << ( j - 1 ) ) ){
                    continue;
                }
                int flag = 1;
                for( int k = 0; k < node[j].tot; k++ ){
                    if( !( i & ( 1 << ( node[j].id[k] - 1 ) ) ) ){
                        flag = 0;
                        break;
                    }
                }
                if( flag == 1 ){
                    dp[i|(1<<(j-1))].sumv = dp[i].sumv + v[j];
                    dp[i|(1<<(j-1))].sume = dp[i].sume + e[j];
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < ( 1 << N ); i++ ){
            if( dp[i].sume <= E ){
                ans = max( ans, dp[i].sumv );
            }
        }
        cout << ans << endl;
    }
    return 0;
}