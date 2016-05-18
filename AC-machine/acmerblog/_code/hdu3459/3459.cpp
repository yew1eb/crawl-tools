#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char maps[10][10];
int maxdeep;
char ans[100];

int get_h(){
    int cnt = 0;
    if( maps[2][0] != maps[3][0] || maps[2][7] != maps[3][7] )  cnt++;
    if( maps[3][6] != maps[3][7] || maps[5][2] != maps[5][3] )  cnt++;
    if( maps[4][2] != maps[5][2] || maps[3][0] != maps[3][1] )  cnt++;
    return cnt;
}

bool check(){
    if( !( maps[0][2] == maps[0][3] && maps[0][3] == maps[1][2] && maps[1][2] == maps[1][3] ) ) return false;
    if( !( maps[2][2] == maps[2][3] && maps[2][3] == maps[3][2] && maps[3][2] == maps[3][3] ) ) return false;
    if( !( maps[4][2] == maps[4][3] && maps[4][3] == maps[5][2] && maps[5][2] == maps[5][3] ) ) return false;
    if( !( maps[2][0] == maps[2][1] && maps[2][1] == maps[3][0] && maps[3][0] == maps[3][1] ) ) return false;
    if( !( maps[2][4] == maps[2][5] && maps[2][5] == maps[3][4] && maps[3][4] == maps[3][5] ) ) return false;
    if( !( maps[2][6] == maps[2][7] && maps[2][7] == maps[3][6] && maps[3][6] == maps[3][7] ) ) return false;
    return true;
}

void rotation_x(){
    char temp1 = maps[5][3];
    char temp2 = maps[4][3];
    maps[5][3] = maps[3][3];
    maps[4][3] = maps[2][3];
    maps[3][3] = maps[1][3];
    maps[2][3] = maps[0][3];
    maps[1][3] = maps[2][6];
    maps[0][3] = maps[3][6];
    maps[2][6] = temp1;
    maps[3][6] = temp2;
    temp1 = maps[2][4];
    maps[2][4] = maps[2][5];
    maps[2][5] = maps[3][5];
    maps[3][5] = maps[3][4];
    maps[3][4] = temp1;
}

void rotation_y(){
    char temp1 = maps[2][7];
    char temp2 = maps[2][6];
    for( int i = 7; i >= 3; i -= 2 ){
        maps[2][i] = maps[2][i-2];
        maps[2][i-1] = maps[2][i-3];
    }
    maps[2][1] = temp1;
    maps[2][0] = temp2;
    char temp = maps[1][2];
    maps[1][2] = maps[0][2];
    maps[0][2] = maps[0][3];
    maps[0][3] = maps[1][3];
    maps[1][3] = temp;
}

void rotation_z(){
    char temp1 = maps[1][2];
    char temp2 = maps[1][3];
    maps[1][2] = maps[2][4];
    maps[1][3] = maps[3][4];
    maps[2][4] = maps[4][3];
    maps[3][4] = maps[4][2];
    maps[4][3] = maps[3][1];
    maps[4][2] = maps[2][1];
    maps[3][1] = temp1;
    maps[2][1] = temp2;
    char temp = maps[2][2];
    maps[2][2] = maps[2][3];
    maps[2][3] = maps[3][3];
    maps[3][3] = maps[3][2];
    maps[3][2] = temp;
}

void pf(){
    cout << endl;
    for( int i = 0; i < 6; i++ ){
        for( int j = 0; j < 8; j++ ){
            cout << maps[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool DFS( int deep ){
    if( deep + get_h() > maxdeep )  return false;
    if( deep == maxdeep )   return check();

    rotation_x();
  //  pf();
    ans[deep] = 'X';
    if( DFS( deep + 1 ) )   return true;
    rotation_x();rotation_x();rotation_x();

    rotation_y();
    ans[deep] = 'Y';
    if( DFS( deep + 1 ) )   return true;
    rotation_y();rotation_y();rotation_y();

    rotation_z();
    ans[deep] = 'Z';
    if( DFS( deep + 1 ) )   return true;
    rotation_z();rotation_z();rotation_z();

    return false;
}

int main(){
    while( 1 ){
        for( int i = 0; i < 6; i++ ){
            scanf( "%s", maps[i] );
        }
        if( maps[0][2] == '.' ){
            break;
        }
        maxdeep = 0;
        while( true ){
            maxdeep++;
            if( DFS( 0 ) ){
                break;
            }
        }
        for( int i = 0; i < maxdeep; i++ ){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}