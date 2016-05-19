//Accepted    1166    46MS    2256K    2359 B    C    ä¸¹ææ¬
#include <stdio.h>
#include <string.h>
#define M  500002

struct node
{
    int left;   //å·¦è¾¹ç
    int right;  //å³è¾¹ç
    int mid;    //å¨addæsubæ¶ï¼æ¯å å¨å·¦å­æ å¢è¿æ¯å³å­æ å¢
    int num;    //äººæ°
} p[M];
void init(int a,int b,int n)
{
    p[n].left = a;
    p[n].right = b;
    p[n].mid = (a+b)/2;
    p[n].num = 0;
    if(a + 1 == b)   //å½åçä¸è½ååæ¶ï¼ä¾å¦[0,1]
    {
        return ;
    }
    init(a,(a+b)/2,2*n);  //nè¥ä»1å¼å§ï¼é£ä¹2*nå°±æ¯å·¦å­æ ä¸æ ï¼å·¦è¾¹çè¿æ¯aï¼å³è¾¹çåä¸­å¼
    init((a+b)/2,b,2*n+1); //åçï¼å¾å³å­æ 
}
void add(int pos,int value,int n)
{
    p[n].num += value;
    if(p[n].left + 1 == p[n].right)
        return ;
    if(pos < p[n].mid)
    {
        //å å¨å·¦å­æ 
        add(pos,value,2*n);
    }
    else
    {
        add(pos,value,2*n + 1);
    }
}
void sub(int pos,int value,int n)
{
    p[n].num -= value;
    if(p[n].left + 1 == p[n].right)
        return ;
    if(pos < p[n].mid)
        sub(pos,value,2*n);
    else
        sub(pos,value,2*n + 1);
}
int query(int a,int b,int n)
{
    if(p[n].left == a && p[n].right == b)  
        return p[n].num; 
    if(a < p[n].mid )
    {
        if(b <= p[n].mid )
        {
            return query(a,b,2*n);
        }
        else
        {
            return query(a,p[n].mid,2*n) + query(p[n].mid,b,2*n + 1);
        }
    }
    else
        return query(a,b,2*n+1);
}
int main()
{
    int icase;
    int N,i,va;
    char c[10];
    int ax,ay;
    int times = 0;
    scanf("%d",&icase);
    while(icase --)
    {
        memset(c,0,sizeof(c));
        scanf("%d",&N);
        init(1,N+1,1);
        for(i = 1; i <= N; i++)
        {
            scanf("%d",&va);
            add(i,va,1);
        }
        printf("Case %d:\n",++times);
        while(1)
        {
            scanf("%s",c);
            if( !strcmp(c,"End"))
            {
                break;
            }
            scanf("%d%d",&ax,&ay);
            if( strcmp(c,"Query") == 0)
            {
                printf ("%d\n",query(ax,ay+1,1));
            }
            else if(strcmp(c,"Add") == 0)
            {
                add(ax,ay,1);
            }
            else if(strcmp(c,"Sub") == 0)
            {
                sub(ax,ay,1);
            }

        }
    }
    return 0;
}
