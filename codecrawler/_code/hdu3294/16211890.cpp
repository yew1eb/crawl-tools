#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 200010
using namespace std;

char ma[MAX<<1];
int mp[MAX<<1];

int manacher(char s[],int len)
{
    int L=0;
    ma[L++]='$';
    ma[L++]='#';
    for(int i=0;i<len;i++)
    {
        ma[L++]=s[i];
        ma[L++]='#';
    }
    ma[L]='\0';
    int mx=0,id=0;
    for(int i=0;i<L;i++)
    {
        mp[i]=mx>i?min(mp[2*id-i],mx-i):1;
        while(ma[i+mp[i]]==ma[i-mp[i]]) mp[i]++;
        if(i+mp[i]>mx)
        {
            mx=i+mp[i];
            id=i;
        }
    }
    return L;
}


int main()
{
    char s[MAX],ch[2];
    int len,nlen,i,pre,maxp,maxn;
    int bg,ed;
    while(~scanf("%s%s",ch,s))
    {
        maxp=maxn=-1;
        len=strlen(s);
        pre=ch[0]-'a';
        for(i=0;i<len;i++)
        {
            s[i]=s[i]-pre;
            if(s[i]<'a')
                s[i]+=26;
        }
        nlen=manacher(s,len);
        for(i=1;i<nlen;i++)
        {
            if(maxn<mp[i])
            {
                maxp=i;
                maxn=mp[i];
            }
        }
        if(maxn-1<2)
            printf("No solution!\n");
        else
        {
            bg=(maxp-maxn)/2;//èµ·å§ä½ç½®
            ed=(maxp+maxn-4)/2;//ç»æä½ç½®
            printf("%d %d\n",bg,ed);
            for(i=bg;i<=ed;i++)
                printf("%c",s[i]);
            printf("\n");
        }


    }
    return 0;
}
