#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct node
{
    char s[10];
    char st[10];
    bool operator<(const node&b)const
    {
       return strcmp(s,b.s)<0;
    }
}rc[103];
int main()
{
    char s[10];
    int i,n=0;
    while(scanf("%s",s),strcmp(s,"XXXXXX")!=0)
    {
        strcpy(rc[n].s,s);
        sort(s,s+strlen(s));
        //puts(s);
        strcpy(rc[n].st,s);
        n++;
    }
    sort(rc,rc+n);
    int f;
    while(scanf("%s",s),strcmp(s,"XXXXXX")!=0)
    {
        sort(s,s+strlen(s));
        f=0;
        for(i=0;i<n;i++)
          if(strcmp(rc[i].st,s)==0)
            f=1,printf("%s\n",rc[i].s);
        if(!f)
        printf("NOT A VALID WORD\n");
        printf("******\n");
    }
    return 0;
}