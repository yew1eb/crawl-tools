#include<stdio.h>
#include<string.h>
int main()
{
    char str[101];
    int s,i,j,len,count1,count2,count3,count4,count5;
    scanf("%d",&s);
    getchar();
    for(j=0;j<=s-1;j++)
    {
        gets(str);
        len=strlen(str);
        count1=count2=count3=count4=count5=0;
        for(i=0;i<=len-1;i++)
        {
            if(str[i]=='a') count1++;
            if(str[i]=='e') count2++;
            if(str[i]=='i') count3++;
            if(str[i]=='o') count4++;
            if(str[i]=='u') count5++;
        }
        printf("a:%d\n",count1);
        printf("e:%d\n",count2);
        printf("i:%d\n",count3);
        printf("o:%d\n",count4);
        printf("u:%d\n",count5);
        if(j<s-1)
        {
            printf("\n");
        }
    }
    return 0;
}