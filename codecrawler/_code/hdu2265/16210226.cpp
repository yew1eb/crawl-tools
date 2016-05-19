#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char s[1000];
    int len,i,j,a[1000];
    while((gets(s))&&(s[0]!='\0'))
    {
        memset(a,0,sizeof(a));
        len=strlen(s);
        i=0;
        j=1;
        while(s[i]!='\0')
        {
            if (s[i]==' ')
            {
                i++;
                continue;
            }
            if((j%3==0)&&(a[i]==0))
            {
                cout<<s[i];
                a[i]=1;
            }
            i++;
            j++;
        }
        i=0;
        j=1;
        while(s[i]!='\0')
        {
            if (s[i]==' ')
            {
                i++;
                continue;
            }
            if((j%2==0)&&(a[i]==0))
            {
                cout<<s[i];
                a[i]=1;
            }
            i++;
            j++;
        }
        i=0; j=1;
        while(s[i]!='\0')
        {
            if (s[i]==' ')
            {
                i++;
                continue;
            }
            if(a[i]==0)
            {
                cout<<s[i];
                a[i]=1;
            }
            i++;
            j++;
        }
        cout<<endl;
    }
    return 0;
}