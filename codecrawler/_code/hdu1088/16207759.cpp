#include"stdio.h"
#include"string.h"
int main()
{
    char str[11111][85];
    int len;
    int i,l,k;
    int temp;
    
    i=0;
    while(scanf("%s",str[i])!=-1)    i++;
    k=i;


    len=0;
    for(i=0;i<k;i++)
    {
        temp=strlen(str[i]);
        if(strcmp(str[i],"<hr>")==0)
        {
            if(len)    printf("\n");
            for(l=0;l<80;l++)    printf("-");
            printf("\n");
            len=0;
        }
        else if(strcmp(str[i],"<br>")==0)    {printf("\n");len=0;}


        else
        {
            if(len+1+temp>80)    {len=temp;printf("\n%s",str[i]);}
            else if(len)        {printf(" %s",str[i]);len+=temp+1;}
            else                {printf("%s",str[i]);len=temp;}
        }
    }
    printf("\n");
    return 0;
}