#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    int cost[100001];
    long n,w,l,i;
    long max, temp, sum, last;
    while(cin >> n){
        max = temp = sum = 0; last = -1;
        for(i=0; i<n; ++i){
            scanf("%ld %ld", &w, &l);
            cost[i] = w - l;
            sum += cost[i];
            if(sum >= 0){
                ++temp;
                if(last == -1) last = i;
            }else{
                max = (temp > max) ? temp : max;
                temp = sum = 0;
                last = -1;
            }
        }
        if(sum >= 0){
            for(i=0; i<last; ++i){
                sum += cost[i];
                if(sum >= 0)
                    ++temp;
                else
                    break;
            }
        }
        max = (temp > max) ? temp : max;
        cout << max << endl;
    }
    return 0;
}