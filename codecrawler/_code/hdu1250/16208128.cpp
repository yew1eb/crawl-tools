#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <malloc.h>
using namespace std;
void add(char* a,char* b,char* c)
{
    int i,j,k,max,min,n,temp;
    char *s,*pmax,*pmin;
    max=strlen(a);
    min=strlen(b);
    if (max<min)
    {
        temp=max;
        max=min;
        min=temp;
        pmax=b;
        pmin=a;
    }
    else
    {
        pmax=a;
        pmin=b;
    }
    s=(char*)malloc(sizeof(char)*(max+1));
    s[0]='0';
    for (i=min-1,j=max-1,k=max; i>=0; i--,j--,k--)
        s[k]=pmin[i]-'0'+pmax[j];
    for (; j>=0; j--,k--)
        s[k]=pmax[j];
    for (i=max; i>=0; i--)
        if (s[i]>'9')
        {
            s[i]-=10;
            s[i-1]++;
        }
    if (s[0]=='0')
    {
        for (i=0; i<=max; i++)
            c[i-1]=s[i];
        c[i-1]='\0';
    }
    else
    {
        for (i=0; i<=max; i++)
            c[i]=s[i];
        c[i]='\0';
    }
    free(s);
}
char a[8001][2505];
int main(void)
{
    int n,i;
    for(i=1; i<=4; i++)
        strcpy(a[i],"1");
    for(i=5; i<=8000; i++)
    {
        char c[2505],b[2505];
        add(a[i-1],a[i-2],c);
        add(a[i-3],a[i-4],b);
        add(b,c,a[i]);
    }
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
