#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    int i, len;
    char s[100];
    int t;
    scanf("%d\n",&n);
    for(int j=1;j<=n;j++)
    {
       gets(s);
       len =strlen(s);
       t =1;
       if(s[0]>=48&&s[0]<=57) t =0;
       else for(i=0;i<len;i++)
               {
if(! ((s[i]>=48&&s[i]<=57)||(s[i]>=65&&s[i]<=90) || (s[i]>=97&&s[i]<=122)||(s[i]=='_')) ) 
{ t = 0;break;}
               }
       if(t) printf("yes\n");
       else printf("no\n");
    }
    return 0;
}
                   
             
