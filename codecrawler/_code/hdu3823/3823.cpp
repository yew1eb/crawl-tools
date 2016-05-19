#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MAXN = 200000010;

int a[MAXN];
bool b[MAXN];
vector <int>sub[155];
int main(){
    memset(b, 0, sizeof(b));
    b[1] = 1;
    for(int i = 2; i*i <= MAXN; i++){
        if(b[i] == 1)
            continue;
        for(int j = i*2; j <= MAXN; j += i){
            b[j] = 1;
        }
    }
    int times = 0;
    for(int i = 2; i <= MAXN; i++){
        if(b[i] == 0){
            a[times] = i;
            times++;
        }
    }
    for(int i = 0; i < times-1; i++){
        int temp = a[i+1] - a[i];
        if(temp>150)
            continue;
        sub[temp].push_back(a[i+1]);
    }
    int m;
    scanf("%d", &m);
    int sum = 0;
    while(m--){
       sum++;
       long long x, y;
       cin >> x >> y;
       int temp1 = abs(x - y);
       int temp2 = x > y ? x : y;
       long long res = 0;
       for(int i = 0;i < sub[temp1].size(); i++){
            if(sub[temp1][i] >= temp2){
                res = sub[temp1][i];
                break;
            }
        }
       printf("Case %d: ", sum);
       if(res == 0)
           puts("-1");
       else
           printf("%lld\n", res - temp2);
    }
    return 0;
}
