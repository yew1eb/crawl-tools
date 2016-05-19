/*
 * Author: yew1eb
 * Created Time:  2014Äê11ÔÂ03ÈÕ ÐÇÆÚÒ» 13Ê±08·Ö16Ãë
 * File Name: hdu3068.cpp
 */
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int inf = 0x7fffffff;
const ll  INF = 1e18;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 110010;
char Ma[maxn*2];
int Mp[maxn*2];
void Manacher(char s[], int len){
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i=0; i<len; ++i){
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i=0; i<l; ++i){
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx){
            mx = i+Mp[i];
            id = i;
        }
    }
}

char s[maxn];

int main() {
    while(~scanf("%s",s)){
        int len = strlen(s);
        Manacher(s, len);
        int ans = 0;
        for(int i=0; i<2*len+2; ++i)
            ans = max(ans, Mp[i]-1);
        printf("%d\n", ans);
    }
    return 0;
}

