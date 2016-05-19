#include<stdio.h>
#include<string.h>
int vis[1000000+100];
int main()
{
    int cas,n,i;
    scanf("%d",&cas);
    while(cas--)
    {
       scanf("%d",&n);
       if(n<0) {printf("-");n=-n;}
       memset(vis,0,(n+100)*sizeof(vis[0]));
       int  cnt=0;
       int fz=1,fm=n;
       if(n==1) {printf("1\n");continue;}
       printf("0.");
       while(fz!=0)
       {
            vis[fz]=1;
            fz=fz*10;
            printf("%d",fz/fm);
            fz=fz%fm;
            if(vis[fz])  break;
       }

       printf("\n");
    }
   return 0;
}
