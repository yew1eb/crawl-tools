/*
¸ÅÄî:
±Ø°Üµã(Pµã) : Ç°Ò»¸öÑ¡ÊÖ(Previous player)½«È¡Ê¤µÄÎ»ÖÃ³ÆÎª±Ø°Üµã¡£ 
±ØÊ¤µã(Nµã) : ÏÂÒ»¸öÑ¡ÊÖ(Next player)½«È¡Ê¤µÄÎ»ÖÃ³ÆÎª±ØÊ¤µã¡£
±Ø°Ü(±ØÊ¤)µãÊôÐÔ
(1) ËùÓÐÖÕ½áµãÊÇ±Ø°Üµã£¨Pµã£©£»
(2) ´ÓÈÎºÎ±ØÊ¤µã£¨Nµã£©²Ù×÷£¬ÖÁÉÙÓÐÒ»ÖÖ·½·¨¿ÉÒÔ½øÈë±Ø°Üµã£¨Pµã£©£»
(3)ÎÞÂÛÈçºÎ²Ù×÷£¬ ´Ó±Ø°Üµã£¨Pµã£©¶¼Ö»ÄÜ½øÈë±ØÊ¤µã£¨Nµã£©.

ÌâÒâ£º

ÔÚÒ»¸öm*nµÄÆåÅÌÄÚ£¬´Ó(1,m)µã³ö·¢£¬Ã¿´Î¿ÉÒÔ½øÐÐµÄÒÆ¶¯ÊÇ£º×óÒÆÒ»£¬ÏÂÒÆÒ»£¬×óÏÂÒÆÒ»¡£È»ºókikiÃ¿´ÎÏÈ×ß£¬ÅÐ¶ÏkikiÊ±ºò»áÓ®£¨¶Ô·½ÎÞÂ·¿É×ßµÄÊ±ºò£©¡£

ÎÒÃÇ¿ÉÒÔ°ÑP¡¢N×´Ì¬µÄµãÍÆ³öÀ´ÈçÏÂÍ¼

*/
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b))
    {
        if(a==0&&b==0) break;
        if(a%2==0 || b%2==0) printf("Wonderful!\n");
        else printf("What a pity!\n");
    }
    return 0;
}
