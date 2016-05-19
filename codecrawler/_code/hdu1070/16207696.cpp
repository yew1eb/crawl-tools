#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define eps 10e-8

const int MAX_ = 10010;
const int MAX = 0x7fffffff;


int main(){
    int T, n, m, maxv, p ,v, maxp;
    double tmp, t;
    string str, ans;
    //scanf("%d",&T);
    cin>>T;
    while(T--){
        //scanf("%d",&n);
        cin>>n;
        tmp = MAX;
        maxv = 0;
        while(n--){
            cin>>str>>p>>v;
            if(v < 200)continue;
            if(v/200 >= 5)t = p/5.0;
            else t = p*1.0/(v/200);
            if(t < tmp){
                tmp = t;
                maxv = v;
                ans =str;
            }else if(fabs(t - tmp) < eps){
                if(maxv < v){
                    maxv = v;
                    ans = str;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
