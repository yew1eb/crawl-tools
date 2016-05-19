#include<stdio.h>
#include<string.h>
int a[1000000+1];
int main()
{
    int cas,i;
    scanf("%d",&cas);
    while(cas--)
    {
        int n;
         scanf("%d",&n);
         for(i=0;i<n;i++) scanf("%d",&a[i]);
         int flag=1;
         for(i=0;i<=n-2;i++)
         {
             if(a[i]==0) continue;
             if(a[i+1]<a[i]) {flag=0;break;}
             a[i+1]-=a[i];
         }
         if(a[n-1]>0) {flag=0;}
         if(flag) printf("yeah~ I escaped ^_^\n");
         else printf("I will never go out T_T\n");
    }
    return 0;
}
/*
æ³¨æè¿äºæ°æ®
55
5
0 2 2 2 2

9
0 2 2 0 0 0 0 2 2

2
1 2

2
2 2

2
2 1

9
0 2 2 2 0 0 0 0 2

*/
