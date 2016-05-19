/*
*Author : Flint_x 
*Created Time : 2015-07-20 14:19:04 
*File name : whust1_I.cpp 
*/

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;

#define cls(a) memset(a,0,sizeof(a))
#define rise(i,a,b) for(int i = a ; i <= b ; i++)
#define fall(i,a,b) for(int i = a ; i >= b ; i--)


int main(){
//    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    rise(t,1,T){
        int r[10];
        rise(i,1,9) cin >> r[i];
        int sum = 0, m = 0;
        rise(i,0,31){
            int tmp = 0;
            rise(j,1,8){
                tmp += r[j]>>i&1;
            }
            if((sum + tmp)% 2 != (r[9]>>i&1)){//x>>i&1ç­æäº1<<i&x 
                tmp = 8 - tmp;
                sum = (sum + tmp) / 2;
                m += 1<<i;
            }
            else sum = (sum + tmp) / 2;
        }
        cout << m << endl;
    }
    return 0;
}


     