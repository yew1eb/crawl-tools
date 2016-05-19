#include <stdio.h>
#include <string.h>
int main()
{
    char s[200];
    char other;
    int a, b, c, d;
    while(gets(s))
    {
        if(strchr( s, '+' )||strlen(s)>15){ puts("NO");continue;}
        if(sscanf(s,"%d.%d.%d.%d%c",&a,&b,&c,&d,&other) ==4)
            if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255)
                puts("NO");
            else
                puts("YES");
        else
        {

            puts("NO");
        }
    }
    return 0;
}
