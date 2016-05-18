#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define REP(a,b,c) for(int a = b; a < c; ++a)
#define eps 10e-8
#define MAX 10

const int MAX_ = 100010;
const int N = 500000;
const int INF = 0x7fffffff;

char str[MAX_], str1[MAX_];


int Minimze(char s[])
{
    int i, j, len, k;
    i = 0; j = 1; len = strlen(s); k = 0;
    while(i < len && j < len && k < len){
        int t = s[(i+k)%len] - s[(j+k)%len];
        if(!t)++k;
        else {
            if(t > 0)i = i+k+1;
            else j = j + k +1;
            if(i == j)++j;
            k = 0;
        }
    }
    return i>j?j:i;
}

int main() {
    int T, n, m, numa = 0, numb = 0,ans;
    bool flag = 0;
    string s = "";



    while(~scanf("%s", str)) {
        int len = strlen(str);
        REP(i, 1, len+1){
            str1[i-1] = (str[i%len] - str[i-1] + 8)%8+'0';
        }
        str1[len] = '\0';
        ans = Minimze(str1);
        REP(i, 0, len){
            printf("%c", str1[(ans+i)%len] );
        }
        putchar('\n');

    }
    return 0;
}
