#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char dp[65][65][65][85];

void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if(strlen(a) > strlen(b))
        l = strlen(a)+2;
    else
        l = strlen(b)+2;
    c = (char*)malloc(l*sizeof(char));
    i = strlen(a)-1;
    j = strlen(b)-1;
    k = 0;
    up = 0;
    while(j>=0 || i>=0)
    {
        if(i<0) x = '0';
        else
            x = a[i];
        if(j<0) y = '0';
        else
            y = b[j];
        z = x-'0'+y-'0';
        if(up)
            z++;
        if(z>9)
        {
            up = 1;
            z%=10;
        }
        else
            up = 0;
        c[k++] = z+'0';
        i--;
        j--;
    }
    if(up)
        c[k++] = '1';
    i = 0;
    c[k] = '\0';
    for(k-=1; k>=0; k--)
        back[i++] = c[k];
    back[i] = '\0';
}

int main()
{
    int n,i,j,k;
    for(i = 0; i<=60; i++)
        for(j = 0; j<=60; j++)
            for(k = 0; k<=60; k++)
                strcpy(dp[i][j][k],"0");
    strcpy(dp[1][0][0],"1");
    strcpy(dp[1][1][0],"1");
    strcpy(dp[1][1][1],"1");
    for(i = 2; i<=60; i++)
    {
        for(j = 0; j<=i; j++)
        {
            for(k = 0; k<=j; k++)
            {
                if(i-1>=j)
                    add(dp[i-1][j][k],dp[i][j][k],dp[i][j][k]);
                if(j-1>=k)
                    add(dp[i][j-1][k],dp[i][j][k],dp[i][j][k]);
                if(j>=k-1)
                    add(dp[i][j][k],dp[i][j][k-1],dp[i][j][k]);
            }
        }
    }
    while(~scanf("%d",&n))
    {
        printf("%s\n\n",dp[n][n][n]);
    }

    return 0;
}
