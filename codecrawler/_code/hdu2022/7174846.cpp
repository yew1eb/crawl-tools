#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, m;
    int i, j, x, y, v;
    int max;
    int t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        max = v = 0;x=1;y=1;                          
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&t);                
                if(max<abs(t) ) 
                {  
                    max =abs(t);
                    v =t;
                    x =i;
                    y =j;
                }
            }   
        printf("%d %d %d\n",x,y,v);
    }
    return 0;
}              
