#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2000 + 5;
char str[500 + 5][MAXN];
int f[MAXN];
int len[MAXN];
int vis[MAXN];
void getfail(char s[])
{
    memset(f, 0, sizeof(f));
    int tj = 0;
    int len = strlen(s);
    for(int j = 1 ; j < len ; j++){
        while(tj && s[tj] != s[j])  tj = f[tj];
        if(s[tj] == s[j])   tj++;
            f[j + 1] = tj;///å°±æ¯è¿éï¼åæf[j]=tjä¼T
    }
}
bool match(char s[], char t[])
{
    int ok = 0;
    int t1 = 0;
    getfail(t);
    int l1 = strlen(s);
    int l2 = strlen(t);
    for(int k = 0 ; k < l1 ; k++){
    //                   printf("i = %d, j = %d, k = %d, t1 = %d\n", i, j, k, t1);
        while(t1 && s[k] != t[t1])    t1 = f[t1];
        if(s[k] == t[t1]) t1++;
    //                  printf("after t1 = %d\n", t1);
        if(t1 == l2){
            return true;
        }
    }
    return false;
}
int main()
{
//    freopen("HDU 5510.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1 ; cas <= T ; cas++){
        int n;
        scanf("%d", &n);
        for(int i = 0 ; i < n ; i++)
            scanf("%s", str[i]);
        memset(vis, 0, sizeof(vis));
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            len[i] = strlen(str[i]);
            if(i == 0)  continue;
            for(int j = 0 ; j < i ; j++){
                if(vis[j] == 1) continue;
                bool ok = match(str[i], str[j]);
                if(ok)  vis[j] = 1;
                else    ans = i + 1;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}