#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
char a[100],b[100];

int main()
{
    int cas,T=1,a1,a2,b1,b2;
    scanf("%d",&cas);
    while(cas--)
    {
        int i,t=0;
        scanf("%s%s",a,b);
        int len=strlen(a);
        if(len>2)
        {
            for(i=0;i<len;i++)
                t+=(a[i]-'a'+b[i]-'a');
            if(t&1)
                printf("Case #%d: NO\n",T++);
            else
                printf("Case #%d: YES\n",T++);
        }
        else
        {
             a1=a[0]-'a';
             a2=a[1]-'a';
             b1=b[0]-'a';
             b2=b[1]-'a';
             i=(b1-a1+26)%26;
             if(i%2==0&&(a2+i)%26==b2)
                 printf("Case #%d: YES\n",T++);
             else
             {
                 i=(b2-a1+26)%26;
                 if(i%2==1&&(a2+i)%26==b1)
                     printf("Case #%d: YES\n",T++);
                 else printf("Case #%d: NO\n",T++);
             }
        }
    }
    return 0;
}
