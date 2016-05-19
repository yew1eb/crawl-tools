#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char ord[100]={"_small_"};
int main()
{
    char fa[50],mo[70];
    while(scanf("%s%s",fa,mo)!=EOF)
    {
        char na[40];
        int pos1,pos2;
        for(int i=0;i<strlen(fa);i++)
        if(fa[i]=='_')
        {
            pos1=i+1;
            break;
        }
        for(int i=0;i<strlen(mo);i++)
        if(mo[i]=='_')
        {
            pos2=i+1;
            break;
        }
        int cnt=0;
        for(int i=pos1;i<strlen(fa);i++)
        na[cnt++]=fa[i];
        for(int i=0;i<strlen(ord);i++)
        na[cnt++]=ord[i];
        for(int i=pos2;i<strlen(mo);i++)
        na[cnt++]=mo[i];
        na[cnt]='\0';
        cout<<na<<endl;
    }
   return 0;
}
