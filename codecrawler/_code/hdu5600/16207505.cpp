#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1000000 + 5;
int data[MAXN];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++)   scanf("%d", &data[i]);
        if(n == 1){
            if(data[1] == 1)    printf("YES\n");
            else    printf("NO\n");
            continue;
        }
        int num = 0;
        for(int i = 1 ; i <= n ; i++){
            if(data[i] == 0)    num++;
        }
//        for(int i = 1 ; i <= n ; i++)   printf("%d ", data[i]);
//        printf("\n");
        if(num % 2 == 0)    printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}