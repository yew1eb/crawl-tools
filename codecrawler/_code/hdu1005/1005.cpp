#include <stdio.h>
#include <string.h>
int s[50];
int main()
{
    int a,b,n,i;
    while(scanf("%d%d%d",&a,&b,&n),a || b || n)
    {
       int i;
       s[0]=s[1]=1;
       for(i = 2; i<50;i++)
       {
             s[i] = (a*s[i-1]+b*s[i-2])%7;
             if(s[i] ==1 && s[i-1] == 1)
             {break;}
                   
       }  
       n = n%(i-1);
       if(n == 0)
        printf("%d/n",s[i-2]);
        else
        printf("%d/n",s[n-1]);
                                        
    }    
    return 0;
}