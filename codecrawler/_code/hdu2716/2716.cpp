#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char cha[26];
char str[80];
int main()
{
    while(cin>>cha)
    {
        getchar();
        gets(str);
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                str[i]=cha[str[i]-'a'];
            }
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]=cha[str[i]-'A']-'a'+'A';
            }
        }
        puts(str);
    }
    return 0;
}