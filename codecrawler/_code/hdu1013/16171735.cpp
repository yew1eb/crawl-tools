#include<stdio.h>
#include<string.h>
int main()
{
    char num[1001];
    int i,temp;
    while(gets(num),num[0]!='0')
    {
        temp=0;
        for(i=0;i<strlen(num);i++)
        {
            temp+=num[i]-'0';
            temp=(temp-1)%9+1;//%9==0çæåµ
        }
        printf("%d\n",temp);
    }
    return 0;
}