
/*
http://acm.hdu.edu.cn/showproblem.php?pid=1525
ÌâÒâ£º
Á½ÈË²©ÞÄ£¬¸ø³öÁ½¸öÊýaºÍb£¬
½Ï´óÊý¼õÈ¥½ÏÐ¡ÊýµÄÈÎÒâ±¶Êý£¬½á¹û²»ÄÜÐ¡ÓÚ0£¬½«Á½¸öÊýÈÎÒâÒ»¸öÊý¼õµ½0µÄÎªÊ¤Õß¡£
Ìâ½â£º
¼ÙÉèa´óÓÚb£¬aºÍbÁ½¸öÊý£¬×îºó¶¼»áÃæ¶Ô(b,a%b)µÄ¾ÖÊÆ£¬Èç¹ûa/b>=1£¬
ÔòÖ»ÄÜÑ¡Ôñ(b,a%b)¾ÖÊÆ£»Èç¹ûa/b>=2£¬Ôò¿ÉÒÔÓÐa/bÖÖ·½·¨£¬
¸ù¾ÝÆæÅ¼ÐÔ¿ÉÒÔÖªµÀÒ»¶¨ÄÜÑ¡Ôñµ½±ØÊ¤²ßÂÔ¡£ËùÒÔa/b>=2¿ÉÒÔÈ¡µ½±ØÊ¤²ßÂÔ¡£
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b))
    {
        if(a==0&&b==0) break;
        if(a<b)  swap(a,b);
        bool Stan = true;
        while(1)
        {

            if(b==0 ||a%b==0||a/b>=2) break;
            int t = a;
            a = b;
            b = t - a;
            Stan = !Stan;
        }
        if(Stan) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}
