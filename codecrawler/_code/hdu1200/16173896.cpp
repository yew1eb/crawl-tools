#include <stdio.h>
#include <string.h>

int main()
{
    char s[30][200],str[300];
    int n,i,j,k,len;
    while(~scanf("%d",&n),n)
    {
        scanf("%s",str);
        len = strlen(str);
        memset(s,'\0',sizeof(s));
        k = 0;
        for(i = 0;i<len/n && k<len;i++)
        {
            for(j = 0;j<n;j++)
            {
                if(i%2)
                s[i][n-j-1] = str[k++];
                else
                s[i][j] = str[k++];
            }
        }
        for(i = 0;i<n;i++)
        {
            for(j = 0;j<len/n;j++)
            {
                printf("%c",s[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}
