#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int n , ans;
char T[55] , S[55];

void solve(){
    ans = 999999999;
    //1直接单个选
    int num = 0;
    for(int i = 0 ; i < n ; i++){
        if(T[i] != S[i]) num++;
    }
    if(ans > num) ans = num;
    //2全选+单个选
    num = 1;
    for(int i = 0 ; i < n ; i++){
        if(S[i] == '0') num++;
    }
    if(ans > num) ans = num;
    //3反选+单个选
    num = 1;
    for(int i = 0 ; i < n ; i++){
        if(T[i] == '0') T[i] = '1';
        else T[i] = '0';
    }
    for(int i = 0 ; i < n ; i++){
        if(T[i] != S[i]) num++;
    }
    if(ans > num) ans = num;
    //4先全选在反选
    num = 2;
    for(int i = 0 ; i < n ; i++) T[i] = '0';
    for(int i = 0 ; i < n ; i++){
        if(T[i] != S[i]) num++;
    }
    if(ans > num) ans = num;
    printf("%d\n" , ans);
}

//主函数
int main(){
    //freopen("input.txt" , "r" , stdin);
    while(scanf("%d" , &n) != EOF){
        getchar();//注意换行
        gets(T) ; gets(S);
        solve();
    }
    return 0;
}