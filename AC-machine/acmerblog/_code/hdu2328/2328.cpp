#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

char s[4002][222];
int n,wlen,next[222];
char word[222];
int be;

void getnext(char *p)
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<wlen)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;    k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}

bool kmp(char *text,char *word)
{
    int i=0,j=0,k=0,tlen=strlen(text);
    while(i<tlen)
    {
        if(j==-1||text[i]==word[j])
        {
            i++;    j++;
        }
        else
            j=next[j];
        if(j==wlen)
            return true;
    }
    return false;
}

int main()
{
    int i,j,k,T,be;
    while(scanf("%d",&n)&&n)
    {
        scanf("%s",s[0]);
        int ll=strlen(s[0]);
        char ss[222];
        strcpy(ss,s[0]);
        int ppp=0;
        for(i=1;i<n;i++)
        {
            scanf("%s",s[i]);
            int k=strlen(s[i]);
            if(k<ll)
                strcpy(ss,s[i]),ll=k,ppp=i;
        }
        strcpy(s[ppp],s[0]);
        strcpy(s[0],ss);
        int be=0,len=0;
        int h=0;
        char pp[222]="";
        for(i=1;i<=ll;i++)
        {
            wlen=i;
            int g=0,kkk=0;
            for(j=0;j+i<=ll;j++)
            {
                strncpy(word,s[0]+j,i);
                word[wlen]='\0';
                getnext(word);
                int f=0;
                for(k=1;k<n;k++)
                    if(!kmp(s[k],word))//匹配不成功
                    {
                        f=1;break;
                    }
                if(f==0)//当从j开始的i个匹配成功
                {
                    be=j;   len=i;
                    if(kkk==0||strcmp(pp,word)>0)
                    {
                        kkk=1;strcpy(pp,word);
                    }
                    g=1;
                }
            }
            if(g==0)//当有i个字符的时候都没有匹配
                break;
        }
        if(len==0)
            printf("IDENTITY LOST\n");
        else
        {
            printf("%s\n",pp);
        }
    }
    return 0;
}