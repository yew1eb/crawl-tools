#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mult(char a[],char b[],char s[])
{
    int i,j,k = 0,alen,blen,sum = 0,res[65][65]= {0},flag = 0;
    char result[65];
    alen = strlen(a);
    blen = strlen(b);
    for(i = 0; i<alen; i++)
    {
        for(j = 0; j<blen; j++)
            res[i][j] = (a[i]-'0')*(b[j]-'0');
    }
    for(i = alen-1; i>=0; i--)
    {
        for(j = blen-1; j>=0; j--)
        {
            sum = sum+res[i+blen-j-1][j];
        }
        result[k] = sum%10;
        k++;
        sum = sum/10;
    }
    for(i = blen-2; i>=0; i--)
    {
        for(j = 0; j<=i; j++)
        {
            sum = sum+res[i-j][j];
        }
        result[k] = sum%10;
        k++;
        sum = sum/10;
    }
    if(sum)
    {
        result[k] = sum;
        k++;
    }
    for(i = 0; i<k; i++)
        result[i]+='0';
    for(i = k-1; i>=0; i--)
        s[i] = result[k-1-i];
    s[k] = '\0';
    while(1)
    {
        if(strlen(s)!=strlen(a) && s[0] == '0')
            strcpy(s,s+1);
        else
            break;
    }
}

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
    int k;
    char a[100],b[100],t[100];
    scanf("%d%*c",&k);
    while(k--)
    {
        scanf("%s",a);
        add(a,"1",b);
        strcpy(t,a);
        mult(t,t,a);
        mult(a,t,a);
        strcpy(t,b);
        mult(t,t,b);
        mult(b,t,b);
        printf("%s %s\n",a,b);
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
    }
    return 0;
}
