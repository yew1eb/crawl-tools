#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len,mark[100000],num,flag;
    char ch[510];
    while(gets(ch))
    {
        if(strcmp("*",ch)==0)break;
        len=strlen(ch);
        flag=0;
        for(i=1;i<len;i++)
        {
            memset(mark,0,sizeof(mark));
            for(j=0;j<len-i;j++)
            {
                num=(ch[j]-'A'+1)*100+ch[j+i]-'A'+1;
                if(mark[num]==1)
                {
                    flag=1;
                    break;
                }
                mark[num]=1;
            }
            if(flag==1)break;
        }
        if(flag==1)
            printf("%s is NOT surprising.\n",ch);
        else
            printf("%s is surprising.\n",ch);
    }
    return 0;
}