#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1001],str2[1001];
    int s,i,len;
    scanf("%d",&s);
    getchar();
    while(s--)
    {
        scanf("%s",str1);
        strcpy(str2,str1);
        strrev(str1);//**åç½®å­ç¬¦ä¸²**//
        if(strcmp(str1,str2)==0)
        {
            printf("yes\n");
        }
        else
            printf("no\n");
    }
    return 0;
}