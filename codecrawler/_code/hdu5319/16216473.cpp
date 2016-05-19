#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[60][60];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++)
            gets(s[i]);
        int ans=0;
        int len=strlen(s[0]);
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<len;k++)  //æ³¨æé¿åº¦ 
            {
                int t=k;
                if((s[i][k]=='R')||(s[i][k]=='G'))
                {
                    ans++;
                    for(int j=i;j<n&&t<len;j++)
                    {

                        if(s[j][t]=='.'||s[j][t]=='B')
                            break;
                        if(s[j][t]=='G')
                            s[j][t]='B';
                        else if(s[j][t]=='R')
                            s[j][t]='.';
                        t++;
                    }
                }
                t=k;
                if((s[i][k]=='B')||(s[i][k]=='G'))
                {
                    ans++;
                    for(int j=i;j<n&&t>=0;j++)
                    {

                        if(s[j][t]=='.'||s[j][t]=='R')
                            break;
                        if(s[j][t]=='G')
                            s[j][t]='R';
                        else if(s[j][t]=='B')
                            s[j][t]='.';
                        t--;
                    }
                }
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}