#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef struct milk {
    char name[110];
    int pay;
    int vol; 
    double wei;    
}ML;
ML M;
bool cmp ( const ML &a, const ML &b ){
    if ( a.wei != b.wei )
        return a.wei < b.wei;
    else return a.vol > b.vol;  
} 
int main ()
{
    int T;
    cin >> T; 
    while ( T -- ){
        int N;
        vector <ML> vec;
        cin >> N;
        for ( int i = 0; i < N; ++ i ){
            cin >> M.name >> M.pay >> M.vol;
            int d = 0;
            int t = M.vol;
            while ( t >= 200 && d <= 4 ){
                d ++;
                t -= 200;  
            }
            if ( d ) {
                M.wei = M.pay * 1.0 / d; 
                vec.push_back ( M );
            }
        }       
        sort ( vec.begin(), vec.end(), cmp );
        cout << vec[0].name << endl;
    }
    return 0;
}