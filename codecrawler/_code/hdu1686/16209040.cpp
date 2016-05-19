#include <stdio.h>
#include <string.h>

int next[10005];
char str1[1000005],str2[10005];
int cnt;

void get_next(int len2)//çænextæ°ç»
{
    int i = 0,j = -1;
    next[0] = -1;
    while (i<len2)
    {
        if(j == -1 || str2[i] == str2[j])
        {
            i++;
            j++;
            if (str2[i]!=str2[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}

int kmp(int len1,int len2)//kmpç®æ³
{
    int i=0,j=0;
    get_next(len2);
    while(i<len1)
    {
        if(j==-1||str1[i]==str2[j])
        {
            ++i;
            ++j;
        }
        else
            j=next[j];
        if(j == len2)
        {
            cnt++;
            j = next[j];
        }
    }
}

int main()
{
    int n;
    int len1,len2;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str2);
        gets(str1);
        len1 = strlen(str1);
        len2 = strlen(str2);
        cnt = 0;
        kmp(len1,len2);
        printf("%d\n",cnt);
    }
    return 0;
}

