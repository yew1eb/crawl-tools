/*
ÁíÒ»ÖÖË¼Â·£º
   Ò»¸öÊ÷£º 1¡¢ÎÞ»·£»2¡¢Ö»ÓÐ¸ù½ÚµãµÄÈë¶ÈÎªÁã£¬ÆäËûµÄ½ÚµãÈë¶È¶¼Îª1.
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100005
int f[MAXN];
int hash[MAXN];
int ineg[MAXN];
int find(int x){while(x!=f[x]) x=f[x]; return x;}
int main()
{
    int a, b, i, x, y, flag1, cnt=0,n, max,flag2,num;
    while(scanf("%d%d",&a,&b))
    {
        if(a<0||b<0) break;
        for(i=0; i<MAXN; i++) {f[i] = i;hash[i] = 0;ineg[i] = 0;}
        flag1 = 1; max = 0;
        while(true)
        {
            if(a==0&&b==0)break;
            hash[a] = hash[b] = 1;
            ineg[b]++;
            if(max<a)max = a; if(max<b) max = b;
            x = find(a); y = find(b);
            if(x!=y)
            {
                f[y] = x;

            }
            scanf("%d%d",&a,&b);
        }
        flag2=flag1= 0;
        for(i=0; i<=max; i++)
        {
            if(hash[i]&&ineg[i]>1) {flag1=1;break;}
            if(hash[i]&&ineg[i]==0){if(++flag2>1) break;}
        }
        if(flag2!=1||flag1!=0){ printf("Case %d is not a tree.\n",++cnt);continue;}

        num = 0;
        for(i=0; i<=max; i++) if(hash[i]&&f[i]==i) num++;
        if(num!=1) printf("Case %d is not a tree.\n",++cnt);
        else printf("Case %d is a tree.\n",++cnt);
    }
    return 0;
}
