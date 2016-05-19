#include <stdio.h>
#include <string.h>

int num[10];
char s[16][81];

int main()
{
    int i,j;

    while(scanf("%s",s[0]) && s[0][0]!='-')
    {
        for(i=0;i<15;i++)//è®¡ç®15æ¬¡æä½çææç»æ
        {
            memset(num,0,sizeof(num));

            for(j=0;j<81 && s[i][j];j++)//è®¡æ°
            {
                num[s[i][j]-'0']++;
            }

            int index=0;
            for(j=0;j<10;j++)//ç»æ
            {
                if(num[j])
                {
                    if(num[j]>9)
                        s[i+1][index++]=num[j]/10+'0';
                    s[i+1][index++]=num[j]%10+'0';

                    s[i+1][index++]=j+'0';
                }
            }
            s[i+1][index]=0;
        }

        if(strcmp(s[0],s[1])==0)
        {
            printf("%s is self-inventorying\n",s[0]);
            continue;
        }

        if(strcmp(s[15],s[14])==0)
        {
            for(i=14;i>=0;i--)
            {
                if(strcmp(s[15],s[i])) break;
            }

            printf("%s is self-inventorying after %d steps\n",s[0],i+1);
            continue;
        }

        int flag=0;
        for(j=0;j<16 && !flag;j++)
        {
            for(i=j+1;i<16 && !flag;i++)
            {
                if(strcmp(s[j],s[i])==0)
                {
                    printf("%s enters an inventory loop of length %d\n",s[0],i-j);
                    flag=1;
                    break;
                }
            }
        }

        if(!flag) printf("%s can not be classified after 15 iterations\n",s[0]);
    }
}
