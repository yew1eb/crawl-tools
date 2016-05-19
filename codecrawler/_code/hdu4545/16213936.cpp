#include <stdio.h>
#include <string.h>
const int N = 1005;

int main()
{
    int cas,t;
    scanf("%d",&t);
    for(cas = 1; cas<=t; cas++)
    {
        getchar();
        char s1[N],s2[N];
        int len1,len2;
        gets(s1);
        gets(s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        int n,i,j;
        int change[30][30] = {0};
        scanf("%d",&n);
        for(i = 0; i<n; i++)
        {
            char a,b;
            getchar();
            scanf("%c %c",&a,&b);
            change[a-'a'][b-'a'] = 1;//æä¸ä¸ä¸ªè½¬æ¢è¡¨
        }
        j = 0;
        int flag = 0;
        for(i = 0; i<len1; i++)
        {
            if(j == len2)
                break;
            if(s1[i] == s2[j])//ç¸ç­ç»§ç»­
            {
                j++;
                continue;
            }
            while(s2[j]!=s1[i])
            {
                if(j==len2)
                {
                    flag = 1;//s2å·²ç»å®äºï¼ä½s1è¿æ²¡å®ï¼è¯æä¸è¡
                    break;
                }
                if(change[s2[j]-'a'][s1[i]-'a'] == 1)
                {
                    j++;
                    break;
                }
                else
                    j++;
            }
        }
        printf("Case #%d: ",cas);
        if(!flag)
            printf("happy\n");
        else
            printf("unhappy\n");
    }
    return 0;
}
