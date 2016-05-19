#include <stdio.h>
#define max 1005

int pre[max];
int n,m,t;

void init()
{
    for(int i=0;i<n;i++)
        pre[i]=i;
}

int find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i,j;
    i=x;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    } 
    return r;
}

void jion(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
      pre[fx]=fy;
    else//è¿ä¸ç¹æ¯æå³é®çï¼å¦æä¸¤ä¸ªæ°çæ ¹èç¹ç¸åï¼ååå ä¸ç°å¨çè¿æ¡è¾¹å°±æä¸ºä¸ä¸ªç¯äºï¼ 
      t++; 
}

int main()
{
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        t=0;
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            jion(a,b);
        }
        printf("%d\n",t); 
    }
}