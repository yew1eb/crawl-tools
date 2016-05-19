#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int textcase;
    scanf("%d",&textcase);
    for(int k=1;k<=textcase;k++)
    {
        int height,width,h,h1,h2,w;
        char a;
        //a=getchar();
        //scanf("%c",&a);
        //getchar();
        //scanf("%d", &height);
        cin>>a>>height;
        width=height/6+1;//widthä¸ºç«ç´å­ç¬¦çé¿åº¦
        h=height-3;
        if(h%2==0)
            h1=h2=h/2;
        else
        {
            h1=h/2;//h1ä¸ºä¸é¢0çé«åº¦
            h2=h-h1;//h2ä¸ºä¸é¢0çé«åº¦
        }
        w=h2;//wä¸ºä¸­é´å­ç¬¦é¿åº¦
        //è¾åºç¬¬ä¸è¡
        for(int i=0;i<width;i++)
            printf(" ");
        for(int i=0;i<w;i++)
            printf("%c",a);
        printf("\n");
        //è¾åºä¸é¢0
        for(int i=0;i<h1;i++)
        {
            for(int j=0;j<width;j++)
                printf("%c",a);
            for(int j=0;j<w;j++)
                printf(" ");
            for(int j=0;j<width;j++)
                printf("%c",a);
            printf("\n");
        }
        //è¾åºä¸­é´ä¸è¡
        for(int i=0;i<width;i++)
            printf(" ");
        for(int i=0;i<w;i++)
            printf("%c",a);
        printf("\n");
        //è¾åºä¸é¢0
        for(int i=0;i<h2;i++)
        {
            for(int j=0;j<width;j++)
                printf("%c",a);
            for(int j=0;j<w;j++)
                printf(" ");
            for(int j=0;j<width;j++)
                printf("%c",a);
            printf("\n");
        }
        //è¾åºæåä¸è¡
        for(int i=0;i<width;i++)
            printf(" ");
        for(int i=0;i<w;i++)
            printf("%c",a);
        printf("\n");
        if(k!=textcase)
            printf("\n");
    }
    return 0;
}
