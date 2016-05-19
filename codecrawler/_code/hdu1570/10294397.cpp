#include<stdio.h>

main()
{
    int i,n,m,t;
    char c;
    long int a[11]={1,1};
    for(i=2;i<11;i++)
        a[i]=a[i-1]*i;
    scanf("%ld",&t);        
    while(t--)
    {
        getchar();
        scanf("%c %d %d",&c,&n,&m);
        if(c=='A') printf("%ld\n",a[n]/a[n-m]);
        else printf("%ld\n",(a[n]/a[n-m])/a[m]);
    }
}