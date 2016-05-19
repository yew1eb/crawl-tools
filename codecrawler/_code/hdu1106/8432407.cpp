#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1005];
int a[1005];

int main()
{
    int n, i,j, num, len;
    while(~scanf("%s",s))
    {
        len = strlen(s);
        if(s[len-1] !='5'){s[len++] = '5'; s[len] ='\0';}
        i = 0; n = 0;
        while(i<len)
        {
            num = 0; j = i;
            while(j<len && s[j]!='5')
                    num =num*10 + s[j++]-'0';
            if(j>i)
            {
                a[n++] = num;
                i = j;
            }
            while(i<len&&s[i] =='5') i++;
        }
        sort(a,a+n);
        for(i=0; i<n-1; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}
