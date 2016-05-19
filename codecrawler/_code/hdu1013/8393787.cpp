#include <stdio.h>
int main()
{
    char s[1010];
    int  i, tmp;
    while(scanf("%s",s))
    {
        if(s[0]=='0') break;
        i=0;
        tmp =0;
        while(s[i])
        {
            tmp +=s[i]-'0';
            i++;
        }
        while(tmp>9)
        {
            tmp = tmp/10 + tmp % 10;
        }
        printf("%d\n",tmp);
    }
    return 0;
}
