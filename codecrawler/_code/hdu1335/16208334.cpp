#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    int num[100],a,b;
    while(~scanf("%s%d%d",s,&a,&b))
    {
        int len = strlen(s);
        memset(num,0,sizeof(num));
        for(int i = 0; i < len; i++)
        {
            if(s[i]>='0' && s[i] <= '9')
                num[i] = s[i] - '0';
            else
                num[i] = s[i] - 'A' + 10;
        }
        int A,NumA;
        NumA = 0,A = 1;
        for(int i = len-1; i >= 0; i--)
        {
            NumA += (num[i]*A);
            A *= a;
        }
        char ans[100];
        int k = 0;
        memset(ans,0,sizeof(ans));
        while(NumA)
        {
            char temp = NumA % b + '0';
            if(temp >='0' && temp<='9')
                ans[k++] = temp;
            else
                ans[k++] = NumA%b+'A'-10;
            NumA /= b;
        }
        ans[k] = '\0';
        if(k > 7)
            printf("  ERROR\n");
        else
        {
            for(int i = 0;i < 7-k;i++)
                printf(" ");
            for(int i = k-1; i >= 0; i--)
                printf("%c",ans[i]);
            printf("\n");
        }
    }

    return 0;
}