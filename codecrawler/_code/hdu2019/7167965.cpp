#include<stdio.h>
int main()
{
    int n, m;
    int i, b;
    int f[103];
    scanf("%d%d",&n,&m);
    while(n!=0&&m!=0)
    {
                     
        for(i=1;i<=n;i++)    scanf("%d",&f[i]);
        b = n+1;
        int first =1;
        for(i=1;i<=n;i++) 
            if(f[i]>=m){b=i;break;}
        for(i=1;i<=n;i++)
          { 
             if(first) first= 0;
             else printf(" ");
             if(i==b&& b<=n) printf("%d ",m);
             printf("%d",f[i]);
          }   
        if(b==n+1) printf(" %d\n",m);
        else printf("\n"); 
        scanf("%d%d",&n,&m);
    }    
    return 0;
}
  