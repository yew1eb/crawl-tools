#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
bool visit[2][801][801];
int maps[801][801];
int gx, gy, mx, my;
int z[2][2];
int step;
int moves[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
queue< pair<int,int> > q[2];

bool judge( int x, int y ){
    if( x >= 0 && x < N && y >= 0 && y < M && maps[x][y] != 0 ){
        for( int i = 0; i < 2; i++ ){
            if( abs( ( x - z[i][0] ) ) + abs( y - z[i][1] ) <= 2 * step ){//这里不要把x-z[i][0]变成double 不然会超时
                return false;
            }
        }
        return true;
    }
    return false;
}

bool BFS( int num ){
    int size = q[num].size();

    while( size-- ){
        int x = q[num].front().first;
        int y = q[num].front().second;
        q[num].pop();
        if( !judge( x, y ) ){
            continue;
        }
        for( int i = 0; i < 4; i++ ){
            int xx = x + moves[i][0];
            int yy = y +  moves[i][1];
            if( judge( xx, yy ) ){
                if( visit[num][xx][yy] ){
                    continue;
                }
                if( visit[num^1][xx][yy] ){
                    return true;
                }
                visit[num][xx][yy] = true;
                q[num].push( make_pair( xx, yy ) );
            }
        }
    }
    return false;
}

int solve(){
    while( !q[0].empty() ){
        q[0].pop();
    }
    while( !q[1].empty() ){
        q[1].pop();
    }
    q[0].push( make_pair( mx, my ) );
    q[1].push( make_pair( gx, gy ) );
    visit[0][mx][my] = visit[1][gx][gy] = true;
    step = 0;

    while( !q[0].empty() || !q[1].empty() ){
        step++;
        if( BFS( 0 ) ) return step;
        if( BFS( 0 ) ) return step;
        if( BFS( 0 ) ) return step;
        if( BFS( 1 ) ) return step;
    }
    return -1;
}

int main(){
    int Case;
    string s;

    cin >> Case;
    while( Case-- ){
        cin >> N >> M;
        int temp = 0;
        for( int i = 0; i < N; i++ ){
            cin >> s;
            for( int j = 0; j < M; j++ ){
                if( s[j] == 'X' ){
                    maps[i][j] = 0;
                }else if( s[j] == 'Z' ){
                    maps[i][j] = 0;
                    z[temp][0] = i;
                    z[temp++][1] = j;
                }else if( s[j] == '.' ){
                    maps[i][j] = 1;
                }else if( s[j] == 'M' ){
                    mx = i;
                    my = j;
                    maps[i][j] = 1;
                }else{
                    gx = i;
                    gy = j;
                    maps[i][j] = 1;
                }
            }
        }
        memset( visit, false, sizeof( visit ) );

        cout << solve() << endl;
    }
    return 0;
}