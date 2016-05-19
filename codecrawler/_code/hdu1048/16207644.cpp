#include <stdio.h>
#include <string.h>

int main()
{
    char alphabetical[26]={0}, message1[300]={0}, message2[300]={0};
    char A[20]={0}, B[20]={0};
    int i, n;
    for (i=0; i<26; i++)
        alphabetical[i] = 'A'+i;
    while (gets(A))
    {
        memset(message1, 0, sizeof(message1));
        memset(message2, 0, sizeof(message2));
        if (!strcmp(A, "START"))
        {
            gets(message1);
            n = strlen(message1);
            for (i=0; i<n; i++)
            {
                if (message1[i]>='A' && message1[i]<='Z')
                    message2[i] = alphabetical[(message1[i]-'A'+21)%26];
                else
                    message2[i] = message1[i];
            }
            puts(message2);
            gets(B);
            memset(A, 0, sizeof(A));
        }
        if (!strcmp(A, "ENDOFINPUT"))
            break;
    }
    return 0;
}