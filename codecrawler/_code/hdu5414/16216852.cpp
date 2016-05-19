#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define sss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a) memset(a,0,sizeof(a))
#define ss(a,b) scanf("%d%d",&a,&b)
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n", a)
#define INF 0x3f3f3f3f
#define w(a) while(a)
#define PI acos(-1.0)
#define LL long long
#define eps 10E-9
#define N 100010
const LL  mod = 1000000000+7;
const int SIGMA_SIZE=26;
const int MAXN=100010;
const int MAXNODE=600010;
using namespace std;
void mys(int& res) {
    int flag=0;
    char ch;
    while(!(((ch=getchar())>='0'&&ch<='9')||ch=='-'))
        if(ch==EOF)  res=INF;
    if(ch=='-')  flag=1;
    else if(ch>='0'&&ch<='9')  res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')  res=res*10+ch-'0';
    res=flag?-res:res;
}
void myp(int a) {
    if(a>9)
        myp(a/10);
    putchar(a%10+'0');
}
/*************************THE END OF TEMPLATE************************/
int a[26];
int b[26];
char stra[100010];
char strb[100010];
int main() {
    int t;
    s(t);
    getchar();
    w(t--){
        int a1=0, b1=0;
        mem(a);
        mem(b);
        int i=0;
        bool f=false;
        w(1){
            stra[i] = getchar();
            if(stra[i] == '\n'){
                stra[i]='\0';
                break;
            }
            a[stra[i]-'a']++;
            if(i>0 && stra[i]!=stra[0]) f=true;
            if(i>0 && stra[i] == stra[0] && !f)  a1++;
            i++;
        }
        f=false;
        i=0;
        w(1){
            strb[i] = getchar();
            if(strb[i] == '\n'){
                strb[i]='\0';
                break;
            }
            b[strb[i]-'a']++;
            if(i>0 && strb[i] != strb[0]) f=true;
            if(i>0 && strb[i] == strb[0] && !f) b1++;
            i++;
        }
        bool flag = false;
        for(int i=0; i<=25; i++){
            if(a[i]>b[i]) {
                flag = true;
                break;
            }
        }
        if(a1<b1 || stra[0] != strb[0]) flag=true;
        if(flag) puts("No");
        else puts("Yes");
    }
    return 0;
}