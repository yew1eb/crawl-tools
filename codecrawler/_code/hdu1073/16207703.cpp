#include <stdio.h>
#include <string.h>

const int NUM=5000;
char str1[NUM];
char str2[NUM];

void input(char *str)
{
    char tmp[NUM];
    //gets(tmp);
  //  while(strcmp(tmp,"START") != 0)
       // gets(tmp);

    while(gets(tmp) && strcmp(tmp,"END"))
    {
        if(strlen(tmp) == 0)
            strcat(str,"\n");
        else
            strcat(str,tmp);
    }
}

void DelChar(char *str,int len)
{
    char tmp[NUM];
    int t = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            tmp[t++] = str[i];
    }
    tmp[t] = '\0';
    strcpy(str,tmp);
}

int cmp()
{
    int len1,len2;
    len1 = strlen(str1);
    len2 = strlen(str2);

    if(len1 == len2 && !strcmp(str1,str2))
        return 1;
    DelChar(str1,len1);
    DelChar(str2,len2);

    if(!strcmp(str1,str2))
        return 0;
    else
        return -1;

}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        while(n--)
        {
            memset(str1,0,sizeof(str1));
            memset(str2,0,sizeof(str2));
            input(str1);
            input(str2);

            int ans = cmp();
            if(ans == 1)
                puts("Accepted");
            else if(ans == 0)
                puts("Presentation Error");
            else
                puts("Wrong Answer");

        }
    }
    return 0;
}
