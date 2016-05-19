#include<stdio.h>
#include<string.h>
int main()
{
    int a[30],b[30];
    char s1[50],s2[50];
    int cas,n,k,i,flag,flag1;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s %s %d",s1,s2,&k);
        if(k%2==0) flag=1;// å¶æ°è¾åºa[i] å¥æ°è¾åºb[i] å·ä½åå çä¸é¢
        else flag=0;
        for(i=0;i<strlen(s1);i++)
        {
            a[s1[i]-'a']++;
        }
        if(k==0)
        {
            for(i=0;i<26;i++)
                printf("%c:%d\n",i+'a',a[i]);
            printf("\n");continue;
        }
        for(i=0;i<strlen(s2);i++)
            b[s2[i]-'a']++;
        if(k==1)
        {
            for(i=0;i<26;i++)
                printf("%c:%d\n",i+'a',b[i]);
            printf("\n");continue;
        }
        k=k-1;
        flag1=1;
        while(k--)
        {
            if(flag1==1)
            {
                for(i=0;i<26;i++)
                {
                     a[i]=b[i]+a[i];
                }
                flag1=!flag1;
            }
            else
            {
                for(i=0;i<26;i++)
                {
                    b[i]=b[i]+a[i];
                }
                flag1=!flag1;
            }

        }
        if(flag)
        {
            for(i=0;i<26;i++)
                printf("%c:%d\n",i+'a',a[i]);
        }
        else
        {
            for(i=0;i<26;i++)
                printf("%c:%d\n",i+'a',b[i]);
        }
        if(cas!=0)
            printf("\n");

    }
    return 0;
}