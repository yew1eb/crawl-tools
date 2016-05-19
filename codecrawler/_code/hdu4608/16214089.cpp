#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[100005],c[100005];

void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    if(strlen(a) > strlen(b))
        l = strlen(a)+2;
    else
        l = strlen(b)+2;
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
    int t,len,i,sum,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int flag = 1;
        while(1)
        {
            len = strlen(str);
            sum = 0;
            for(i = 0; i<len; i++)
            {
                sum+=str[i]-'0';
            }
            if(sum%10 || flag)
                add(str,"1",str);
            else
                break;
            flag = 0;
        }
        printf("%s\n",str);
    }

    return 0;
}
