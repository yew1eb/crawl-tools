/*
×À×ÓÉÏÓÐM¶ÑÆË¿ËÅÆ£»Ã¿¶ÑÅÆµÄÊýÁ¿·Ö±ðÎªNi(i=1¡­M)£»
Á½ÈËÂÖÁ÷½øÐÐ£»Ã¿×ßÒ»²½¿ÉÒÔÈÎÒâÑ¡ÔñÒ»¶Ñ²¢È¡×ßÆäÖÐµÄÈÎÒâÕÅÅÆ£»
×À×ÓÉÏµÄÆË¿ËÈ«²¿È¡¹â£¬ÔòÓÎÏ·½áÊø£»×îºóÒ»´ÎÈ¡ÅÆµÄÈËÎªÊ¤Õß¡£

Ìâ½â£º
ÄáÄ·²©ÞÈ£¨Nimm Game£©

ÏÈÇóËùÓÐ¶ÑµÄ Nim-sum = N1 ^ N2 ^ ... NM
È»ºó
res =Nim-sum ^ Ni
Èç¹û res < Ni, ÔòÏÈÊÖÍæ¼ÒÖ»ÒªµÚÒ»²½´ÓNi¶ÑÖÐÈ¡×ßNi-res¸ö, ÔòÊ£ÏÂµÄ¾ÖÃæNim-sum = 0,
¼´ÎªÊ£ÏÂµÄ¾ÖÃæÎª±Ø°ÜÌ¬¡£ÔòÕâ¾ÍÒ»ÖÖÈ¡Ê¤µÄ·½°¸¡£

¶ÔÓÚÃ¿¸ö¶ÑµÄ²Ù×÷ÖÁ¶àÖ»ÓÐÒ»ÖÖ·½·¨¿ÉÒÔµ¼°Ü±Ø°Üµã£¨Nim-sum = 0£©
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[200];

int main() {
    int n;
    while(~scanf("%d", &n)&&n) {
        int sum = 0;
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
            sum ^= a[i];
        }
        int ans = 0;
        for(int i=0; i<n; ++i)
            if(a[i] > (sum^a[i]) ) ans++;

        printf("%d\n", ans);
    }
    return 0;
}












