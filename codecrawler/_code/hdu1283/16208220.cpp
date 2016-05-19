#include <stdio.h>
#include <string.h>

int main()
{
    int m1,m2,len,i;
    char str[300];
    while(~scanf("%d%d %s",&m1,&m2,str))
    {
        len = strlen(str);
        int r1 = 0,r2 = 0,r3 = 0;
        for(i = 0;i<len;i++)
        {
            if(str[i] == 'A')
            {
                r1 = m1;
            }
            else if(str[i] == 'B')
            {
                r2 = m2;
            }
            else if(str[i] == 'C')
            {
                m1 = r3;
            }
            else if(str[i] == 'D')
            {
                m2 = r3;
            }
            else if(str[i] == 'E')
            {
                r3 = r1+r2;
            }
            else if(str[i] == 'F')
            {
                r3 = r1-r2;
            }
        }
        printf("%d,%d\n",m1,m2);
    }

    return 0;
}
