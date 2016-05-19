#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;
char s[1005];
LL a,b;
bool check()
{
    int n = strlen(s);
    int flag = 0;
    for(int i = 0;i < n;++i){
        if(s[i] == '-'){
            if(i != 0 || n == 1)
                return false;
        }
        else if(s[i] == '0'){
            if(flag == 0)
                return false;
        }
        else if(s[i] >= '1' && s[i] <= '9'){
            flag++;
        }
        else
            return false;
    }
    return true;
}
LL get()
{
    int n = strlen(s);
    if(n > 11 || n == 0)
        return b + 1;
    LL res = 0;
    for(int i = 0;i < n;++i){
        if(s[i] == '-')continue;
        res = res*10LL + s[i] - '0';
    }
    if(s[0] == '-')
        res = -res;
    return res;
}
void work()
{
    scanf("%I64d%I64d",&a,&b);
    getchar();
    if(check() || strcmp(s,"0") == 0){
        LL ss = get();
        if(ss >= a && ss <= b)
            puts("YES");
        else
            puts("NO");
    }
    else
        puts("NO");


    return ;
}
int main(){
    while(gets(s)){
        work();
    }
    return 0;
 }