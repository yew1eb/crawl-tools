/*
* @author Novicer
* language : C++/C
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

const int maxn = 1000000 + 5;
int a[maxn];

int main(){
    int n;
    while(cin >> n && n){
        int cnt = 0;
        int total = 0;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&a[i]);
            total += a[i];
        }
        if(total < 0){
            cout << 0 << endl;
            continue;
        }
        else{
            int l = 0;
            int pos = n;
            int ans = 0;
            int sum = 0;
            while(l <= pos){
                sum += a[l];
                l++;
                while(sum < 0){
                    sum += a[pos];
                    pos--;
                }
            }
//            cout << l << endl;
//            cout << pos << endl;
            int tmp = 0;
            while(pos >= 1){
                if(tmp >= 0) ans ++;
                if(tmp < 0)    tmp += a[pos];
                else if(a[pos] < 0) tmp = a[pos];
                pos--;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

