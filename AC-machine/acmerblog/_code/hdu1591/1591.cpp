#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char ch[27],Bch[27],Sch[27];
int temp[27];
int get_Bch(char x)
{
    int i=0;
    for(i=0;i<26;i++)
        if(Bch[i]==x)
            return i;
}
int get_Sch(char x)
{
    int i=0;
    for(i=0;i<26;i++)
        if(Sch[i]==x)
            return i;
}
int main()
{
    int i,len;    
//    freopen("d:\\1.txt","r",stdin);
    gets(ch);
    memset(temp,0,sizeof(temp));
    len=strlen(ch);
    int h;
    for(i=0;i<len;i++)
    {
        Bch[i]=ch[i];
        h=(int)(ch[i]-65);
        temp[h]=1;
    }
    int j;
    for(i=25,j=0;i>=len;i--,j++)
    {
        while(temp[j]==1)
            j++;
        Bch[i]=j+65;
    }
    for(i=0;i<26;i++)
        Sch[i]=Bch[i]+32;
    char ch1[10000];
    while(gets(ch1))
    {
        i=0;
        while(ch1[i]!='\0')
        {
            if(ch1[i]>='A'&&ch1[i]<='Z')
                printf("%c",(get_Bch(ch1[i])+65));
            else if(ch1[i]>='a'&&ch1[i]<='z')
                printf("%c",(get_Sch(ch1[i])+97));
            else
                printf("%c",ch1[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}