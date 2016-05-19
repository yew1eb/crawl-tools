#include<stdio.h>
#include<string.h>
int main()
{
    char str[66];
    int i;
    int n,k;
    scanf("%d",&n);
    for(k=1; k<=n; k++)
    {
        scanf("%s",str);
        int l=strlen(str);
        for(i=0; i<l; i++)
        {
            if(str[i]=='Z')
                str[i]='A';
            else
                str[i]++;
        }
        printf("String #%d\n",k);
        printf("%s\n",str);
        printf("\n");
    }
    return 0;
}
