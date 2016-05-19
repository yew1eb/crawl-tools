#include<stdio.h>
int main()
{
    int k,m,c,r,d,i,j,l,flag,res,a[102];
    while(scanf("%d%d",&k,&m),k)
    {
        flag=1;
        for(i=0;i<k;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&c,&r);
            res=0;
            for(j=0;j<c;j++)
            {
                scanf("%d",&d);
                for(l=0;l<k;l++)//è®°å½éäºå¯éè¯¾çæ°é 
                    if(d==a[l])
                        res++;
            }
            if(res>=r)//æ­¤æ¬¡éè¯¾è¾¾æ  
                continue;
            else//ä¸è¾¾æ  
                flag=0;
        }
        if(flag)
            printf("yes\n");
        else    
            printf("no\n");
    }
    return 0;
}