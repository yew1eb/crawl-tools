#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int al,i,s;
    char a[50];
    while(scanf("%s",a)!=EOF)
    {
        al=strlen(a);
        s=0;
        if(a[0]=='#')break;
        for(i=0;i<al-1;i++)
        {
           if(a[i]=='1')s++;
           printf("%c",a[i]);
        }
        if(a[al-1]=='e')
        {
            if(s%2==0)printf("0\n");
            else printf("1\n");
        }
        else
        {
            if(s%2==0)printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}