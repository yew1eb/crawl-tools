#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 0x3f3f3f3f
int weight[1001][1001];

int main(){
    
    int lowcost[1001];
    int N, M, ans;
	int flag = 0;

    while( scanf( "%d%d", &N, &M ) != EOF ){
        memset( weight, 0x3f, sizeof( weight ) );
        
        for( int i = 0; i < M; i++ ){
            int temp1, temp2, temp3;
            cin >> temp1 >> temp2 >> temp3;
            if( weight[temp1][temp2] > temp3 ){
                weight[temp1][temp2] = temp3;
                weight[temp2][temp1] = temp3;
            }
        }
        
        for( int i = 1; i < N; i++ ){
            lowcost[i] = weight[i][0];
        }
        lowcost[0] = -1;

        int ans = 0;
        for( int i = 1; i < N; i++ ){
            int mindis = MAX;
            int k = 1;
            for( int j = 1; j < N; j++ ){
                if( lowcost[j] < mindis && lowcost[j] != -1 ){
                    mindis = lowcost[j];
                    k = j;
                }
            }
            if( mindis == MAX ){
                ans = MAX;
                break;
            }
            ans += mindis;
			lowcost[k] = -1;
            for( int j = 1; j < N; j++ ){
                if( weight[k][j] < lowcost[j] ){
                    lowcost[j] = weight[k][j];
                }
            }
        }

        if( ans == MAX ){
            cout << "impossible" << endl;
        }else{
            cout << ans << endl;
        }
		cout << endl;
    }
    return 0;
}