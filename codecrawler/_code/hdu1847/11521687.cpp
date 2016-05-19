/*
SGÖµ£ºÒ»¸öµãµÄSGÖµ¾ÍÊÇÒ»¸ö²»µÈÓÚËüµÄºó¼ÌµãµÄSGµÄÇÒ´óÓÚµÈÓÚÁãµÄ×îÐ¡ÕûÊý¡£
¼òµ¥µãÀ´½²¾ÍÊÇµ±Ç°×´Ì¬Àë×î½üÒ»¸ö±Ø°ÜµãµÄ¾àÀë£¿£¿£¿
ÎÒÃÇÃ¶¾ÙÏÂÅÆÊýÎª0-10µÄsgÖµ£º
SG(x)=mex{SG(S)}
SÊÇxµÄºó¼Ì×´Ì¬µÄSGº¯ÊýÖµ¼¯ºÏ£¬mex(S)±íÊ¾²»ÔÚSÄÚµÄ×îÐ¡·Ç¸ºÕûÊý¡£
SG(x) = 0 µ±ÇÒ½öµ±xÎª±Ø°Ü×´Ì¬¡£

num£º 0 1 2 3 4 5 6 7 8 9 10
sgÖµ£º0 1 2 0 1 2 0 1 2 0 1
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
int arr[11], sg[maxn];

void pre() { //°Ñ1000ÒÔÄÚµÄËùÓÐµÄ¿ÉÄÜÒ»´ÎÄÃµÄÅÆ¶¼Ëã³öÀ´£¡&#160;
    arr[0] = 1;
    for(int i=1; i<=10; ++i) arr[i] = arr[i-1]*2;
}

int mex(int x) { //ÕâÊÇÇó½â¸ÃµãµÄsgÖµµÄËã·¨º¯Êý(²ÉÓÃ¼ÇÒä»¯ËÑË÷)&#160;
    if(sg[x]!=-1) return sg[x];
    bool vis[maxn];
    memset(vis, false, sizeof vis );
    for(int i=0; i<10; ++i) {
        int temp = x - arr[i];
        if(temp<0) break;
        sg[temp] = mex(temp);
        vis[sg[temp]] = true;
    }

    for(int i=0; ; ++i) {
        if(!vis[i]) {
            sg[x] = i;
            break;
        }
    }
    return sg[x];
}
int main() {
    int n;
    pre();
    while(scanf("%d", &n)!=EOF) {
        memset(sg, -1, sizeof sg );
        if(mex(n)) printf("Kiki\n");
        else printf("Cici\n");
    }
    return 0;
}
