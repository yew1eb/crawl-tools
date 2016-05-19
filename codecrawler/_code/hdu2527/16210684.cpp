#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int L = 1000000+10;
const int inf = 1<<30;
char str[L];
struct kode
{
    int num;
    char c;
} b[L<<2];

struct node
{
    int wei,parent,lson,rson,cover;
    char data;
} a[L<<2];

int main()
{
    int i,j,sum,t,len,lb;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&sum,str);
        len = strlen(str);
        sort(str,str+len);
        for(i = 0; i<len<<2; i++)
        {
            a[i].cover = a[i].lson = a[i].rson = a[i].parent = a[i].wei = b[i].num = 0;
            a[i].data = b[i].c = '\0';
        }
        lb = 0;
        b[lb].num = 1;
        b[lb].c = ch = str[0];
        for(i = 1; i<len; i++)
        {
            if(str[i] == ch)
                b[lb].num++;
            else
            {
                lb++;
                ch = str[i];
                b[lb].c = ch;
                b[lb].num = 1;
            }
        }
        if(lb == 0)//åªæä¸ç§ç±»åçå­ç¬¦ï¼ç´æ¥æ¯è¾
        {
            if(b[lb].num<=sum)
                printf("yes\n");
            else
                printf("no\n");
            continue;
        }
        lb++;
        int m = lb*2-1;
        for(i = 0; i<lb; i++)
        {
            a[i].data = b[i].c;
            a[i].wei = b[i].num;
        }
        for(i = 0; i<lb; i++)//å»ºç«åå¤«æ¼æ 
        {
            int m1 = inf,m2 = inf;
            int x = 0,y = 0;
            for(j = 0; j<lb+i; j++)
            {
                if(a[j].wei<m1 && !a[j].cover)
                {
                    m2 = m1;
                    m1 = a[j].wei;
                    y = x;
                    x = j;
                }
                else if(a[j].wei<m2 && !a[j].cover)
                {
                    m2 = a[j].wei;
                    y = j;
                }
            }
            a[x].parent = lb+i;
            a[y].parent = lb+i;
            a[lb+i].lson = x;
            a[lb+i].rson = y;
            a[lb+i].wei = a[x].wei+a[y].wei;
            a[x].cover = a[y].cover = 1;
        }
        int ans = 0;
        for(i = lb; i<2*lb-1; i++)//æ±é¤äºå¶å­èç¹å¤å¶ä»ææèç¹çæå¼å
            ans+=a[i].wei;
        if(ans<=sum)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
