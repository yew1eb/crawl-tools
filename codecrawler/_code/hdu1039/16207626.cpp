#include <stdio.h>
#include <string.h>
int main()
{
    char str[32767];
    int  flag,sum,len,i,a[32767];
    while(scanf("%s",str),strcmp("end",str))
    {
        flag=1;sum=0;
        for(i=0;i<strlen(str);i++)
        {
            switch(str[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':a[i]=1;sum++;break;
                default :a[i]=0;
            }
            if(i>0&&str[i]!='e'&&str[i]!='o'&&str[i]==str[i-1])
            {
                flag=0;break;
            }
            if(i>1&&a[i-2]==a[i-1]&&a[i-1]==a[i])
            {
                flag=0;break;
            }
        }
        if(sum!=0&&flag)
            printf("<%s> is acceptable.\n",str);
        else
            printf("<%s> is not acceptable.\n",str);
    }
}