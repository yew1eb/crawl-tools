#include<stdio.h>
#include<string.h>
int main()
{
    int n, p, j, k, len;
    int a,e,i,o,u;
    char s[120];
    scanf("%d\n",&n);
    int first =1;
    for(j=1;j<=n;j++)
    {
        a =e =i =o =u = 0;
        gets(s);
        len =strlen(s);
        for(k=0;k<len;k++)
        {
            if(s[k]=='a'||s[k]=='A') a++;
            if(s[k]=='e'||s[k]=='E') e++;
            if(s[k]=='i'||s[k]=='I') i++;
            if(s[k]=='o'||s[k]=='O') o++;
            if(s[k]=='u'||s[k]=='U') u++;
        }
        if(first) first=0;
        else printf("\n");
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
    } 
    return 0;
}
                   
             
