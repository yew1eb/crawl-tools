#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
    int T,i,j,flag,n;
    char Map[60][60];
    scanf("%d",&T);
    while(T--)
    {
        flag = 0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            //for(j=1; j<=n; j++)
            scanf("%s",Map[i]);
        for(i=1; i<=n; i++)
            for(j=0; j<strlen(Map[1]); j++)
            {
                if((Map[i][j]=='R'||Map[i][j]=='G')&&!(Map[i-1][j-1]=='R'||Map[i-1][j-1]=='G'))
                    flag++;
                if((Map[i][j]=='B'||Map[i][j]=='G')&&!(Map[i-1][j+1]=='B'||Map[i-1][j+1]=='G'))
                    flag++;
            }
        printf("%d\n",flag);
    }
    return 0;
}
